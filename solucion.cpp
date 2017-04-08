#include "definiciones.cpp"
#include "backtracking_naive.cpp"
#include "backtracking_poda.cpp"
#include "dp.cpp"

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    std::vector<int> numeros(n, 0);

    for (int i = 0; i < n; i++) {
        std::string dato = argv[i+2];
        numeros[i] = std::stoi(dato);
    }

    std::cout << "Solucion bt naive: " << resolver_backtracking_naive(n, numeros) << "\n";
    std::cout << "Solucion bt poda: " << resolver_backtracking_poda(n, numeros) << "\n";
    std::cout << "Solucion DP: " << resolver_dp(n, numeros) << "\n";
    return 0;
}

