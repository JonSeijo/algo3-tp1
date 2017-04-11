bool valido(const std::vector<int> &numeros, std::vector<Color> &colores) {
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
int backtrack_naive(const std::vector<int> &numeros, int actual, std::vector<Color> &colores, int cantSinPintar) {

    // Caso base, ya no hay mas numeros para pintar
    if (actual == (int)numeros.size()) {
        return valido(numeros, colores) ? cantSinPintar : INFINITO;
    }

    int minimo = INFINITO;

    // Pinto de rojo
    colores[actual] = Rojo;
    int minConRojo = backtrack_naive(numeros, actual+1, colores, cantSinPintar);
    minimo = std::min(minimo, minConRojo);

    // Pinto de azul
    colores[actual] = Azul;
    int minConAzul = backtrack_naive(numeros, actual+1, colores, cantSinPintar);
    minimo = std::min(minimo, minConAzul);

    // No pinto
    colores[actual] = Ninguno;
    int minSinPintar = backtrack_naive(numeros, actual+1, colores, cantSinPintar+1);
    minimo = std::min(minimo, minSinPintar);

    return minimo;
}

int resolver_backtracking_naive(int n, const std::vector<int> &numeros) {
    std::vector<Color> colores(n, Ninguno);
    return backtrack_naive(numeros, 0, colores, 0);
}
