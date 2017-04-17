#include "definiciones.cpp"
#include "backtracking_naive.cpp"

int main() {
    int n;
    std::vector<int> numeros;

    std::cin >> n;
    numeros.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    std::cout << resolver_backtracking_naive(n, numeros) << "\n";
    
    return 0;
}