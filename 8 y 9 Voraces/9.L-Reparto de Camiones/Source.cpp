
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;

using lli = long long int;

struct Pueblo {
	lli distS;
	lli distN;
	int index;
};

bool operator>(Pueblo const& a, Pueblo const& b) {
	lli difA = abs(a.distN - a.distS);
	lli difB = abs(b.distN - b.distS);
	return (difA > difB) || (difA == difB && a.index > b.index);
}


class RepartoDeCamiones {
public:
	RepartoDeCamiones(DigrafoValorado<int> const& g): coste(0), N(g.V()), mitad((g.V()-2)/2), distN(N, INF), pqN(N), pqS(N), distS(N, INF) {
		
		dijkstra(g, 0, pqS, distS);
		dijkstra(g, N - 1, pqN, distN);

		vector<Pueblo> pueblos = rellenaPueblos(distN, distS);
		sort(pueblos.begin(), pueblos.end(), greater<Pueblo>());

		repartePueblos(pueblos);
	}

	int getCoste() {
		return coste;
	}
	

private:
	const lli INF = 9223372036854775807;
	lli coste;
	const int N;
	const int mitad;
	vector<lli> distN;
	IndexPQ<int> pqN;
	vector<lli> distS;
	IndexPQ<int> pqS;

	void dijkstra(DigrafoValorado<int> const& g, int origen, IndexPQ<int>& pq, vector<lli>& dist) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, pq, dist);
		}
	}

	void relajar(AristaDirigida<int> a, IndexPQ<int>& pq, vector<lli>& dist) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}

	vector<Pueblo> rellenaPueblos(vector<lli>& distN, vector<lli>& distS) {
		vector<Pueblo> pueblos;
		for (int i = 1; i < N-1; i++)
		{
			pueblos.push_back({ distS[i], distN[i], i });
		}
		return pueblos;
	}

	void repartePueblos(vector<Pueblo> const& pueblosShorted) {
		int pueblosNorte = 0, pueblosSur = 0, i=0;

		while (pueblosNorte < mitad && pueblosSur < mitad) {
			if (pueblosShorted[i].distN <= pueblosShorted[i].distS) {
				pueblosNorte++; coste += pueblosShorted[i].distN*2;
			}
			else {
				pueblosSur++; coste += pueblosShorted[i].distS * 2;
			}
			i++;
		}

		while (pueblosNorte < mitad) {
			pueblosNorte++; coste += pueblosShorted[i].distN * 2;
			i++;
		}

		while (pueblosSur < mitad) {
			pueblosSur++; coste += pueblosShorted[i].distS * 2;
			i++;
		}
	}
};



/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>




bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

	DigrafoValorado<int> dg(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dg.ponArista({ a-1, b-1, c });
		dg.ponArista({ b-1, a-1, c });
	}

	RepartoDeCamiones rp(dg);
	cout << rp.getCoste() << "\n";
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
