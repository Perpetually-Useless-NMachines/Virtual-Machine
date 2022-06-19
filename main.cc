#include <iostream>
#include <string>
#include "parser/parser.h"

#define SIZE 2000000

using namespace std;

int main(int argc, char *argv[]) {

	// this represents our memory:
	uint32_t memory [SIZE];

	// Step 1: Transform .pun to binary, and load the binary into memory
	// Step 2: Have a program counter to point to instruction we take out
		// Then, we decode it (into a specific instruction)
		// Then we execute that instruction
	Parser::writePUNInstructionsToMemory(, memory);
	return 0;
}
