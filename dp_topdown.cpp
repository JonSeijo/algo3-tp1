using namespace std;

vector<vector<vector<int> > > DP;

int topdown_sol(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);
int topdown_caso_rojo(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);
int topdown_caso_azul(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);
int topdown_caso_nada(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua);

int topdown_sol(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    if (i == -1) {
        return 0;
    }

    if (DP[i][ur][ua] != -1) {
        return DP[i][ur][ua];
    }

    return DP[i][ur][ua] = min3(
        topdown_caso_nada(DP, A, i, ur, ua),
        topdown_caso_rojo(DP, A, i, ur, ua),
        topdown_caso_azul(DP, A, i, ur, ua)
    );
}

int topdown_caso_rojo(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    if (ur == (int)A.size()) {  // no pued haber caso rojo si no hay rojo
        return INFINITO;
    }

    if (i == ua) {
        return INFINITO;
    }
    // si i es mas grande que el ultimo rojo, entonces no puede ser rojo pues ur no seria el ultimo
    if (i < ur) { 
        if (A[i] < A[ur]) {  // Si se cumple la propiedad de que los rojos son crecientes estrictos
            // return topdown_sol(A, i-1, ur, ua);
            return topdown_sol(DP, A, i-1, i, ua);
        }
    }
    if (i == ur) {
        return topdown_sol(DP, A, i-1, ur, ua);
    }
    return INFINITO;
}

int topdown_caso_azul(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    if (ua == (int)A.size()) { // no pued haber caso azul si no hay azul
        return INFINITO; 
    }

    if (i == ur) {
        return INFINITO;
    }
    // si i es mas grande que el ultimo azul, entonces no puede ser azul pues ua no seria eel ultimo
    if (i < ua) {
        if (A[i] > A[ua]) {  // Si se cumple la propiedad de que los azules son decrecientes estrictos
            // return topdown_sol(A, i-1, ur, ua);
            return topdown_sol(DP, A, i-1, ur, i);
        }
    }
    if (i == ua) {
        return topdown_sol(DP, A, i-1, ur, ua);
    }
    return INFINITO;
}

int topdown_caso_nada(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    if (i != ua && i != ur) {
        return 1 + topdown_sol(DP, A, i-1, ur, ua);
    }
    return INFINITO;
}

int resolver_dp_topdown(int n, const std::vector<int> &numeros) {
    Matriz3 DP;
    DP.resize(0);
    DP.resize(n+1, vector<vector<int> >(n+1, vector<int>(n+1, -1)));

    int min_abs = INFINITO;

    for (int ur = 0; ur <= n; ur++) {
        for (int ua = 0; ua <= n; ua++) {
            if (ur != ua) {
                int solu = topdown_sol(DP, numeros, n-1, ur, ua);
                min_abs = min(min_abs, solu);
            }
        }
    }
    return min_abs;
}
