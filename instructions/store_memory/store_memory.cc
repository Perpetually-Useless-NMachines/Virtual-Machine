#include "store_memory.h"

StoreMemory::StoreMemory(int reg1, int reg2, int reg3) {
  this->reg1 = reg1;
  this->reg2 = reg2;
  this->reg3 = reg3;
}

// given a string rest (so in this case it'll be like 10, 20, 30), either throw an error for a mismatched string
// or properly construct StoreMemory
StoreMemory::StoreMemory(const string &s) {

}

void StoreMemory::performInstruction() {
  // actually perform instructions
}
