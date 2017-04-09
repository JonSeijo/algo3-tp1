using namespace std;

int resolver_dp_bottomup(int n, const std::vector<int> &A) {
    Matriz3 DP;
    DP.resize(0);
    DP.resize(n+2, vector<vector<int> > (n+2, vector<int>(n+2, INFINITO)));

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

            if (ur == ua) 
                continue;

            // recordar que lo que quiero ver es A[i-1]
            for (int i = 1; i <= n; i++) {


                // caso nada
                int min_nada = 1 + DP[i-1][ur][ua];

                int min_rojo =   INFINITO;
                if (i == ur || (i < ur && A[i-1] < A[ur-1])) {
                    min_rojo = DP[i-1][i][ua];
                }

                int min_azul = INFINITO;
                if (i == ua || (i < ua && A[i-1] > A[ua-1])) {
                    min_azul = DP[i-1][ur][i];
                }

                DP[i][ur][ua] = min3(min_nada, min_rojo, min_azul);               
            }            
        }
    }


    for (int ur = 0; ur <= n+1; ur++) {
        for (int ua = 0; ua <= n+1; ua++) {
            int rta = DP[n][ur][ua];
            min_abs = min(min_abs, rta);
            // cout << "ur: " << ur << " ua: " << ua << " rta: " << rta << "\n";
        }
    }

    // debug2(n);
    return min_abs;
}
