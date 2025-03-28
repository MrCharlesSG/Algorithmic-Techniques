/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
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

template <typename Valor>
class ARM_Kruskal {
private:
	ConjuntosDisjuntos cjtos;
	Valor maximo;
public:

	Valor minimoHoras() const {
		return maximo;
	}

	bool esPosible() {
		return cjtos.num_cjtos() == 1;
	}

	ARM_Kruskal(GrafoValorado<Valor> const& g) : maximo(0), cjtos(g.V()) {
		PriorityQueue<Arista<Valor>> pq(g.aristas());
		int contador = 0;
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				contador++;
				maximo = a.valor();
				if (contador == g.V() - 1) break;
			}
		}
	}
};


void resuelveCaso() {
	int N, M;
	cin >> N >> M;

	GrafoValorado<int> g(N);

	for (int i = 0; i < M; i++)
	{
		int a, b, h;
		cin >> a >> b >> h;
		g.ponArista({ a-1, b-1, h });
	}

	ARM_Kruskal<int> kruskal(g);
	if (kruskal.esPosible()) {
		cout << kruskal.minimoHoras() << "\n";
	}
	else {
		cout << "Imposible\n";
	}
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