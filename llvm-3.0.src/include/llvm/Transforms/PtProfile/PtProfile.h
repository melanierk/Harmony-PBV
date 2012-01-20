#ifndef LLVM_PTPROFILE_H
#define LLVM_PTPROFILE_H

#include "llvm/Pass.h"
#include "llvm/Module.h"

namespace llvm {
  class PtProfile;
  ModulePass *createPtProfilePass(); 
}

#endif
