
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


int getPos(int c, int r, int C) {
    return c + r * C;
}

int getNumCaminos(vector<bool> const& esInterseccion, int M, int N) {
    vector<int> caminos(M, 0);
    caminos[0] = 1;
    for (int i = 0; i < N; i++)
    {
        int origen = getPos(0, i, M);
        caminos[0] = esInterseccion[origen] ? 0 : caminos[0];

        for (int j = 1; j < M; j++) {
            int pos = getPos(j, i, M);

            if (esInterseccion[pos]) {
                caminos[j] = 0;
            }
            else {
                caminos[j] += caminos[j-1];
            }
        }
    }
    return caminos[M - 1];
}

bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

    vector<bool> esInterseccion(N * M);

    for (int i = 0; i < N*M; i++)
    {
        char aux;
        cin >> aux;
        esInterseccion[i] = aux == 'X';
    }

    cout << getNumCaminos(esInterseccion, M, N) << "\n";

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
