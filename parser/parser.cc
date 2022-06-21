#include "parser.h"
#include "../instructions/instructions.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/wait.h>
#include <fstream>
#include <sstream>
#include <wctype.h>
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

void Parser::writePUNInstructionsToMemory(string filename, uint32_t *memory) {
  if (isOutputFileReadable(filename)) {
    ifstream infile(filename);
    int memLocation = 0;

    string line;
    while (getline(infile, line)) {
      if (line.size() == 0) continue;

      char c = line.at(0);

      if (c == 'q' || iswspace(c)) continue;

      Instructions instruction = parseInstruction(line);
      memory[memLocation] = instruction.transformToInteger();
      memLocation++;
    }
    for (int i = 0; i < 20; ++i) {
      cout << i << " " << memory[i] << endl;
    }
  }
}
