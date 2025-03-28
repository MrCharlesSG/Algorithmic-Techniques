
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

using namespace std;





void printSol(vector<int> const& sectores, int N, int S) {
    vector<EntInf> dardos(S + 1, Infinito);
    dardos[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = sectores[i-1]; j <= S; j++) {
            dardos[j] = min(
                dardos[j],
                dardos[j - sectores[i - 1]] + 1
            );
        }
    }

    EntInf num = dardos[S];

    if (num == Infinito)
        cout << "Imposible\n";
    else {
        vector<EntInf> sol;
        int i = N, j = S;
        while (j > 0) {
            if (sectores[i - 1] <= j && dardos[j] == dardos[j - sectores[i - 1]] + 1) {
                // tomamos una moneda de tipo i
                sol.push_back(sectores[i - 1]);
                j = j - sectores[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;

        }

        cout << num << ":";
        for (auto s : sol) {
            cout << " " << s;
        }
        cout << "\n";
    }
}

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>




bool resuelveCaso() {
	int N, S;
	cin >> S >> N;
	if (!cin) return false;

    vector<int> sectores(N);

    for (int i = 0; i < N; i++)
    {
        cin >> sectores[i];
    }

    printSol(sectores, N, S);
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
