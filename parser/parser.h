#ifndef PARSER_H
#define PARSER_H

#include "../instructions/instructions.h"

#include <string>
#include <vector>

using namespace std;

namespace Parser {
void writePUNInstructionsToMemory(string filename, vector<unique_ptr<Instructions>> &memory);
unique_ptr<Instructions> parseInstruction(const string &s);
};

#endif