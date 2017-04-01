CPP=g++
FLAGS=-std=c++11

backtrack: backtracking.cpp
	$(CPP) $(FLAGS) -o backtrack backtracking.cpp

all: backtrack 

clean:
	rm -f *.o