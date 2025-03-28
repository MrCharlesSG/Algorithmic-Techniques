/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
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

class Equipos {
private:
	std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
	vector<int> equipos;
	bool esPosible;

	void bfs(Grafo const& g, int s) {
		std::queue<int> q;
		visit[s] = true;
		equipos[s] = s;
		q.push(s);
		int lider1 = s;
		int lider2 = lider1;
		while (!q.empty() && esPosible) {
			int v = q.front(); q.pop();
			int liderDeV = equipos[v];
			for (int w : g.ady(v)) {
				if (!visit[w]) {
					visit[w] = true;
					if (lider1 == lider2) { //todavia no hay lider 2
						lider2 = w;
						equipos[w] = w;
					}
					else { //unir w al otro conjunto
						if (lider1 == liderDeV) {
							equipos[w] = lider2;
						}
						else {
							equipos[w] = lider1;
						}
					}
					q.push(w);
				}
				else if(equipos[w] == equipos[v]) { // si esta visitado hay q comprobar que v y w esten en distintos conjuntos
					esPosible = false;
				}
			}
		}
	}

public:
	Equipos(Grafo const& g) : visit(g.V(), false), esPosible(true), equipos(g.V(), -1) {
		
		for (int v = 0; v < g.V(); v++)
		{
			if (!visit[v]) {
				bfs(g, v);
			}
		}
		
	}
	// ¿hay camino del origen a v?
	bool sePuedenAsignarEquipos() const {
		return esPosible;
	}
};


bool resuelveCaso() {
	int A, R;
	cin >> A >> R;
	if (!cin) return false;
	
	Grafo g(A);
	for (int i = 0; i < R; i++)
	{
		int a, b;
		cin >> a >> b;
		g.ponArista(a-1, b-1);
	}

	Equipos e(g);

	if (e.sePuedenAsignarEquipos()) cout << "SI\n";
	else cout << "NO\n";
	
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