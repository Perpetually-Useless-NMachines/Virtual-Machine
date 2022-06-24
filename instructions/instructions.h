#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <string>
#include <memory>

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
    virtual uint32_t transformToInteger() = 0;
    virtual ~Instructions() {};
};

unique_ptr<Instructions> parseInstruction(string s);
unique_ptr<Instructions> parseIntegerToInstruction(uint32_t integer);

#endif
