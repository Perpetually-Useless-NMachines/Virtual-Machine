# Virtual-Machine

This is our own version of a virtual machine so that we can control which instruction set we want to support. It is interpreted directly in C++, just as the JVM is byte code interpreted in C.

# VM Code breakdown:
Frontend (aka the parser) is found in the parser. It provides the file interface through the writePUNInstructionsToMemory function.

Backend: split between the instructions/ folder, where each subfolder handles the logic for each specific instruction.

Generally, the frontend generates the backend structs, which then gets simulated through a fetch-decode-execute cycle.

