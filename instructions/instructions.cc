#include "instructions.h"
#include "halting/halting.h"
#include "store_memory/store_memory.h"

// TODO: Jenny pls implement this constructor:
Instructions::Instructions(int reg1, int reg2, int reg3) {}

// TODO: Let's parse this instruction together:
Instructions parseInstruction(string s) {
  char c = s.at(0);
  switch(c) {
    case 's':
      // parse the string s for the registers
      return StoreMemory(0, 0, 0);    
      break;
  }
}
