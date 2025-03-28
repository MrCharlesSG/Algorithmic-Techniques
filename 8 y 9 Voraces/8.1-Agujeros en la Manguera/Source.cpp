/*@ <authors>
 *
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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

int getNumParches(vector<int> const& dist, int L, int N) {
	int numParches = 1;
	int r = L;
	for (int v = 1; v < N; v++)
	{
		if (dist[v] - dist[v - 1] <= r) {
			r -= (dist[v] - dist[v - 1]);
		}
		else {
			r = L; numParches++;
		}
	}
	return numParches;
}


bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!cin) return false;

	vector<int> dist(N);
	for (int i = 0; i < N; i++)
	{
		cin >> dist[i];
	}

	cout << getNumParches(dist, L, N) << "\n";

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