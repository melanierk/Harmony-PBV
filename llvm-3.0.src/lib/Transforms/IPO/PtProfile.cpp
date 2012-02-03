//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This pass adds instrumentation code and is to be run at link-time optimization.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "ptprofile"
#include "llvm/ADT/Statistic.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/Constants.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Instructions.h"
#include "llvm/LLVMContext.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/InstVisitor.h"
#include "llvm/Support/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Instrumentation.h"
#include "llvm/Transforms/PtProfile/PtProfile.h"
#include <vector>

using namespace llvm;

namespace llvm {
  class PtProfile : public ModulePass {
    bool runOnModule(Module &M);
  private:
    void insertModuleInit(Module &M);

  public:
    static char ID;
    PtProfile() : ModulePass(ID) {
      initializePtProfilePass(*PassRegistry::getPassRegistry());
    }
    virtual const char *getPassName() const { return "Pthread Block Profiler"; }
  };

  ModulePass *createPtProfilePass() { return new PtProfile(); }
}


char PtProfile::ID = 0;
INITIALIZE_PASS(PtProfile, "insert-ptprofile", "Instrument pthread block profiling", false, false)

static Module *pM;

// some types
static IntegerType *int32Ty;
static FunctionType *funcVoidTy;
static PointerType *ptrFuncVoidTy;
static StructType *globalCDtorElemTy;
static FunctionType *startRoutineTy;
static PointerType *ptrStartRoutineTy;
static PointerType *voidPtrTy;
static StructType *shimWrapperTy;
static PointerType *ptrShimWrapperTy;

void llvm::PtProfile::insertModuleInit(Module &M) {
  std::vector<Constant *> ctors;
 
  // If llvm.global_ctors already exists, copy contents into ctors and destroy.
  // Assume priorities will not overflow, and minimum priority is zero.
  if (GlobalVariable *globalCtors = M.getNamedGlobal("llvm.global_ctors")) {
    if (ConstantArray *initList = 
        dyn_cast<ConstantArray>(globalCtors->getInitializer())) {
      for (unsigned i = 0, e = initList->getType()->getNumElements();
           i != e; ++i) {
        Constant *entry = cast<Constant>(initList->getOperand(i));
        ConstantInt *priority = cast<ConstantInt>(entry->getOperand(0));
        DEBUG(errs() << "Constructor " << *entry << " priority is " << *priority << "\n");

        APInt p = priority->getValue();
        assert(!priority->isMaxValue(false));
        p++;

        ctors.push_back(
            ConstantStruct::get(globalCDtorElemTy,
              ConstantInt::get(M.getContext(), p),
              cast<Constant>(entry->getOperand(1)),
              NULL));
      }
    }
    globalCtors->eraseFromParent();
  }

  // Get the module initializer function and add it as the lowest priority
  Constant *moduleInitFn = M.getOrInsertFunction("PROF_IN_init_module", funcVoidTy);
  ctors.push_back(ConstantStruct::get(
        globalCDtorElemTy,
        ConstantInt::get(int32Ty, 0),
        ConstantExpr::getBitCast(moduleInitFn, ptrFuncVoidTy),
        NULL));

  // Reconstruct globalCtors using the ctors vector
  GlobalVariable *globalCtors = new GlobalVariable(
      M, ArrayType::get(globalCDtorElemTy, ctors.size()), /*isConstant*/ false,
      GlobalValue::AppendingLinkage, /*Initializer*/ NULL,
      "llvm.global_ctors"); 
  globalCtors->setInitializer(ConstantArray::get(
    cast<ArrayType>(globalCtors->getType()->getElementType()), ctors));
  DEBUG(errs() << "globalCtors is " << *globalCtors << "\n");

}

