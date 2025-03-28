
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

int numParesPilas(vector<int> pilas, int N, int V) {
    int j = N-1, i = 0, numPares=0;
    while (i < j) {
        if (pilas[i] + pilas[j] >= V) {
            numPares++; i++; j--;
        }
        else
            i++;
    }
    return numPares;
}

void resuelveCaso() {
    int  V, N;
    cin >> N >> V;

    vector<int> pilas(N);

    for (int i = 0; i < N; i++)
    {
        cin >> pilas[i];
    }

    sort(pilas.begin(), pilas.end());

    cout << numParesPilas(pilas, N, V) << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.


int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}

