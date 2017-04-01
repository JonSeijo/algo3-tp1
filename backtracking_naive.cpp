#include <iostream>
#include <vector>
#include <climits>

/*
 *  En realidad nada de esto es necesario,
 *  Porque no mee estan pidiendo ningun resultado, solo el minimo
 * 
 *  De todos modos quiza este bueno quedarmelo para poder debugguear
 * 
 */
 
#define INFINITO INT_MAX;

std::vector<int> numeros;


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

// Devuelve la minima cantidad sin pintar posible
int backtrack(int i, 
		int ultimoRojo, int ultimoAzul, int cantSinPintar) {
	
	if (i == (int)numeros.size()) {
		return cantSinPintar;
	}
	
	int minimo = INFINITO;
	
	if (ultimoRojo == -1 || numeros[i] > numeros[ultimoRojo]) {
		int minConRojo = backtrack(i+1, i, ultimoAzul, cantSinPintar);
		minimo = std::min(minimo, minConRojo);
	}
	
	if (ultimoAzul == -1 || numeros[i] < numeros[ultimoAzul]) {
		int minConAzul = backtrack(i+1, ultimoRojo, i, cantSinPintar);
		minimo = std::min(minimo, minConAzul);
	}
	
	int minSinPintar = backtrack(i+1, ultimoRojo, ultimoAzul, cantSinPintar + 1);
	minimo = std::min(minimo, minSinPintar);
	
	return minimo;
}

int main() {
	int n;
	std::cin >> n;

	// numeros es global para evitar pasar el vector cada vezs
	numeros.resize(n);
	for (int i = 0; i < n; i++) {
		std::cin >> numeros[i];
	}
	
	std::cout << backtrack(0, -1, -1, 0) << "\n";
	
	return 0;
}
