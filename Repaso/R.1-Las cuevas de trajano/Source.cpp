/*@ <authors>
 *
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
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
class Dijkstra {
public:
	Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig), profundidad(g.V(), INF), pq(g.V()) {
		pq.push(origen, 0);
		profundidad[origen] = 0;
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	bool hayCamino(int v) const { return profundidad[v] != INF; }

	Valor maxRespiracion(int v) const { return profundidad[v]; }

private:
	const Valor INF = 1000000000;
	int origen;
	std::vector<Valor> profundidad;
	IndexPQ<Valor> pq;

	void relajar(AristaDirigida<Valor> a) {
		int v = a.desde(), w = a.hasta();
		Valor maxProf = max(profundidad[v], a.valor());
		if (profundidad[w] > maxProf) {
			profundidad[w] = maxProf;
			pq.update(w, profundidad[w]);
		}
	}
};



bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

	DigrafoValorado<int> g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g.ponArista({ a - 1, b - 1, c });
		g.ponArista({ b - 1, a - 1, c });
	}

	int origen, destino;
	cin >> origen >> destino;

	Dijkstra<int> d(g, origen - 1);
	if (d.hayCamino(destino - 1)) {
		cout << d.maxRespiracion(destino - 1) << "\n";
	}
	else {
		cout << "IMPOSIBLE\n";
	}

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