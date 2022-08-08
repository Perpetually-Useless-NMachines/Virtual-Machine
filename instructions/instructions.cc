#include "instructions.h"
#include "halting/halting.h"
#include "store_memory/store_memory.h"

using namespace std;

// Given a string s, generate the new string where we take the first letter concatenated with
// every other first letter after a dash. e.g.: "so-much" => "sm", "please-no" => "pn"
string parseInstructionType(const string &s) {
  string abbrev;
  abbrev = s[0];
  char prev = s[0];
  
  for(std::string::size_type i = 1; i < s.size(); ++i) { // assumes s can't end with '-' -> need a check?
    if (prev == '-') {
      abbrev += s[i];
    }
    prev = s[i];
  }
  return abbrev;
}

unique_ptr<Instructions> parseInstruction(const string &s) {
  // Step 1: separate the instruction type from the string s, and get it back. 
  // and then generate the rest:
  string instructionType; 
  bool instructionTypeComplete = false;

  string rest;

  for(std::string::size_type i = 0; i < s.size(); ++i) {
    if (s[i] == ' ' && !instructionTypeComplete) { // since you only need to look for the first space
      instructionTypeComplete = true;
      continue;
      } 
    
    if (!instructionTypeComplete) {
      instructionType += s[i];
      continue;
    }

    rest += s[i];
     
  }  
  cout << instructionType << endl;
  cout << rest << endl;

  // Step 2: Get the instruction type
  string parsedInstructionType = parseInstructionType(s);
  
  // Step 3: Make decisions on how to parse the rest based on parsedInstructionType
  if (parsedInstructionType == "sm") {
    return make_unique<StoreMemory>(rest);
  } else if (parsedInstructionType == "lw") {
  } else if (parsedInstructionType == "halt") {
    return make_unique<Halting>();
  } else {

  }
}
