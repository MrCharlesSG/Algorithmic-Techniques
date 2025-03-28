/*@ <authors>
 *
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "DigrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>


class Borrequin {
#define INF 2147483647

public:

	Borrequin(DigrafoValorado<int> const& g, vector<int> borrequines, int D) : pq(g.V()), dist(g.V(), INF), numBorrequines(0) { // O(A log V) y esp adicional O(V)
		for (int borrequin : borrequines) {
			numBorrequines++;
			dist[borrequin] = 0;
			pq.push(borrequin, 0);
		}
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, D);
		}
	}

	int getNumBorrequines() {
		return numBorrequines;
	}

private:

	std::vector<int> dist;
	IndexPQ<int> pq;
	int numBorrequines;

	void relajar(AristaDirigida<int> a, int D) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor() && dist[v] + a.valor() <= D) {
			if (dist[w] == INF) {
				numBorrequines++;
			}
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}

};

bool resuelveCaso() {
	int N, D, C;

	cin >> D >> N >> C;

	if (!std::cin)
		return false;

	DigrafoValorado<int> dv(N);

	int v, w, u;
	for (int i = 0; i < C; i++)
	{
		cin >> v >> w >> u;

		dv.ponArista({ v - 1, w - 1, u });
		dv.ponArista({ w - 1, v - 1, u });
	}


	int B;
	cin >> B;
	vector<int> borrequines;
	for (int i = 0; i < B; i++)
	{
		int aux;
		cin >> aux;
		borrequines.push_back(aux - 1);
	}

	Borrequin bq(dv, borrequines, D);
	cout << bq.getNumBorrequines() << "\n";
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