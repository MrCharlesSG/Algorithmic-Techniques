#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
using namespace std;


class AutonomiaVehiculos {
private:
	int autonomia;
	bool posible;
public:
	

	AutonomiaVehiculos(GrafoValorado<int> const& g) : autonomia(0) {
		int numCiudadesVisitadas = 1;
		posible = numCiudadesVisitadas == g.V();
		PriorityQueue<Arista<int>> pq(g.aristas());
		ConjuntosDisjuntos cjtos(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjtos.unidos(v, w)) {
				cjtos.unir(v, w);
				numCiudadesVisitadas++;
				if (numCiudadesVisitadas == g.V()) {
					autonomia = a.valor();
					posible = true;
				}
			}
		}
	}

	bool esPosible() {
		return posible;
	}

	int getAutonomia() {
		return autonomia;
	}
};





bool resuelveCaso() {
    int N, M;
    cin >> N >> M;
    if (!cin) return false;

	GrafoValorado<int> g(N);

	for (int i = 0; i < M; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		g.ponArista({ a-1, b-1, l });
	}

	AutonomiaVehiculos a(g);
	if (a.esPosible()) {
		cout << a.getAutonomia() << "\n";
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
