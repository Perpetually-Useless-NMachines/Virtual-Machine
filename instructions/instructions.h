#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <string>

using namespace std;

// Create a class that's an instructions struct
// Then, we have other things inherit from this class
class Instructions {

    int reg1;
    int reg2;
    int reg3;

  public:
    Instructions(int reg1, int reg2, int reg3);
    virtual void performInstruction();
    virtual uint32_t transformToInteger();

};

Instructions parseInstruction(string s);
Instructions parseIntegerToInstruction(uint32_t integer);

#endif
