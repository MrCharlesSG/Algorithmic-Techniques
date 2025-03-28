
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

int getValue(vector<int> casilla, int i, int j, int N) {
    if (i >= 0 && i < N && j >= 0 && j < N)
        return casilla[getPos(j, i, N)];
    return 0;
}

int getValueInTablero(vector<int> const& tablero, int i, int j, int N) {
    if (i >= 0 && i < N && j >= 0 && j < N) {
        return tablero[getPos(j, i, N)];
    }
    return 0;
}

void printResultado(vector<int> const& tablero, int N) {
    vector<int> casilla(N*N, 0);
    int colMax = 0, maxi = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            int izqTablero = getValueInTablero(tablero, i, j - 1, N);

            int diagIzq = getValue(casilla, i - 1, j - 1, N);
            int diagDcha = getValue(casilla, i - 1, j + 1, N);
            int top = getValue(casilla, i - 1, j, N);

            int tab = tablero[getPos(j, i, N)];
            int primMax = max(
                top,
                diagDcha
            );
            casilla[getPos(j, i, N)] = max(diagIzq,
                primMax
            )
                + tab;

            if (i == N - 1) {
                if (casilla[getPos(j, i, N)] > maxi) {
                    maxi = casilla[getPos(j, i, N)];
                    colMax = j;
                }
            }
        }
    }

    cout << maxi << " " << colMax + 1 << "\n";

}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;

    vector<int> tablero(N * N);

    for (int i = 0; i < N*N; i++)
    {
        cin >> tablero[i];
    }

    printResultado(tablero, N);

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
