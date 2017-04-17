#include "definiciones.cpp"
#include "dp_topdown.cpp"

int main() {
    int n;
    std::vector<int> numeros;

    std::cin >> n;
    numeros.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numeros[i];
    }

    std::cout << resolver_dp_topdown(n, numeros) << "\n";
    
    return 0;
}