/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "EnterosInf.h"
#include <queue>
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


EntInf getNumTiradas(int K, int S) {
	vector<EntInf> dados(S + 1, 0);
	dados[0] = 1;
	for (int k = 1; k <= K; k++)
	{
		for (int s = k; s <= S; s++) {
			dados[s] = dados[s] + dados[s - k];
		}
	}
	return dados[S];
}

void resuelveCaso() {
	int K, S;
	cin >> K >> S;
	cout << getNumTiradas(K, S) << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}