
/*@ <authors>
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"

using namespace std;

#include "EnterosInf.h"

/*@ <answer>

esfuerzo(i, j) = cantidad minima de esfuerzo para realizar cortes del Ci al Cj

esfuerzo(i, j) = min{ esfuerzo(i, k) + esfuerzo(k, j) + (Cj - Ci) * 2

esfuerzo(i, j) = 0 if i==j || i == j-1

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const int INF = 1000000000;

int minCoste(vector<int> const& cortes) {
    int n = cortes.size();
    Matriz<int> matrices(n, n, 0);
    for (int d = 2; d < n; d++)  // recorre diagonales
        for (int i = 0; i < n - d; i++)  // recorre elementos de diagonal
        {
            int j = i + d;
            matrices[i][j] = INF;
            for (int k = i + 1; k < j; k++)
            {
                int temp = matrices[i][k] + matrices[k][j] + (cortes[j] - cortes[i]) * 2;
                if (temp < matrices[i][j])  // es mejor partir por k
                {
                    matrices[i][j] = temp;
                }
            }
        }
    return matrices[0][n - 1];
}



bool resuelveCaso() {

    int L, N;
    cin >> L >> N;
    if (L == 0 && N == 0)
        return false;

    vector<int> cortes(N + 2);
    cortes[0] = 0;
    cortes[N + 1] = L;
    for (int i = 1; i <= N; i++)
    {
        cin >> cortes[i];
    }

    cout << minCoste(cortes) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef cortesOMJUcortesGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef cortesOMJUcortesGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
