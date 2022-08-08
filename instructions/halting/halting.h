#ifndef HALTING_H
#define HALTING_H

#include "../instructions.h"

class Halting : public Instructions {
  public:
    Halting();
    void performInstruction() override;
    uint32_t transformToInteger() override {return 0x1100;};
    virtual ~Halting() {};
};

#endif