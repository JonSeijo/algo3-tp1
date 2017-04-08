// POR AHORA ES DP A SECAS PORQUE NO SE DE QUE FORMA LO VOY A IMPLEMENTAR

using namespace std;

vector<vector<vector<int> > > DP;

int sol(const std::vector<int> &A, int i, int ur, int ua);
int caso_rojo(const std::vector<int> &A, int i, int ur, int ua);
int caso_azul(const std::vector<int> &A, int i, int ur, int ua);
int caso_nada(const std::vector<int> &A, int i, int ur, int ua);

void debug(int i) {
    cout << "\ni: " << i << "\n";
    int n = (int)DP.size()-1;
    for (int r = 0; r <= n; r++) {
        for (int a = 0; a <= n; a++) {
            int res = DP[i][r][a];
            if (res == INFINITO) {
                printf("%-9s", "~~");
            } else {
                printf("%-9d", res);
            }
            // cout << "  ";
        }
        cout << "\n";
    }
    cout << "";
}

int min3(int a, int b, int c) {
    return min(a,
        min(b, c)
    );
}

// ur = n = (int)A.size()  significa que no hay rojos
int sol(const std::vector<int> &A, int i, int ur, int ua) {
    // cout << "i: " << i << "\n";
    if (i == 0) {
        return 0;
    }

    if (DP[i][ur][ua] != -1) {
        return DP[i][ur][ua];
    }

    return DP[i][ur][ua] = min3(
        caso_nada(A, i, ur, ua),
        caso_rojo(A, i, ur, ua),
        caso_azul(A, i, ur, ua)
    );
}

int caso_rojo(const std::vector<int> &A, int i, int ur, int ua) {
    if (ur == (int)A.size()) {  // no pued haber caso rojo si no hay rojo
        return INFINITO;
    }

    if (i == ua) {
        return INFINITO;
    }
    // si i es mas grande que el ultimo rojo, entonces no puede ser rojo pues ur no seria el ultimo
    if (i < ur) { 
        if (A[i] < A[ur]) {
            return sol(A, i-1, ur, ua);
        }
    }
    if (i == ur) {
        return sol(A, i-1, ur, ua);
    }
    return INFINITO;
}

int caso_azul(const std::vector<int> &A, int i, int ur, int ua) {
    if (ua == (int)A.size()) { // no pued haber caso azul si no hay azul
        return INFINITO; 
    }

    if (i == ur) {
        return INFINITO;
    }
    // si i es mas grande que el ultimo azul, entonces no puede ser azul pues ua no seria eel ultimo
    if (i < ua) {
        if (A[i] > A[ua]) {
            return sol(A, i-1, ur, ua);
        }
    }
    if (i == ua) {
        return sol(A, i-1, ur, ua);
    }
    return INFINITO;
}

int caso_nada(const std::vector<int> &A, int i, int ur, int ua) {
    if (i != ua && i != ur) {
        return 1 + sol(A, i-1, ur, ua);
    }
    return INFINITO;
}

int f2(const std::vector<int> &A, int i, int ur, int ua) {
    if (DP[i][ur][ua] =! -1) {
        return DP[i][ur][ua];
    }

    if (ur > i || ua > i) {
        return DP[i][ur][ua] = INFINITO;
    }

    if (i == 0) {
        return DP[i][ur][ua] = 0;
    }

    int min_nada = 1 + f2(A, i-1, ur, ua);

    int min_rojo = INFINITO;

    // Dado un ur, ua, quiero
    if (ur == -1 || A[i] > A[ur]) {
        min_rojo = f2(A, i-1, ur, ua);
    }

    int min_azul = INFINITO;
    if (A[i] < A[ua]) {
        min_azul = f2(A, i-1, ur, ua);
    }

    return DP[i][ur][ua] = min3(min_nada, min_rojo, min_azul);
}

