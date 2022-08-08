#include "parser.h"
#include "../instructions/instructions.h"
#include "../instructions/halting/halting.h"
#include "../instructions/store_memory/store_memory.h"
#include "../instructions/addition/addition.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/wait.h>
#include <fstream>
#include <sstream>
#include <wctype.h>
#include <memory>
using namespace std;

// checks if a file exists and returns exit status, 0 means it does, 1 means it doesn't
bool doesFileExist(const string &filename) {
  return WEXITSTATUS(system(("test -f " + filename).c_str())) == 0;
}

bool isOutputFileReadable(const string &outputFileName) {
  if (!doesFileExist(outputFileName)) {
    cerr << "Output File: " << outputFileName << " does not exist!" << endl;
    throw "file doesn't exist";
  }
  return true;
}

void Parser::writePUNInstructionsToMemory(string filename, vector<unique_ptr<Instructions>> &memory) {
  if (isOutputFileReadable(filename)) {
    ifstream infile(filename);
    int memLocation = 0;

    string line;
    while (getline(infile, line)) {
      if (line.size() == 0) continue;

      char c = line.at(0);

      if (c == 'q' || iswspace(c)) continue;

      memory.push_back(parseInstruction(line)); 
      ++memLocation;
    }
    for (int i = 0; i < 20; ++i) {
      try
      {
        cout << i << " " << (memory.at(i)->toString()) << endl;
      }
      catch(const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        break;
      }
    }
  }
}

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

unique_ptr<Instructions> Parser::parseInstruction(const string &s) {
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
    return make_unique<Addition>(rest);
  } else if (parsedInstructionType == "halt") {
    return make_unique<Halting>();
  } else if (parsedInstructionType == "add") {
    return make_unique<Addition>(rest);
  } else {
    return make_unique<Addition>(rest);
  }
}

