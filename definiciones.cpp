#include <iostream>
#include <vector>
#include <string>
#include <climits>

// Lo defino asi para no tener overflows inesperados cuando tenga que sumar valores
#define INFINITO (INT_MAX - 10000)

typedef std::vector<std::vector<std::vector<int> > > Matriz3;

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

int min3(int a, int b, int c) {
    return std::min(a,
        std::min(b, c)
    );
}
