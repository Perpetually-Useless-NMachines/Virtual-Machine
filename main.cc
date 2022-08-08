#include <iostream>
#include <string>
#include "parser/parser.h"
#include <vector>
// for testing
#include "instructions/instructions.h"

#define SIZE 2000000

using namespace std;

int main(int argc, char *argv[]) {

	// this represents our memory:
	vector<unique_ptr<Instructions>> memory;

	if (argc != 2) {
		cerr << "bad, command wrong" << endl;
		throw "Please enter a valid command!";
	}

	// Step 1: Transform .pun to a bunch of structs	
	// Step 2: Have a program counter to point to instruction we take out
		// Then, we decode it (into a specific instruction)
		// Then we execute that instruction
	Parser::writePUNInstructionsToMemory(argv[1], memory);

	return 0;
}