static void initializeTyConstants(Module &M) {
  int32Ty = Type::getInt32Ty(M.getContext());
  funcVoidTy = FunctionType::get(Type::getVoidTy(M.getContext()), false);
  ptrFuncVoidTy = ((Type *)funcVoidTy)->getPointerTo();
  globalCDtorElemTy = StructType::get((Type *) int32Ty, (Type *) ptrFuncVoidTy, NULL);
  voidPtrTy = Type::getInt8Ty(M.getContext())->getPointerTo();
  std::vector<Type*> startRoutineArgs;
  startRoutineArgs.push_back(voidPtrTy);
  startRoutineTy = FunctionType::get(voidPtrTy, startRoutineArgs, /*isVarArg*/ false);
  ptrStartRoutineTy = ((Type *)startRoutineTy)->getPointerTo();
  Type *wrapper_tmp[] = { ptrStartRoutineTy, voidPtrTy };
  shimWrapperTy = StructType::create(ArrayRef<Type*>(wrapper_tmp, 2), 
    "PROF_shim_wrapper_t");
  ptrShimWrapperTy = shimWrapperTy->getPointerTo();
}

namespace {
  class PthreadCreateVisitor : public InstVisitor<PthreadCreateVisitor> {
  private:
    int ci;
    IRBuilder<> builder;
    Constant *threadInitFn;

  public:
    PthreadCreateVisitor() : InstVisitor(), ci(0), builder(pM->getContext()),
      threadInitFn(pM->getOrInsertFunction("PROF_IN_init_thread", funcVoidTy)) { }
    void visitCallInst(CallInst &call) {
      Function *f = call.getCalledFunction();
      if (f == 0) {
        errs() << "PthreadCreateVisitor::visitCallInst saw indirect call: "
               << call << " -- make sure this is not pthread_create.\n";
      }
      if (f && f->getName() == "pthread_create") {
        DEBUG(errs() << "PthreadCreateVisitor: " << call << "Was a call to pthread_create\n");
        ci++;

        builder.SetInsertPoint(&call);
  
        Instruction *wrapper = CallInst::CreateMalloc(/*InsertBefore*/ &call,
            /*IntPtrTy*/ int32Ty,
            /*AllocTy*/ shimWrapperTy,
            /*AllocSize*/ builder.getInt32(1));
        Value *wrapper_start_routine = builder.CreateConstGEP2_32(
            wrapper, 0, 0);
        Value *wrapper_arg = builder.CreateConstGEP2_32(
            wrapper, 0, 1);
        
        DEBUG(errs() << "wrapper_t = " << *shimWrapperTy);
        DEBUG(errs() << "wrapper = " << *wrapper << "\n");
        DEBUG(errs() << "wrapper_start_routine = " << *wrapper_start_routine
                     << " and " << "wrapper_arg = " << *wrapper_arg << "\n");
        Value *start_routine = call.getArgOperand(2);
        Value *arg           = call.getArgOperand(3);
        builder.CreateStore(start_routine, wrapper_start_routine);
        builder.CreateStore(arg, wrapper_arg);
        
        /*
        Function *shim = shimStartRoutine(start_routine->getName(),
            capture_start_routine,
            call.getArgOperand(3));
        */
        
        // call pthread_create with shim instead of start_routine
        Constant *shim = pM->getOrInsertFunction("PROF_shim_start_routine",
            startRoutineTy);
        Value *newArg = builder.CreateBitCast(wrapper, voidPtrTy);
        Value *newArgs[] = {call.getArgOperand(0), 
                            call.getArgOperand(1),
                            shim,
                            newArg};
        CallInst *newCall = CallInst::Create(call.getCalledValue(),
                                             ArrayRef<Value*>(newArgs, 4),
                                             Twine("PROF_IN_patched_call"),
                                             &call);
        DEBUG(errs() << "old call was " << call << "\n");
        DEBUG(errs() << "newCall is   " << *newCall << "\n");
        call.eraseFromParent();
        DEBUG(errs() << "erased from parent" << "\n");
        // TODO: make the shim
      }
    }
  };
}

bool llvm::PtProfile::runOnModule(Module &M) {
  // Initialize some globals. Should really factor into class stuff.
  pM = &M;
  initializeTyConstants(M);

  // Do instrumentation
  insertModuleInit(M);

  // First pass: intercept calls to pthread_create.
  PthreadCreateVisitor PtCV;
  PtCV.visit(M);
  
  DEBUG(errs() << "Module about to finish" << "\n");
  return true;
}


