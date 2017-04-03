CPP=g++
FLAGS= -std=c++11

all: tiempos solucion

tiempos: tiempos.cpp
	$(CPP) $(FLAGS) -o $@ $<

solucion: solucion.cpp
	$(CPP) $(FLAGS) -o $@ $<

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<


clean:
	rm -f *.o
	rm tiempos
	rm solucion
