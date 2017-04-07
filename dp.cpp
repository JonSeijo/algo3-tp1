// POR AHORA ES DP A SECAS PORQUE NO SE DE QUE FORMA LO VOY A IMPLEMENTAR

#include <climits>

#define INFINITO INT_MAX;


int f() {
    return 0;
}


int resolver_dp(int n, const std::vector<int> &numeros) {
    return f();
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
