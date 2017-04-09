using namespace std;

// vector<vector<vector<int> > > DP;

int bottomup_sol(const std::vector<int> &A, int i, int ur, int ua);
int bottomup_caso_rojo(const std::vector<int> &A, int i, int ur, int ua);
int bottomup_caso_azul(const std::vector<int> &A, int i, int ur, int ua);
int bottomup_caso_nada(const std::vector<int> &A, int i, int ur, int ua);

int bottomup_sol(const std::vector<int> &A, int i, int ur, int ua) {
    if (i == -1) {
        return 0;
    }

    if (DP[i][ur][ua] != -1) {
        return DP[i][ur][ua];
    }

    return DP[i][ur][ua] = min3(
        bottomup_caso_nada(A, i, ur, ua),
        bottomup_caso_rojo(A, i, ur, ua),
        bottomup_caso_azul(A, i, ur, ua)
    );
}

int bottomup_caso_rojo(const std::vector<int> &A, int i, int ur, int ua) {
    if (ur == (int)A.size()) {  // no pued haber caso rojo si no hay rojo
        return INFINITO;
    }

    if (i == ua) {
        return INFINITO;
    }
    // si i es mas grande que el ultimo rojo, entonces no puede ser rojo pues ur no seria el ultimo
    if (i < ur) { 
        if (A[i] < A[ur]) {  // Si se cumple la propiedad de que los rojos son crecientes estrictos
            // return bottomup_sol(A, i-1, ur, ua);
            return bottomup_sol(A, i-1, i, ua);
        }
    }
    if (i == ur) {
        return bottomup_sol(A, i-1, ur, ua);
    }
    return INFINITO;
}

int bottomup_caso_azul(const std::vector<int> &A, int i, int ur, int ua) {
    if (ua == (int)A.size()) { // no pued haber caso azul si no hay azul
        return INFINITO; 
    }

    if (i == ur) {
        return INFINITO;
    }
    // si i es mas grande que el ultimo azul, entonces no puede ser azul pues ua no seria eel ultimo
    if (i < ua) {
        if (A[i] > A[ua]) {  // Si se cumple la propiedad de que los azules son decrecientes estrictos
            // return bottomup_sol(A, i-1, ur, ua);
            return bottomup_sol(A, i-1, ur, i);
        }
    }
    if (i == ua) {
        return bottomup_sol(A, i-1, ur, ua);
    }
    return INFINITO;
}

int bottomup_caso_nada(const std::vector<int> &A, int i, int ur, int ua) {
    if (i != ua && i != ur) {
        return 1 + bottomup_sol(A, i-1, ur, ua);
    }
    return INFINITO;
}

int resolver_dp_bottomup(int n, const std::vector<int> &numeros) {
    DP.resize(n+1, vector<vector<int> >(n+1, vector<int>(n+1, -1)));

    int min_abs = INFINITO;

    for (int ur = 0; ur <= n; ur++) {
        for (int ua = 0; ua <= n; ua++) {
            if (ur != ua) {
                int solu = bottomup_sol(numeros, n-1, ur, ua);
                min_abs = min(min_abs, solu);
                // cout << "ur: " << ur <<  " ua: " << ua << "  sol: " << solu << "\n";
            }
        }
    }
    return min_abs;
}

// 12 3 11 0 1 3 5 2 4 1 0 9 3

// 8 0 7 1 2 2 1 5 0
