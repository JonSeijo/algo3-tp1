// POR AHORA ES DP A SECAS PORQUE NO SE DE QUE FORMA LO VOY A IMPLEMENTAR

using namespace std;

vector<vector<vector<int> > > DP;

void debug(int i) {
    int n = (int)DP.size()-1;
    for (int r = 0; r <= n; r++) {
        for (int a = 0; a <= n; a++) {
            int res = DP[i][r][a];
            if (res == INFINITO) {
                printf("%-12s", "~~~");
            } else {
                printf("%-12d", res);
            }
            // cout << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
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

    // No usar ningun color nunca es dejar todos sin pintar
    for (int i = 0; i <= n; i++) {
        DP[i][0][0] = i;
    }

    // Caso recursivo


    for (int i = 1; i <= n; i++) {
        DP[i][i][i] = INFINITO;  // No puedo elegir i de ambos colores

        // pinto de nada
        // for (uR = 0 to i-1) {
        for (int uR = 0; uR < i; uR++) {
            // for (uA = 0 to i-1) {
            for (int uA = 0; uA < i; uA++) {
                DP[i][uR][uA] = 1 + DP[i-1][uR][uA];
            }
        }

        // idea: dp[i][i][uA] = min( |max(uR, uA) - i -1| + dp[i-1][uR][uA] )
        // Casos donde i es rojo, osea uR es i en el dp

        // for (uA = 0 to i-1) {
        for (int uA = 0; uA < i; uA++) {
            // Completo todas las filas de uA dado que i es rojo
            int min_rojo_opt = INFINITO;

            // for (uR = 0 to i-1) {
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

                } else if (A[i] > A[uR]) {
                    // Si hay alguno rojo tengo que ver si soy valido
                    // [a1, a2, (a3), ...., _ai-2, ai-1] ai
                    int ultimoColoreado = max(uR, uA);
                    int sinPintarEnMedio = i - ultimoColoreado - 1;  //revisar +- 1 es importante

                    if (DP[i][uR][uA] + sinPintarEnMedio < min_rojo_opt) {
                        min_rojo_opt = DP[i][uR][uA] + sinPintarEnMedio;
                    }

                }
            }
            DP[i][i][uA] = min_rojo_opt;  // Lleno todas las filas i, uA
        }



        // Casos donde i es azul, osea uA = i en el dp
        // Idea analoga a lo anterior, moviendo uR
        // idea: dp[i][uR][i] = min( |max(uR, uA) - i -1| + dp[i-1][uR][uA] )


        // for (uR = 0 to i-1) {
        for (int uR = 0; uR < i; uR++) {
            // Completo todas las filas de uR dado que i es azul
            int min_azul_opt = INFINITO;

            // for (uA = 0 to i-1) {
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
                    if (DP[i-1][uA][0] < min_azul_opt) {
                        min_azul_opt = DP[i-1][uA][0];
                    }
                } else if (A[i] < A[uA]) {
                    // [a1, a2, (a3), ...., _ai-2, ai-1] ai
                    int ultimoColoreado = max(uR, uA);
                    int sinPintarEnMedio = i - ultimoColoreado - 1;  //revisar +- 1 es importante

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

    debug(1);

    debug(2);

    debug(3);


    return optimoAbsoluto;
}


int resolver_dp(int n, const std::vector<int> &numeros) {
    DP.resize(n+1, vector<vector<int> >(n+1, vector<int>(n+1, INFINITO)));
    return f(numeros);
}


/*
La idea es que DP[i][uR][uA] guarde el optimo de una secuencia de longitud i que termina en uR y uA


// Completo casos base

Siempre que i sea cero, el minimo es 0 pues el primer elemento es 1
for (ur = 0 to n) {
    for(ua = 0 to n) {
        DP[0][ur][ua] = 0;
    }
}

// Caso recursivo


for (i = 1 to n) {
    DP[i][i][i] = INFINITO;  // No puedo elegir i de ambos colores

    // pinto de nada
    for (uR = 0 to i-1) {
        for (uA = 0 to i-1) {
            DP[i][uR][uA] = 1 + DP[i-1][uR][uA];
        }
    }

    // idea: dp[i][i][uA] = min( |max(uR, uA) - i -1| + dp[i-1][uR][uA] )
    // Casos donde i es rojo, osea uR es i en el dp

    for (uA = 0 to i-1) {
        Completo todas las filas de uA dado que i es rojo
        int min_rojo_opt = INFINITO;

        for (uR = 0 to i-1) {

            // No puede ser que el mismo numero este pintado de dos colores, a menos que ninguno este pintado
            // 0 representa que no hay ninguno de ese color

            if (uA != 0 && uA == uR) {
                DP[i][uR][uA] = INFINITO
                continue;
            }

            // quiero DP[i][i][uA]
            // Veo si es valido poner un i en rojo dado uR

            if (uR == 0) {
                // Si no hay ningun rojo, entonces soy valido
                if (DP[i-1][0][uA] < min_rojo_opt) {
                    min_rojo_opt = DP[i-1][0][uA];
                }

            } else if (A[i] > A[uR]) {
                // Si hay alguno rojo tengo que ver si soy valido
                // [a1, a2, (a3), ...., _ai-2, ai-1] ai
                int ultimoColoreado = max(uR, uA);
                int sinPintarEnMedio = i - ultimoColoreado - 1  //revisar +- 1 es importante

                if (DP[i][uR][uA] + sinPintarEnMedio < min_rojo_opt) {
                    min_rojo_opt = DP[i][uR][uA] + sinPintarEnMedio;
                }

            }
        }
        dp[i][i][uA] = min_rojo_opt  // Lleno todas las filas i, uA
    }



    // Casos donde i es azul, osea uA = i en el dp
    // Idea analoga a lo anterior, moviendo uR
    // idea: dp[i][uR][i] = min( |max(uR, uA) - i -1| + dp[i-1][uR][uA] )


    for (uR = 0 to i-1) {
        Completo todas las filas de uR dado que i es azul
        int min_azul_opt = INFINITO;

        for (uA = 0 to i-1) {

            // No puede ser que el mismo numero este pintado de dos colores, a menos que ninguno este pintado
            // 0 representa que no hay ninguno de ese color
            if (uA != 0 && uA == uR) {
                DP[i][uR][uA] = INFINITO
                continue;
            }

            // quiero DP[i][uR][i]
            // Veo si es valido poner un i en azul dado uA
            if (uA == 0) {
                // Si no hay ningun azul, entonces soy valido
                if (DP[i-1][uA][0] < min_azul_opt) {
                    min_azul_opt = DP[i-1][uA][0];
                }
            } else if (A[i] < A[uA]) {
                // [a1, a2, (a3), ...., _ai-2, ai-1] ai
                int ultimoColoreado = max(uR, uA);
                int sinPintarEnMedio = i - ultimoColoreado - 1  //revisar +- 1 es importante

                if (DP[i][uR][uA] + sinPintarEnMedio < min_azul_opt) {
                    min_azul_opt = DP[i][uR][uA] + sinPintarEnMedio;
                }
            }
        }
        dp[i][uR][i] = min_azul_opt  // Lleno todas las filas uR, i
    }

}


*/
