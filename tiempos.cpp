#include "backtracking_naive.cpp"
#include <chrono>

// NOTA: Si quiero muchas ejecuciones para la misma entrada, 
// lo controlo desde el script de python que llama a ./tiempos

/*
 * Params:
 * 1) n
 * 2) numeros del input separados por espacios
 */

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    
    // Numeros es global pues no cambia para ningun problema
    numeros.resize(n, 0);

    for (int i = 0; i < n; i++) {
        std::string dato = argv[i+2];
        numeros[i] = std::stoi(dato);
    }

    std::cout << resolver_backtracking_naive(n, numeros) << "\n";
    
    return 0;
}

