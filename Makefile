CPP=g++
FLAGS= -std=c++11

all: tiempos solucion ej1 ej2 ej3 ej4

tiempos: tiempos.cpp
	$(CPP) $(FLAGS) -o $@ $<

solucion: solucion.cpp
	$(CPP) $(FLAGS) -o $@ $<

ej1: ej1.cpp
	$(CPP) $(FLAGS) -o $@ $<

ej2: ej2.cpp
	$(CPP) $(FLAGS) -o $@ $<

ej3: ej3.cpp
	$(CPP) $(FLAGS) -o $@ $<

ej4: ej4.cpp
	$(CPP) $(FLAGS) -o $@ $<

%.o: %.cpp
	$(CPP) $(FLAGS) -c -o $@ $<

clean:
	rm -f *.o
	rm tiempos
	rm solucion
	rm ej1
	rm ej2
	rm ej3
	rm ej4
