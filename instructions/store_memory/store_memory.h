#ifndef STORE_MEMORY_H
#define STORE_MEMORY_H

#include "../instructions.h"

class StoreMemory : public Instructions {
  public:
    StoreMemory(int reg1, int reg2, int reg3);
    StoreMemory(const string &s);
    void performInstruction() override;
    virtual ~StoreMemory() {};
    string toString() const override;
};

#endif