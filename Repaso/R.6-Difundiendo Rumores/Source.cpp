/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
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

const int INF = 10000000;

class Sobornos {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	int coste;

	int bfs(Grafo const& g, vector<int> const& costes, int s) {
		std::queue<int> q;
		visit[s] = true;
		q.push(s);
		int minimo = INF;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			minimo = min(minimo, costes[v]);
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					visit[w] = true;
					q.push(w);
				}
			}
		}
		return minimo;
	}
public:
	Sobornos(Grafo const& g, vector<int> const& costes) : visit(g.V(), false), coste(0) {
		for (int i = 0; i < g.V(); i++)
		{
			if (!visit[i]) {
				coste += bfs(g, costes, i);
			}
		}
	}
	
	int getCosteTotal() {
		return coste;
	}

};


bool resuelveCaso() {

	int N, M;
	cin >> N >> M;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> costes(N);
	for (int i = 0; i < N; i++)
	{
		cin >> costes[i];
	}

	Grafo g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		g.ponArista(a - 1, b - 1);
	}

	Sobornos s(g, costes);
	cout << s.getCosteTotal() << "\n";
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