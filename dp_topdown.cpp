int topdown_sol(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);
int topdown_caso_rojo(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);
int topdown_caso_azul(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);
int topdown_caso_nada(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);

int contador = 0;


int topdown_sol(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    if (i == -1) {
        return 0;
    }

    if (DP[i][ur][ua] != -1) {
        contador++;
        return DP[i][ur][ua];
    }

    return DP[i][ur][ua] = min3(
        topdown_caso_nada(DP, A, i, ur, ua),
        topdown_caso_rojo(DP, A, i, ur, ua),
        topdown_caso_azul(DP, A, i, ur, ua)
    );
}


int topdown_caso_rojo(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    // No puede ser rojo si estoy viendo el caso donde no hay rojo.
    if (ur == (int)A.size()) {
        return INFINITO;
    }

    // No puede ser rojo si ya es el ultimo azul.
    if (i == ua) {
        return INFINITO;
    }

    // Si es el ultimo rojo, entonces es rojo.
    if (i == ur) {
        return topdown_sol(DP, A, i-1, ur, ua);
    }

    // Si indice i fuese mas grande que el ultimo rojo, entonces i no puede ser rojo pues ur no seria el ultimo
    // Si indice i es mas chico que el ultimo rojo, entonces puede ser rojo
    // En ese caso, para que el elemento i sea rojo veo si se cumple la propiedad de creciente estricto
    if ((i < ur) && (A[i] < A[ur])) { 
        // Veo la solucion donde ahora i es el ultimo rojo
        return topdown_sol(DP, A, i-1, i, ua);
    }
    
    return INFINITO;
}


int topdown_caso_azul(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    // No puede ser azul si estoy viendo el caso donde no hay azul.
    if (ua == (int)A.size()) {
        return INFINITO; 
    }

    // No puede ser azul si ya es el ultimo rojo.
    if (i == ur) {
        return INFINITO;
    }
    
    // Si es el ultimo azul, entonces es azul.
    if (i == ua) {
        return topdown_sol(DP, A, i-1, ur, ua);
    }

    // Si indice i fuese mas grande que el ultimo azul, entonces i no puede ser azul pues ua no seria el ultimo
    // Si indice i es mas chico que el ultimo azul, entonces puede ser azul
    // En ese caso, para que el elemento i sea azul veo si se cumple la propiedad de decreciente estricto
    if ((i < ua) && (A[i] > A[ua])) { 
        // Veo la solucion donde ahora i es el ultimo azul
        return topdown_sol(DP, A, i-1, ur, i);    
    }

    return INFINITO;
}


int topdown_caso_nada(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    // No puede pasar que quiera pintar a i de nada, pero que al mismo tiempo el ultimo rojo/azul 
    if (i != ua && i != ur) {
        // La solucion devuelve la cantidad sin pintar. 
        // Como el actual no lo pinto, devuelvo 1 sumado a la solucion para el indice anterior. 
        return 1 + topdown_sol(DP, A, i-1, ur, ua);
    }

    return INFINITO;
}


int resolver_dp_topdown(int n, const std::vector<int> &numeros) {
    Matriz3 DP;
    DP.resize(0);
    DP.resize(n+1, std::vector<std::vector<int> >(n+1, std::vector<int>(n+1, -1)));

    int min_abs = INFINITO;

    for (int ur = 0; ur <= n; ur++) {
        for (int ua = 0; ua <= n; ua++) {
            // if (ur != ua) {
                int solu = topdown_sol(DP, numeros, n-1, ur, ua);
                min_abs = std::min(min_abs, solu);
            // }
        }
    }

    return min_abs;
}
