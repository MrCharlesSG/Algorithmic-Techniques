
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Grafo.h"
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


class Peaje {
private:
	std::vector<bool> visitAlex; // visitAlex[v] = ¿hay camino de alex a v?
	std::vector<bool> visitLucas; // visitLucas[v] = ¿hay camino de lucas a v?
	std::vector<bool> visitTrabajo; // visitTrabajo[v] = ¿hay camino de trabajo a v?

	std::vector<int> distAlex; // distAlex[v] = aristas en el camino v alex
	std::vector<int> distLucas;// distLucas[v] = aristas en el camino v lucas
	std::vector<int> distTrabajo; // distTrabajo[v] = aristas en el camino v trabajo

	int trabajo;
	int casaAlex;
	int casaLucas;
	int numIntersecciones;
	int costeViaje;

	void bfs(Grafo const& g, vector<bool>& visit, vector<int>& dist, int s) {
		std::queue<int> q;
		dist[s] = 0; visit[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					dist[w] = dist[v] + 1; visit[w] = true;
					q.push(w);
				}
			}
		}
	}

	void setCosteViaje() {
		costeViaje = distTrabajo[casaAlex] + distTrabajo[casaLucas];
		for (int v = 0; v < numIntersecciones; v++)
		{
			if (v != trabajo) {
				costeViaje = min(
					costeViaje,
					distAlex[v] + distLucas[v] + distTrabajo[v]
				);// minimo entre juntar caminos en v o mantenerse en el anterior. Inicialmente es no juntar caminos
			}
		}
	}

public:
	Peaje(Grafo const& g, int trabajo, int casaAlex, int casaLucas) :
		visitAlex(g.V(), false), visitLucas(g.V(), false), visitTrabajo(g.V(), false),
		distAlex(g.V()), distLucas(g.V()), distTrabajo(g.V()),
		trabajo(trabajo), casaAlex(casaAlex), casaLucas(casaLucas), numIntersecciones(g.V()) {

		bfs(g, visitLucas, distLucas, casaLucas);
		bfs(g, visitAlex, distAlex, casaAlex);
		bfs(g, visitTrabajo, distTrabajo, trabajo);

		setCosteViaje();
	}

	int getCosteViaje() {
		return costeViaje;
	}
};

bool resuelveCaso() {
	int N, C, A, L, T;
	cin >> N >> C >> A >> L >> T;

	if (!std::cin)
		return false;

	Grafo g(N);
	for (int i = 0; i < C; i++)
	{
		int v, w;
		cin >> v >> w;
		g.ponArista(v-1, w-1);
	}

	Peaje peaje(g, T-1, A-1, L-1);

	cout << peaje.getCosteViaje() << "\n";

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