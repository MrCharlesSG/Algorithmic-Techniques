
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
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

const string kevinBacon = "KevinBacon";

class KevinBacon {
public:
	KevinBacon(Grafo const& g) : visit(g.V(), false), dist(g.V()) {
		bfs(g);
	}

	void printKevinBacon(string actor, int indexOfActor) {
		if (visit[indexOfActor]) {
			cout << actor << " " << dist[indexOfActor] << "\n";
		}
		else
		{
			cout << actor + " INF\n";
		}
	}


private:
	std::vector<bool> visit; 
	std::vector<int> dist; 

	void bfs(Grafo const& g) {
		std::queue<int> q;
		dist[0] = 0; visit[0] = true;
		q.push(0);
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
};

bool resuelveCaso() {
	int P;
	cin >> P;

	if (!std::cin)
		return false;

	vector<string> indexActor;
	unordered_map<string, int> actorIndex;
	indexActor.push_back(kevinBacon);
	actorIndex[kevinBacon] = indexActor.size()-1;
	vector<vector<string>> peliculas;
	string titulo;
	for (int i = 0; i < P; i++)
	{
		int N;
		cin >> titulo >> N;
		vector<string> actores(N);
		for (int i = 0; i < N; i++)
		{
			cin >> actores[i];
			string actor = actores[i];

			if (actorIndex.count(actor) == 0) {
				indexActor.push_back(actor);
				actorIndex[actor] = indexActor.size() - 1;
			}
		}
		peliculas.push_back(actores);
	}
	Grafo g(indexActor.size());
	for (vector<string> actores: peliculas)
	{
		for (int a = 0; a < actores.size(); a++)
		{
			for (int o = a + 1; o < actores.size(); o++)
			{
				int otherIndex = actorIndex[actores[a]];
				int actualIndex = actorIndex[actores[o]];
				g.ponArista(otherIndex, actualIndex);
			}
		}
	}

	KevinBacon kb(g);
	int N;
	cin >> N;
	vector<string> actores(N);

	for (int i = 0; i < N; i++)
	{
		cin >> actores[i];
	}

	for (string actor: actores)
	{
		kb.printKevinBacon(actor, actorIndex[actor]);
	}
	cout << "---\n";

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