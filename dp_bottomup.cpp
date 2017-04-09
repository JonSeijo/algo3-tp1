using namespace std;

// vector<vector<vector<int> > > DP;

void debug2(int i) {
    cout << "\ni: " << i << "\n";
    int n = (int)DP.size()-3;
    for (int r = 0; r <= n; r++) {
        for (int a = 0; a <= n; a++) {
            int res = DP[i][r][a];
            if (res == INFINITO) {
                printf("%-7s", "~~");
            } else {
                printf("%-7d", res);
            }
            // cout << "  ";
        }
        cout << "\n";
    }
    cout << "";
}


int resolver_dp_bottomup(int n, const std::vector<int> &A) {
    
    DP.resize(n+3, vector<vector<int> >(n+3, vector<int>(n+3, INFINITO)));

    for (int ur = 0; ur <= n; ur++) {
                // cout << "ur: " << ur << "\n";
        for (int ua = 0; ua <= n; ua++) {
            DP[0][ur][ua] = 0;  // caso base para terminar la suma
        }        
    }

    for (int r = 0; r < n; r++) {
        for (int i = 1; i <= n; i++) {
            DP[i][r][r] = INFINITO;
        }
    }

    int min_abs = INFINITO;

    for (int ur = 1; ur <= n; ur++) {
        for (int ua = 1; ua <= n; ua++) {
            // recordar que lo que quiero ver es A[i-1]
            for (int i = 1; i <= n; i++) {
                // cout << "i: " << i << "\n";

 
                // caso nada
                int min_nada = 1 + DP[i-1][ur][ua];

                int min_rojo = INFINITO;
                if ((i-1 == ur) || (i-1 < ur && A[i-1] < A[ur])) {
                    min_rojo = DP[i-1][i][ua];
                }

                int min_azul = INFINITO;
                if ((i-1 == ua) || (i-1 < ua && A[i-1] > A[ua])) {
                    min_rojo = DP[i-1][ur][i];
                }

                DP[i][ur][ua] = min3(min_nada, min_rojo, min_azul);               
            }            
        }
    }


    for (int ur = 0; ur <= n; ur++) {
        for (int ua = 0; ua <= n; ua++) {
            int rta = DP[n-1][ur][ua];
            min_abs = min(min_abs, rta);
            // cout << "ur: " << ur << " ua: " << ua << " rta: " << rta << "\n";
        }
    }

    // debug2(n-2);
    return min_abs;
}

// incorrecto
// ./solucion 12 3 11 0 1 3 5 2 4 1 0 9 123123

// ./solucion 5 3 2 4 1 5  da 1 pero deberia dar 0
// ./solucion 5 1 1 1 1 1  da 2 pero deberia dar 3

