EXE = main
OBJS = main.o graph.o

CXX = clang++
LD = clang++

WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
CXXFLAGS = -std=c++1y -stdlib=libc++ -O0 $(WARNINGS) -g -c
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi
MKDIR_P = mkdir -p

all : $(EXE)

$(EXE) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)


main.o : main.cpp graph.o outputs
	$(CXX) $(CXXFLAGS) main.cpp 

outputs:
	mkdir -p Outputs

#test : output_msg tests.o graph.o
#    $(LD) tests.o graph.o $(LDFLAGS) -o test

#tests.o : tests/tests.cpp tests/catch/catch.hpp
#    $(CXX) $(CXXFLAGS) tests/tests.cpp

graph.o: graph.h graph.cpp
	$(CXX) $(CXXFLAGS) graph.cpp

.PHONY : output_msg

clean : 
	-rm -f *.o $(EXE) test ./Outputs/*