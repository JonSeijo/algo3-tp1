bool valido(const std::vector<int> &numeros, std::vector<Color> &colores) {
    int n = (int)numeros.size();
    int ultimoRojo = -1;
    int ultimoAzul = -1;
    for (int i = 0; i < n; i++) {
		// Valido si los rojos son crecientes
        if (colores[i] == Rojo) {
            if (ultimoRojo != -1) {
				// Si no era estrictamente creciente, devuelvo falso
                if (numeros[ultimoRojo] >= numeros[i]) {
                    return false;
                }
            }
            ultimoRojo = i;
        }
        
		// Valido si los azules son decrecientes
        if (colores[i] == Azul) {
            if (ultimoAzul != -1) {
				// Si no era estrictamente decreciente, devuelvo falso
                if (numeros[ultimoAzul] <= numeros[i]) {
                    return false;
                }
            }
            ultimoAzul = i;
        }
    }
    return true;
}

int cuentaSinPintar(const std::vector<Color> &colores) {
    int sinPintar = 0;
    for (int i = 0; i < (int)colores.size(); i++) {
        sinPintar += (colores[i] == Ninguno ? 1 : 0);
    }
    return sinPintar;
}

// Devuelve la minima cantidad sin pintar posible
int backtrack_naive(const std::vector<int> &numeros, std::vector<Color> &colores, int actual) {

    int n = (int)numeros.size();

    // Caso base, ya no hay mas numeros para pintar
    if (actual == n) {
        return valido(numeros, colores) ? cuentaSinPintar(colores) : INFINITO;
    }

    int minimo = INFINITO;

    // Pinto de rojo
    colores[actual] = Rojo;
    int minConRojo = backtrack_naive(numeros, colores, actual+1);

    // Pinto de azul
    colores[actual] = Azul;
    int minConAzul = backtrack_naive(numeros, colores, actual+1);

    // No pinto
    colores[actual] = Ninguno;
    int minSinPintar = backtrack_naive(numeros, colores, actual+1);

    return min3(minConRojo, minConAzul, minSinPintar);
}

int resolver_backtracking_naive(int n, const std::vector<int> &numeros) {
    std::vector<Color> colores(n, Ninguno);
    return backtrack_naive(numeros, colores, 0);
}
