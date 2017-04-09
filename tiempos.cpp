#include "definiciones.cpp"
#include "backtracking_naive.cpp"
#include "backtracking_poda.cpp"
#include <stdlib.h>
#include <chrono>
#include <stdexcept>

#define ya std::chrono::high_resolution_clock::now

// NOTA: Si quiero muchas ejecuciones para la misma entrada, 
// lo controlo desde el script de python que llama a ./tiempos

const std::string todo = "todo";
const std::string bt_todo = "bt";
const std::string bt_naive = "naive";
const std::string bt_poda = "poda";
const std::string dp_todo = "dp";
const std::string dp_topdown = "topdown";
const std::string dp_bottomup = "bottomup";

void medirBacktrackNaive(int n, std::vector<int> &numeros) {
    auto start = ya();
    resolver_backtracking_naive(n, numeros);
    auto end = ya();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << ";";
}

void medirBacktrackPoda(int n, std::vector<int> &numeros) {
    auto start = ya();
    resolver_backtracking_poda(n, numeros);
    auto end = ya();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << ";";    
}

void medirBacktrack(int n, std::vector<int> &numeros) {
    medirBacktrackNaive(n, numeros);
    medirBacktrackPoda(n, numeros);
}

void medirTodo(int n, std::vector<int> &numeros) {
    medirBacktrack(n, numeros);
}

/*
 * Params:
 * 1) programa
 * 2) n
 * 3) numeros del input separados por espacios
 */

int main(int argc, char *argv[]) {

    std::string programa = argv[1];
    int n = atoi(argv[2]);
    std::vector<int> numeros(n, 0);

    for (int i = 0; i < n; i++) {
        std::string dato = argv[i+3];
        numeros[i] = std::stoi(dato);
    }

    // Corro el programa deseado 1 vez, con los parametros que pase
    if (programa == todo) {
        medirTodo(n, numeros);
    } else if (programa == bt_naive) {
        medirBacktrackNaive(n, numeros);
    } else if (programa == bt_poda) {
        medirBacktrackPoda(n, numeros);
    } else if (programa == bt_todo) {
        medirBacktrack(n, numeros);
    } else if (programa == todo) {
        medirTodo(n, numeros);
    } else {
        throw std::invalid_argument("Parametro 'programa' no es valido !!");
    }

    return 0;
}

