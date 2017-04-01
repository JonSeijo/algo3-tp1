CPP=g++
FLAGS=-std=c++11

backtrack: backtracking_naive.cpp
	$(CPP) $(FLAGS) -o backtrack backtracking_naive.cpp

all: backtrack 

clean:
	rm -f *.o