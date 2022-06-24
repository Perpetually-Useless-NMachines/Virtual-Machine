#include "instructions.h"
#include "halting/halting.h"
#include "store_memory/store_memory.h"

using namespace std;

// TODO: Jenny please implement this function!
// Given a string s, generate the new string where we take the first letter concatenated with
// every other first letter after a dash. e.g.: "so-much" => "sm", "please-no" => "pn"
string parseInstructionType(string s) {
  return "";
}

// TODO: Let's parse this instruction together:
unique_ptr<Instructions> parseInstruction(string s) {
  // Step 1: separate the instruction type from the string s, and get it back.
  // string instructionType = ... 
  // and then generate the rest:
  // string rest = ...

  // Step 2: Get the instruction type
  // string parsedInstructionType = parseInstructionType(s);
  
  // Step 3: Make decisions on how to parse the rest based on parsedInstructionType
  return make_unique<StoreMemory>(0, 0, 0);
}
