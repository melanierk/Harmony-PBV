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
#include <algorithm>
#include <cstdio>

using namespace llvm;

namespace llvm {
  class PtProfile : public ModulePass {
    bool runOnModule(Module &M);
  private:
    Constant *sampleCall;
    void insertModuleInit(Module &M);
    void insertSampleCall(int n, BasicBlock *B);
    void insertBBMap(const std::vector<BasicBlock*> &bbs);

  public:
    static char ID;
    PtProfile() : ModulePass(ID), sampleCall(0) {
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
static IntegerType *int8Ty;
static FunctionType *funcVoidTy;
static PointerType *ptrFuncVoidTy;
static StructType *globalCDtorElemTy;
static FunctionType *startRoutineTy;
static PointerType *ptrStartRoutineTy;
static PointerType *voidPtrTy;
static StructType *shimWrapperTy;
static PointerType *ptrShimWrapperTy;
static Type* voidTy;
static FunctionType *sampleCallTy;

static void initializeTyConstants(Module &M) {
  LLVMContext &ctx = M.getContext();
  int32Ty = Type::getInt32Ty(ctx);
  int8Ty = Type::getInt8Ty(ctx);
  funcVoidTy = FunctionType::get(Type::getVoidTy(ctx), false);
  ptrFuncVoidTy = static_cast<Type *>(funcVoidTy)->getPointerTo();
  globalCDtorElemTy = StructType::get((Type *) int32Ty, (Type *) ptrFuncVoidTy, NULL);
  voidPtrTy = Type::getInt8Ty(ctx)->getPointerTo();

  startRoutineTy = FunctionType::get(voidPtrTy, 
      ArrayRef<Type*>(voidPtrTy), /*isVarArg*/ false);
  ptrStartRoutineTy = static_cast<Type *>(startRoutineTy)->getPointerTo();

  Type *wrapper_tmp[] = { ptrStartRoutineTy, voidPtrTy };

  shimWrapperTy = StructType::create(ArrayRef<Type*>(wrapper_tmp, 2), 
    "PROF_shim_wrapper_t");
  ptrShimWrapperTy = shimWrapperTy->getPointerTo();
  voidTy = Type::getVoidTy(ctx);

  sampleCallTy = FunctionType::get(voidTy, 
      ArrayRef<Type*>(int32Ty), false);
}

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
  Constant *moduleInitFn = M.getOrInsertFunction("PROF_init_module", funcVoidTy);
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

void llvm::PtProfile::insertSampleCall(int bb_id, BasicBlock *B) {
  BasicBlock::iterator insertPoint = B->getFirstInsertionPt();
  ConstantInt *constBBId = ConstantInt::get(int32Ty, bb_id);
  CallInst::Create(sampleCall, ArrayRef<Value*>(constBBId), "", insertPoint);
}

void llvm::PtProfile::insertBBMap(const std::vector<BasicBlock*> &bbs) {
  // inserting this equivalent C code:
  // char *PROF_bbmap[] = { "alpha", "beta" };
  //
  // which is this in LLVM:
  // @.str = private unnamed_addr constant [6 x i8] c"alpha\00", align 1
  // @.str1 = private unnamed_addr constant [5 x i8] c"beta\00", align 1
  // @PROF_bbmap = global [2 x i8*] [i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8]* @.str1, i32 0, i32 0)], align 16
  //
  // which is the following in C++:
  std::vector<Constant*> gepIndices;
  ConstantInt *zero = ConstantInt::get(int32Ty, 0);
  gepIndices.push_back(zero);
  gepIndices.push_back(zero);

  std::vector<Constant*> bbNames;

  char sprintf_buf[64];
  for (int i = 0, sz = bbs.size(); i < sz; ++i) {
    snprintf(sprintf_buf, 63, "%d", i);
    Twine tName = bbs[i]->getParent()->getName() + ":" + bbs[i]->getName();
    std::string srName(tName.str());
    ArrayType *ty = ArrayType::get(int8Ty, srName.size() + 1);
    GlobalVariable *v = new GlobalVariable(/*Module=*/*pM,
      /*Type=*/ty,
      /*isConstant=*/true,
      /*Linkage*/GlobalValue::PrivateLinkage,
      /*Initializer=*/ConstantArray::get(pM->getContext(), srName, true), // c string shorthand
      /*Name=*/std::string("PROF_bb_id_") + sprintf_buf);
    v->setAlignment(1);
    Constant *const_ptr_v = ConstantExpr::getGetElementPtr(v, gepIndices);
    bbNames.push_back(const_ptr_v);
  }
  // Null-terminate this list
  PointerType *ptrInt8Ty = PointerType::get(int8Ty, 0);
  bbNames.push_back(llvm::ConstantPointerNull::get(ptrInt8Ty));
  ArrayType *BBMapTy = ArrayType::get(ptrInt8Ty, bbNames.size());
  Constant *constBBMap = ConstantArray::get(BBMapTy, bbNames);
  GlobalVariable *gvBBMap = new GlobalVariable(*pM,
      BBMapTy,
      true,
      GlobalValue::ExternalLinkage,
      constBBMap,
      "PROF_bbmap");

  // Also add a counter
  GlobalVariable *gvNbbs = new GlobalVariable(*pM,
      int32Ty,
      true,
      GlobalValue::ExternalLinkage,
      ConstantInt::get(int32Ty, bbNames.size()),
      "PROF_nbbs");
}

namespace {
  class PthreadCreateVisitor : public InstVisitor<PthreadCreateVisitor> {
  private:
    int ci;
    IRBuilder<> builder;
    Constant *threadInitFn;

  public:
    PthreadCreateVisitor() : InstVisitor(), ci(0), builder(pM->getContext()),
      threadInitFn(pM->getOrInsertFunction("PROF_init_thread", funcVoidTy)) { }
    void visitCallInst(CallInst &call) {
      Function *f = call.getCalledFunction();
      if (f == 0) {
        DEBUG(errs() << "PthreadCreateVisitor::visitCallInst saw indirect call: "
                     << call << " -- make sure this is not pthread_create.\n");
        return;
      }
      if (f->getName() == "pthread_create") {
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
                                             Twine("PROF_patched_call"),
                                             &call);
        DEBUG(errs() << "old call was " << call << "\n");
        DEBUG(errs() << "newCall is   " << *newCall << "\n");
        call.replaceAllUsesWith(newCall);
        call.eraseFromParent();
        DEBUG(errs() << "erased from parent" << "\n");
        // TODO: make the shim
      }
    }
  };

  class BlockingCallVisitor : public InstVisitor<BlockingCallVisitor> {
  private:
    std::vector<StringRef> blockingNames;
    Constant *preblockFn;
    Constant *postblockFn;
    inline bool isBlocking(Function *f) {
      if (f == 0) { return false; }
      std::vector<StringRef>::iterator r = 
        std::find(blockingNames.begin(), blockingNames.end(), f->getName());
      return r != blockingNames.end();
    }

  public:
    BlockingCallVisitor() : InstVisitor() {
      preblockFn = pM->getOrInsertFunction("PROF_postblock", funcVoidTy);
      postblockFn = pM->getOrInsertFunction("PROF_postblock", funcVoidTy);
      blockingNames.push_back("pthread_mutex_lock");
      blockingNames.push_back("pthread_rwlock_wrlock");
      blockingNames.push_back("pthread_rwlock_rdlock"); 
      blockingNames.push_back("pthread_cond_timedwait");
      blockingNames.push_back("pthread_cond_wait");
      blockingNames.push_back("pthread_join");
      blockingNames.push_back("pthread_barrier_wait");
    }
    void visitCallInst(CallInst &call) {
      Function *f = call.getCalledFunction();
      if (f == 0) {
        DEBUG(errs() << "BlockingCallVisitor::visitCallInst saw indirect call: "
                     << call << " -- make sure this is not a blocking call.\n");
        return;
      }
      if (isBlocking(f)) {
        DEBUG(errs() << "Got a blocking call " << *f << "\n");
        CallInst::Create(preblockFn)->insertBefore(&call);
        CallInst::Create(postblockFn)->insertAfter(&call);
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

  // Intercept calls to pthread_create.
  PthreadCreateVisitor PtCV;
  PtCV.visit(M);
  
  // Now gather all of our basic blocks
  std::vector<BasicBlock*> bbs;
  for (Module::iterator F = M.begin(), FE = M.end(); F != FE; ++F) {
    for (Function::iterator B = F->begin(), BE = F->end(); B != BE; ++B) {
      BasicBlock &pB = *B;
      bbs.push_back(&pB);
    }
  }

  // Store how basic block IDs map to names
  insertBBMap(bbs);
  // Insert sampling call into each basic block
  sampleCall = pM->getOrInsertFunction("PROF_sample", sampleCallTy);
  for (int i = 0, sz = bbs.size(); i < sz; ++i) {
    insertSampleCall(i, bbs[i]);
  }

  // Intercept blocking calls
  BlockingCallVisitor BCV;
  BCV.visit(M);

  return true;
}

