
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.


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

