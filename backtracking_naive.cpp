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
int backtrack(int actual, int ultimoRojo, int ultimoAzul, int cantSinPintar) {
	
	// Caso base, ya no hay mas numeros para pintar
	if (actual == (int)numeros.size()) {
		return cantSinPintar;
	}
	
	int minimo = INFINITO;
	
	// Pinto de rojo solo si el numero es mayor al anterior rojo
	// (Los rojos deben ser estrictamente crecientes)
	if (ultimoRojo == -1 || numeros[actual] > numeros[ultimoRojo]) {
		int minConRojo = backtrack(actual+1, actual, ultimoAzul, cantSinPintar);
		minimo = std::min(minimo, minConRojo);
	}
	
	// Pinto de azul solo si el numero es menor al anterior azul
	// (Los azules deben ser estrictamente decrecientes)
	if (ultimoAzul == -1 || numeros[actual] < numeros[ultimoAzul]) {
		int minConAzul = backtrack(actual+1, ultimoRojo, actual, cantSinPintar);
		minimo = std::min(minimo, minConAzul);
	}
	
	// No pinto al numero de ningun color 
	int minSinPintar = backtrack(actual+1, ultimoRojo, ultimoAzul, cantSinPintar+1);
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
