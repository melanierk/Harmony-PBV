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
}

namespace {
  class PthreadCreateVisitor : public InstVisitor<PthreadCreateVisitor> {
  private:
    int ci;
    IRBuilder<> builder;
    Constant *threadInitFn;

    GlobalVariable *capturePthreadCreateStartRoutine(Function *start_routine, Instruction *insertBefore) {
      std::string capture_name("PROF_IN_capture");
      capture_name += "_";
      capture_name += start_routine->getName();

      GlobalVariable *capture_start_routine = new GlobalVariable(
          *pM, ptrStartRoutineTy, false, Function::CommonLinkage,
          ConstantPointerNull::get(ptrStartRoutineTy), capture_name);

      DEBUG(errs() << "the global variable is " << *capture_start_routine << "\n");
      StoreInst *si = new StoreInst(start_routine, capture_start_routine, /*insertBefore*/ insertBefore);
      
      return capture_start_routine;
    }

    Function *shimStartRoutine(StringRef name, GlobalVariable *capture_start_routine, Value *arg) {
      // make the function prototype
      std::string shimStartRoutineName("PROF_IN_shim_");
      shimStartRoutineName += name;
      Function *F = Function::Create(startRoutineTy,
          Function::ExternalLinkage, shimStartRoutineName, pM);
      if (F->getName() != shimStartRoutineName) { // conflicted
        DEBUG(errs() << "in shimStartRoutine, function creation conflicted: "
                     << "wanted name to be " << shimStartRoutineName << " but got "
                     << F->getName() << " instead.");
        return 0;
      }
      // make an entry basic block
      BasicBlock *BB = BasicBlock::Create(pM->getContext(), "entry", F);
      builder.SetInsertPoint(BB);
      
      // insert a call to PROF_init_thread
      builder.CreateCall(threadInitFn);
      // insert a call (return) to start_routine (for real)
      ArrayRef<Value*> startRoutineArg(arg);
      // get 

      LoadInst *start_routine = builder.CreateLoad(capture_start_routine);
      CallInst *ci = builder.CreateCall(start_routine, arg);
      builder.CreateRet(ci);
      return F;
    }

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
        Function *start_routine = cast<Function>(call.getArgOperand(2));
        GlobalVariable *capture_start_routine = 
          capturePthreadCreateStartRoutine(start_routine, cast<Instruction>(&call));
        Function *shim = shimStartRoutine(start_routine->getName(),
            capture_start_routine,
            call.getArgOperand(3));
        DEBUG(errs() << "call.getArgOperand(2) " << *call.getArgOperand(2) << "\n");
        DEBUG(errs() << "shim is " << *shim << "\n");
        
        // call pthread_create with shim instead of start_routine
        Value *newArgs[] = {call.getArgOperand(0), 
                            call.getArgOperand(1),
                            shim,
                            call.getArgOperand(3)};
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


