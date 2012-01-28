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
#include "llvm/Transforms/Instrumentation.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/InstVisitor.h"
#include "llvm/Constants.h"
#include "llvm/Support/Debug.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Instructions.h"
#include "llvm/LLVMContext.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Transforms/PtProfile/PtProfile.h"
#include <vector>

using namespace llvm;

namespace llvm {
  class PtProfile : public ModulePass {
    bool runOnModule(Module &M);
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

// Interface (PtProfile.h)

// some types
static IntegerType *int32Ty;
static FunctionType *funcVoidTy;
static PointerType *ptrFuncVoidTy;
static StructType *globalCDtorElemTy;
static FunctionType *startRoutineTy;
static PointerType *ptrStartRoutineTy;
static PointerType *voidPtrTy;


static void insertModuleInit(Module &M) {
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

static Module *pM;
namespace {
  struct PthreadCreateVisitor : public InstVisitor<PthreadCreateVisitor> {
    int ci;
    PthreadCreateVisitor() : InstVisitor(), ci(0) { }
    void visitCallInst(CallInst &call) {
      Function *f = cast<Function>(call.getCalledValue());
      if (f->getName() == "pthread_create") {
        DEBUG(errs() << "PthreadCreateVisitor: " << *f << "Was a pthread_create\n");
        ci++;
        Function *start_routine = cast<Function>(call.getArgOperand(2));
        std::string capture_name("capture");
        capture_name += "_";
        capture_name += start_routine->getName();
//        GlobalVariable *capture_start_routine = new GlobalVariable(
//            ptrStartRoutineTy, false, Function::InternalLinkage,
//            /*Initializer*/0, capture_name);

        GlobalVariable *capture_start_routine = new GlobalVariable(
            *pM, ptrStartRoutineTy, false, Function::InternalLinkage,
            /*Initializer*/0, capture_name);

        DEBUG(errs() << "the global variable is " << *capture_start_routine << "\n");
        DEBUG(errs() << "parent of the global variable is " << *capture_start_routine->getParent() << "\n");
        StoreInst(start_routine, capture_start_routine, /*isVolatile*/ false,
                  /*insertBefore*/ &call);
        // TODO: make the shim
      }
    }
  };
}

bool llvm::PtProfile::runOnModule(Module &M) {
  pM = &M;
  initializeTyConstants(M);
  insertModuleInit(M);

  // First pass: intercept calls to pthread_create.
  PthreadCreateVisitor PtCV;
  errs() << "prior to visit\n";
  PtCV.visit(M);
  errs() << "after visit\n";
  
  return true;
}


