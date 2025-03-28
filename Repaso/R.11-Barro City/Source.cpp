#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
using namespace std;


class BarroCity {
private:
	bool posible;
	int coste;
public:
	int getCoste() const {
		return coste;
	}

	bool esPosible() {
		return posible;
	}

	BarroCity(GrafoValorado<int> const& g) : coste(0) {
		PriorityQueue<Arista<int>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());
		int numCalles=1;
		posible = g.V() == numCalles;
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				numCalles++; coste += a.valor();
				if (numCalles == g.V()) {
					posible = true;
					break;
				}
			}
		}
	}
};



bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin) return false;
	GrafoValorado<int> g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g.ponArista({ a - 1, b - 1, c });
	}

	BarroCity bc(g);
	if (bc.esPosible()) {
		cout << bc.getCoste() << "\n";
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
