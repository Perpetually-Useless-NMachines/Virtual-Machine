#ifndef STORE_MEMORY_H
#define STORE_MEMORY_H

#include "instructions.h"

class StoreMemory : public Instructions {
  public:
    void performInstruction() override;
};

#endif