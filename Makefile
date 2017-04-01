CPP=g++
FLAGS=-std=c++11

backtrack: backtracking.cpp
	$(CPP) $(FLAGS) -o backtrack backtracking.cpp

backtrack_naive: backtracking_naive.cpp
	$(CPP) $(FLAGS) -o backtrack_naive backtracking_naive.cpp

all: backtrack 

clean:
	rm -f *.o