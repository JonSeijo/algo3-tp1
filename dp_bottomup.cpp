int bottomup_caso_nada(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    // Al no pintar el actual, entonces el total es 1 + resultado hasta el anterior.
    return 1 + DP[i-1][ur][ua];
}

int bottomup_caso_rojo(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    int min_sinpintar = INFINITO; // Resultado es infinito si no pude pintar el actual de rojo.
    
    bool es_ultimo_rojo = (i == ur) && (i != ua);
    bool cumple_propiedad = (i < ur) && (A[i-1] < A[ur-1]); //(x -> A[x-1] pues indices en A empiezan en 0)
    
    // Si es posible pintar el actual de rojo, 
    // entonces el minimo_sinpintar es la solucion hasta el anterior dado que el actual es ultimo rojo.
    if (es_ultimo_rojo || cumple_propiedad) {
        min_sinpintar = DP[i-1][i][ua];
    }

    return min_sinpintar;
}

int bottomup_caso_azul(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    int min_sinpintar = INFINITO; // Resultado es infinito si no pude pintar el acual de azul.
    
    bool es_ultimo_azul = (i == ua) && (i != ur);
    bool cumple_propiedad = (i < ua) && (A[i-1] > A[ua-1]); //(x -> A[x-1] pues indices en A empiezan en 0)
    
    // Si es posible pintar el actual de azul, 
    // entonces el minimo_sinpintar es la solucion hasta el anterior dado que el actual es el ultimo azul
    if (es_ultimo_azul || cumple_propiedad) {
        min_sinpintar = DP[i-1][ur][i];
    }

    return min_sinpintar;
}


int resolver_dp_bottomup(int n, const std::vector<int> &A) {
    Matriz3 DP;
    DP.resize(0);
    DP.resize(n+2, std::vector<std::vector<int> > (n+2, std::vector<int>(n+2, INFINITO)));

    // Caso base cuando i es 0
    for (int ur = 0; ur <= n+1; ur++) {
        for (int ua = 0; ua <= n+1; ua++) {
            DP[0][ur][ua] = 0;  // caso base para terminar la suma
        }        
    }

    // Caso base cuando el ultimo rojo y el ultimo azul son el mismo
    for (int r = 0; r <= n+1; r++) {
        for (int i = 1; i <= n+1; i++) {
            DP[i][r][r] = INFINITO;
        }
    }

    int min_abs = INFINITO;

    // Lleno la matriz con los resultados, en orden
    for (int ur = 1; ur <= n+1; ur++) {
        for (int ua = 1; ua <= n+1; ua++) {
            for (int i = 1; i <= n; i++) {

                int min_nada = bottomup_caso_nada(DP, A, i, ur, ua);
                int min_rojo = bottomup_caso_rojo(DP, A, i, ur, ua);
                int min_azul = bottomup_caso_azul(DP, A, i, ur, ua);

                DP[i][ur][ua] = min3(min_nada, min_rojo, min_azul);               
            }            
        }
    }

    // Devuelvo el minimo de todas las combinaciones para i = n
    for (int ur = 0; ur <= n+1; ur++) {
        for (int ua = 0; ua <= n+1; ua++) {
            int rta = DP[n][ur][ua];
            min_abs = std::min(min_abs, rta);
        }
    }

    return min_abs;
}
