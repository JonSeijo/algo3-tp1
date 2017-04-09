#include <iostream>
#include <vector>
#include <string>
#include <climits>

// Lo defino asi para no tener overflows inesperados si es que tengo que sumar valores
#define INFINITO (INT_MAX - 1000)

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

void debug(Matriz3 &DP, int i) {
    std::cout << "\ni: " << i << "\n";
    int n = (int)DP.size()-1;
    for (int r = 0; r <= n; r++) {
        for (int a = 0; a <= n; a++) {
            int res = DP[i][r][a];
            if (res == INFINITO) {
                printf("%-9s", "~~");
            } else {
                printf("%-9d", res);
            }
            // std::cout << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "";
}