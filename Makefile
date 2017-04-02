CPP=g++
FLAGS=-std=c++11

tiempo: tiempo.cpp backtracking_naive.o backtracking_poda.o
	$(CPP) $(FLAGS) -o $@ $<

solucion: solucion.cpp
	$(CPP) $(FLAGS) -o $@ $< 

# backtrack_poda: backtracking_poda.cpp
# 	$(CPP) $(FLAGS) -o backtrack_poda backtracking_poda.cpp

# backtrack_naive: backtracking_naive.cpp
# 	$(CPP) $(FLAGS) -o backtrack_naive backtracking_naive.cpp

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

all: tiempo 

clean:
	rm -f *.o
	rm tiempo