int f(const std::vector<int> &A) {

    int n = (int)A.size();


    // Completo casos base

    // Siempre que i sea cero, para no romper considero que el minimo es 0 pues el primer elemento es i=1
    for (int ur = 0; ur <= n; ur++) {
        // for(ua = 0 to n) {
        for (int ua = 0; ua <= n; ua++) {
            DP[0][ur][ua] = 0;
        }
    }

    // No usar ningun color nunca es dejar todos sin pintar, entonces puedo pintar el actual de cualquiera.. no es cierto
    for (int i = 1; i <= n; i++) {
        // DP[i][0][0] = max(i-2, 0);
    }

    // Caso recursivo

    for (int i = 1; i <= n; i++) {
        DP[i][i][i] = INFINITO;  // No puedo elegir i de ambos colores

        // pinto de nada
        for (int uR = 0; uR < i; uR++) {
            for (int uA = 0; uA < i; uA++) {
                DP[i][uR][uA] = 1 + DP[i-1][uR][uA];
            }
        }

        // idea: dp[i][i][uA] = min( |max(uR, uA) - i -1| + dp[i-1][uR][uA] )
        // Casos donde i es rojo, osea uR es i en el dp

        for (int uA = 0; uA < i; uA++) {
            // Completo todas las filas de uA dado que i es rojo
            int min_rojo_opt = INFINITO;

            for (int uR = 0; uR < i; uR++) {

                // No puede ser que el mismo numero este pintado de dos colores, a menos que ninguno este pintado
                // 0 representa que no hay ninguno de ese color

                if (uA != 0 && uA == uR) {
                    DP[i][uR][uA] = INFINITO;
                    continue;
                }

                // quiero DP[i][i][uA]
                // Veo si es valido poner un i en rojo dado uR

                if (uR == 0) {
                    // Si no hay ningun rojo, entonces soy valido
                    if (DP[i-1][0][uA] < min_rojo_opt) {
                        min_rojo_opt = DP[i-1][0][uA];
                    }

                } else if (A[i-1] > A[uR-1]) {
                    // Si hay alguno rojo tengo que ver si soy valido
                    // [a1, a2, (a3), ...., _ai-2, ai-1] ai
                    int ultimoColoreado = max(uR, uA);
                    int sinPintarEnMedio = abs(i - ultimoColoreado - 1);  //revisar +- 1 es importante

                    if (DP[i][uR][uA] + sinPintarEnMedio <= min_rojo_opt) {
                        min_rojo_opt = DP[i][uR][uA] + sinPintarEnMedio;
                    }
                }
                cout << "\nur = " << uR << " ua = " << uA << " i = " << i << ", min_rojo_opt: " << min_rojo_opt << "\n";
            }
            DP[i][i][uA] = min_rojo_opt;  // Lleno todas las filas i, uA
        }



        // Casos donde i es azul, osea uA = i en el dp
        // Idea analoga a lo anterior, moviendo uR
        // idea: dp[i][uR][i] = min( |max(uR, uA) - i -1| + dp[i-1][uR][uA] )


        for (int uR = 0; uR < i; uR++) {
            // Completo todas las filas de uR dado que i es azul
            int min_azul_opt = INFINITO;

            for (int uA = 0; uA < i; uA++) {

                // No puede ser que el mismo numero este pintado de dos colores, a menos que ninguno este pintado
                // 0 representa que no hay ninguno de ese color
                if (uA != 0 && uA == uR) {
                    DP[i][uR][uA] = INFINITO;
                    continue;
                }

                // quiero DP[i][uR][i]
                // Veo si es valido poner un i en azul dado uA
                if (uA == 0) {
                    // Si no hay ningun azul, entonces soy valido
                    if (DP[i-1][uR][0] < min_azul_opt) {
                        min_azul_opt = DP[i-1][uR][0];
                    }
                } else if (A[i-1] <= A[uA-1]) {
                    // [a1, a2, (a3), ...., _ai-2, ai-1] ai
                    int ultimoColoreado = max(uR, uA);
                    int sinPintarEnMedio = abs(i - ultimoColoreado - 1);  //revisar +- 1 es importante

                    if (DP[i][uR][uA] + sinPintarEnMedio < min_azul_opt) {
                        min_azul_opt = DP[i][uR][uA] + sinPintarEnMedio;
                    }
                }
            }
            DP[i][uR][i] = min_azul_opt;  // Lleno todas las filas uR, i
        }

    }

    int optimoAbsoluto = INFINITO;
    for (int uR = 0; uR <= n; uR++) {
        for (int uA = 0; uA <= n; uA++) {
            optimoAbsoluto = min(optimoAbsoluto, DP[n][uR][uA]);
        }
    }

    for (int i = 0; i <= n; i++) {
        debug(i);
    }



    return optimoAbsoluto;

}


int resolver_dp(int n, const std::vector<int> &numeros) {
    DP.resize(n+1, vector<vector<int> >(n+1, vector<int>(n+1, -1)));
    // DP.resize(n+1, vector<vector<int> >(n+1, vector<int>(n+1, INFINITO)));

    int min_abs = INFINITO;
    for (int ur = 0; ur <= n; ur++) {
       // debug(ur);
        for (int ua = 0; ua <= n; ua++) {
            if (ur != ua) {
                int solu = sol(numeros, n, ur, ua);
                min_abs = min(min_abs, solu);
                cout << "ur: " << ur <<  " ua: " << ua << "  sol: " << solu << "\n";
            }
        }
    }
    return min_abs;
    // return f(numeros);
}


// 12 3 11 0 1 3 5 2 4 1 0 9 3

// 8 0 7 1 2 2 1 5 0
