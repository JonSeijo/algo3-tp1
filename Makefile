CPP=g++
FLAGS= -std=c++11

tiempos: tiempos.cpp
	$(CPP) $(FLAGS) -o $@ $<

solucion: solucion.cpp
	$(CPP) $(FLAGS) -o $@ $< 

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

all: tiempos 

clean:
	rm -f *.o
	rm tiempos
