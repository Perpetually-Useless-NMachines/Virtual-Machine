#include "parser.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sys/wait.h>
#include <fstream>
#include <sstream>
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
  cout << filename << endl;
  if (isOutputFileReadable(filename)) {
    cout << "readable" << endl;
  }

  

}
