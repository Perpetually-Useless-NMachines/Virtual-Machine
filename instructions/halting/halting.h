#ifndef HALTING_H
#define HALTING_H

#include "../instructions.h"

class Halting : public Instructions {
  public:
    Halting();
    void performInstruction() override;
    virtual ~Halting() {};
};

#endif