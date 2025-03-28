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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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