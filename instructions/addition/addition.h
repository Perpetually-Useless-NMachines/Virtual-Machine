#ifndef ADDITION_H
#define ADDITION_H

#include "../instructions.h"

class Addition : public Instructions {
  public:
    Addition(int reg1, int reg2, int reg3);
    Addition(const string &s);
    void performInstruction() override;
    virtual ~Addition() {};
    string toString() const override;
};

#endif