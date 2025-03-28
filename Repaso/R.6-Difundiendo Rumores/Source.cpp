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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

const int INF = 10000000;

class Sobornos {
private:
	std::vector<bool> visit; // visit[v] = �hay camino de s a v?
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