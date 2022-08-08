CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
EXEC = pun-vm
OBJECTS = main.o parser/parser.o \
					instructions/instructions.o \
					instructions/store_memory/store_memory.o \
					instructions/halting/halting.o \
					instructions/addition/addition.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
