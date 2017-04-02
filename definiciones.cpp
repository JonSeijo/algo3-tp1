#include <iostream>

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
