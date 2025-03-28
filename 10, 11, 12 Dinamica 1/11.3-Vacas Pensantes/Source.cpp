
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"
#include "Matriz.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int cubos_rec(vector<int> const& comida, int i, int j, Matriz<int>& cubos) {
    int& res = cubos[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = comida[i];
        else {
            int comidaIzq = comida[i], comidaDcha = comida[j],
                comidaSigIzq = i + 1 < j ? comida[i + 1] : 0,
                comidaSigDcha = j - 1 > i ? comida[j - 1] : 0,
                resIzq, resDcha;

            if (comidaSigIzq > comidaDcha) {
                resIzq = cubos_rec(comida, i + 2, j, cubos);
            }
            else {
                resIzq = cubos_rec(comida, i + 1, j - 1, cubos);
            }
            if (comidaSigDcha > comidaIzq) {
                resDcha = cubos_rec(comida, i, j - 2, cubos);
            }
            else {
                resDcha = cubos_rec(comida, i + 1, j - 1, cubos);
            }
            res = max(
                resIzq + comidaIzq,
                resDcha + comidaDcha
            );
        }
    }
    return res;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin || N == 0) return false;

    vector<int> comida(N);
    for (int i = 0; i < N; i++)
    {
        cin >> comida[i];
    }

    Matriz<int> cubos(N, N, -1);
    cout << cubos_rec(comida, 0, N - 1, cubos) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
