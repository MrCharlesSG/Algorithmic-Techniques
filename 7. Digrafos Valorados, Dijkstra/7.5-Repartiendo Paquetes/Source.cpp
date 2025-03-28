#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;

using lli = long long int;

class Dijkstra {
public:
	Dijkstra(DigrafoValorado<int> const& g, int orig) : origen(orig), dist(g.V(), INF), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a);
		}
	}

	bool hayCamino(int v) const { return dist[v] != INF; }

	lli distancia(int v) const { return dist[v]; }

private:
	const lli INF = 9223372036854775807;
	int origen;
	std::vector<lli> dist;
	IndexPQ<lli> pq;

	void relajar(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
		}
	}
};





bool resuelveCaso() {
    int N, C;
    cin >> N >> C;
    if (!cin) return false;

	DigrafoValorado<int> g(N);
	DigrafoValorado<int> ig(N);

	bool esPosible = true;
	int coste = 0;

	for (int i = 0; i < C; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g.ponArista({ a - 1, b - 1, c });
		ig.ponArista({ b - 1, a - 1, c });
	}

	int O, P;
	cin >> O >> P;
	O--;
	Dijkstra dijkstraOrigen(g, O);
	Dijkstra dijkstraVuelta(ig, O);
	for (int i = 0; i < P; i++)
	{
		int d;
		cin >> d;
		d--;
		if (dijkstraOrigen.hayCamino(d) && dijkstraVuelta.hayCamino(d)) {
			coste += dijkstraOrigen.distancia(d) + dijkstraVuelta.distancia(d);
		}
		else {
			esPosible = false;
		}
	}

	if (esPosible) {
		cout << coste << "\n";
	}
	else {
		cout << "Imposible\n";
	}


    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
