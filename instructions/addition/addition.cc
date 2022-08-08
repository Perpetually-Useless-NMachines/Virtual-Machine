#include "addition.h"
#include <iostream>
using namespace std;

Addition::Addition(int reg1, int reg2, int reg3) {
  this->reg1 = reg1;
  this->reg2 = reg2;
  this->reg3 = reg3;
}

// given a string rest (so in this case it'll be like 10, 20, 30), either throw an error for a mismatched string
// or properly construct Addition
Addition::Addition(const string &s) {
  cout << "Rest of the string: " << s << endl;
  // "0, 0, 100" -- parse it so that reg1 = 0, reg2 = 0, reg3 = 100
}

void Addition::performInstruction() {
  // actually perform instructions
}

string Addition::toString() const {return "Addition";}