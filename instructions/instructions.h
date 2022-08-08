#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

// Create a class that's an instructions struct
// Then, we have other things inherit from this class
class Instructions {

  protected:
    int reg1;
    int reg2;
    int reg3;

  public:
    virtual void performInstruction() = 0;
    virtual ~Instructions() {};
    virtual string toString() const {return "Unspecified Instruction";}
};

#endif
