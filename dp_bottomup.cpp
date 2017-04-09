
int bottomup_caso_nada(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    return 1 + DP[i-1][ur][ua];
}

int bottomup_caso_rojo(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    int min_rojo = INFINITO;
    
    bool es_ultimo_rojo = (i == ur) && (i != ua);
    bool cumple_propiedad = (i < ur) && (A[i-1] < A[ur-1]);
    
    if (es_ultimo_rojo || cumple_propiedad) {
        min_rojo = DP[i-1][i][ua];
    }

    return min_rojo;
}

int bottomup_caso_azul(Matriz3 &DP, const std::vector<int> &A, int i, int ur, int ua) {
    int min_azul = INFINITO;
    
    bool es_ultimo_azul = (i == ua) && (i != ur);
    bool cumple_propiedad = (i < ua) && (A[i-1] > A[ua-1]);
    
    if (es_ultimo_azul || cumple_propiedad) {
        min_azul = DP[i-1][ur][i];
    }

    return min_azul;
}


int resolver_dp_bottomup(int n, const std::vector<int> &A) {
    Matriz3 DP;
    DP.resize(0);
    DP.resize(n+2, std::vector<std::vector<int> > (n+2, std::vector<int>(n+2, INFINITO)));

    for (int ur = 0; ur <= n+1; ur++) {
        for (int ua = 0; ua <= n+1; ua++) {
            DP[0][ur][ua] = 0;  // caso base para terminar la suma
        }        
    }

    for (int r = 0; r <= n+1; r++) {
        for (int i = 1; i <= n+1; i++) {
            DP[i][r][r] = INFINITO;
        }
    }

    int min_abs = INFINITO;

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


    for (int ur = 0; ur <= n+1; ur++) {
        for (int ua = 0; ua <= n+1; ua++) {
            int rta = DP[n][ur][ua];
            min_abs = std::min(min_abs, rta);
            // cout << "ur: " << ur << " ua: " << ua << " rta: " << rta << "\n";
        }
    }

    // debug2(n);
    return min_abs;
}
