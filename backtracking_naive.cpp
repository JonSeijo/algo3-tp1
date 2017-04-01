#include <iostream>
#include <vector>
#include <climits>

#define INFINITO INT_MAX;

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

bool valido(std::vector<numero> numeros) {
    int n = (int)numeros.size();
    int ultimoRojo = -1;
    int ultimoAzul = -1;
    for (int i = 0; i < n; i++) {
        if (numeros[i].color == Rojo) {
            if (ultimoRojo != -1) {
                if (numeros[ultimoRojo].num >= numeros[i].num) {
                    return false;
                }
            }
            ultimoRojo = i;
        }

        if (numeros[i].color == Azul) {
            if (ultimoAzul != -1) {
                if (numeros[ultimoAzul].num <= numeros[i].num) {
                    return false;
                }
            }
            ultimoAzul = i;
        }
    }
    return true;
}

// Devuelve la minima cantidad sin pintar posible
int backtrack(int actual, std::vector<numero> &numeros, int ultimoRojo, int ultimoAzul, int cantSinPintar) {
    
    // Caso base, ya no hay mas numeros para pintar
    if (actual == (int)numeros.size()) {
        return valido(numeros) ? cantSinPintar : INFINITO;
    }
    
    int minimo = INFINITO;
    
    // Pinto de rojo
    numeros[actual].color = Rojo;
    int minConRojo = backtrack(actual+1, numeros, actual, ultimoAzul, cantSinPintar);
    minimo = std::min(minimo, minConRojo);
    
    // Pinto de azul 
    numeros[actual].color = Azul;
    int minConAzul = backtrack(actual+1, numeros, ultimoRojo, actual, cantSinPintar);
    minimo = std::min(minimo, minConAzul);
    
    // No pinto 
    numeros[actual].color = Ninguno;
    int minSinPintar = backtrack(actual+1, numeros, ultimoRojo, ultimoAzul, cantSinPintar+1);
    minimo = std::min(minimo, minSinPintar);
    
    return minimo;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<numero> numeros;

    numeros.resize(n, numero(0));
    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i].num;
    }
    
    std::cout << backtrack(0, numeros, -1, -1, 0) << "\n";
    
    return 0;
}
