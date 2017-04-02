#include <iostream>
#include <vector>
#include <string>
#include <climits>

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


bool valido(std::vector<Color> &colores) {
    int n = (int)numeros.size();
    int ultimoRojo = -1;
    int ultimoAzul = -1;
    for (int i = 0; i < n; i++) {
        if (colores[i] == Rojo) {
            if (ultimoRojo != -1) {
                if (numeros[ultimoRojo] >= numeros[i]) {
                    return false;
                }
            }
            ultimoRojo = i;
        }

        if (colores[i] == Azul) {
            if (ultimoAzul != -1) {
                if (numeros[ultimoAzul] <= numeros[i]) {
                    return false;
                }
            }
            ultimoAzul = i;
        }
    }
    return true;
}

// Devuelve la minima cantidad sin pintar posible
int backtrack_naive(int actual, std::vector<Color> &colores,
             int ultimoRojo, int ultimoAzul, int cantSinPintar) {
    
    // Caso base, ya no hay mas numeros para pintar
    if (actual == (int)numeros.size()) {
        return valido(colores) ? cantSinPintar : INFINITO;
    }
    
    int minimo = INFINITO;
    
    // Pinto de rojo
    colores[actual] = Rojo;
    int minConRojo = backtrack_naive(actual+1, colores, actual, ultimoAzul, cantSinPintar);
    minimo = std::min(minimo, minConRojo);
    
    // Pinto de azul 
    colores[actual] = Azul;
    int minConAzul = backtrack_naive(actual+1, colores, ultimoRojo, actual, cantSinPintar);
    minimo = std::min(minimo, minConAzul);
    
    // No pinto 
    colores[actual] = Ninguno;
    int minSinPintar = backtrack_naive(actual+1, colores, ultimoRojo, ultimoAzul, cantSinPintar+1);
    minimo = std::min(minimo, minSinPintar);
    
    return minimo;
}

int resolver_backtracking_naive(int n, std::vector<int> &numeros) {
    std::vector<Color> colores(n, Ninguno);
    return backtrack_naive(0, colores, -1, -1, 0);
}

// int main(int argc, char *argv[]) {
//     int n = atoi(argv[1]);
//     numeros.resize(n, 0);
//     for (int i = 0; i < n; i++) {
//         std::string dato = argv[i+2];
//         numeros[i] = std::stoi(dato);
//     }
//     std::cout << resolver_backtracking_naive(n, numeros) << "\n";
    
//     return 0;
// }
