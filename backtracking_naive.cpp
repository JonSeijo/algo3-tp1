#include <iostream>
#include <vector>

/*
 *  En realidad nada de esto es necesario,
 *  Porque no mee estan pidiendo ningun resultado, solo el minimo
 * 
 *  De todos modos quiza este bueno quedarmelo para poder debugguear
 * 
 */

enum Color { 
	Azul, Rojo, Ninguno
};

// Defino << para mostrar el color
std::ostream& operator<<(std::ostream& os, Color c) {
    switch(c) {
		case Azul: os << "Azul"; break;
		case Rojo: os << "Rojo"; break;
		default: os << "Ninguno";
    }
    return os;
}

// Un numero es un entero con un color asociado
struct numero {
	numero(int numIn) : num(numIn), color(Ninguno) {}
	int num;
	Color color;
};

int 

int main() {
	
	numero uno(1);
	
	std::cout << uno.num << " " << uno.color << "\n";
	
	return 0;
}
