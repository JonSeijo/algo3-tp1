using namespace std;

// vector<vector<vector<int> > > DP;

int resolver_dp_bottomup(int n, const std::vector<int> &A) {
    DP.resize(n+3, vector<vector<int> >(n+3, vector<int>(n+3, INFINITO)));

    for (int ur = 0; ur <= n; ur++) {
                // cout << "ur: " << ur << "\n";
        for (int ua = 0; ua <= n; ua++) {
            DP[0][ur][ua] = 0;  // caso base para terminar la suma
        }        
    }

    for (int r = 0; r < n; r++) {
        for (int i = 0; i <= n; i++) {
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
                    min_rojo = DP[i-1][i-1][ua];
                }

                int min_azul = INFINITO;
                if ((i-1 == ua) || (i-1 < ua && A[i-1] > A[ua])) {
                    min_rojo = DP[i-1][ur][i-1];
                }

                DP[i][ur][ua] = min3(min_nada, min_rojo, min_azul);               
            }            
        }
    }


    for (int ur = 0; ur <= n; ur++) {
        for (int ua = 0; ua <= n; ua++) {
            min_abs = min(min_abs, DP[n-1][ur][ua]);
        }
    }
    return min_abs;

}

// incorrecto
// ./solucion 12 3 11 0 1 3 5 2 4 1 0 9 123123
