
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


class TTL {
private:
	Grafo configuracion;
	int N;

	int numNodosAlcanzablesMasCortos(vector<int>& dist, int s, int ttl) {
		vector<bool> visit(N, false);
		std::queue<int> q;
		visit[s] = true;
		q.push(s);
		int numAlcancables = 1;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			if (dist[v] < ttl) {
				for (int w : configuracion.ady(v)) {
					if (!visit[w]) {
						dist[w] = dist[v] + 1; visit[w] = true;
						q.push(w);
						numAlcancables++;
					}
				}
			}
		}
		return numAlcancables;
	}

public:
	TTL(Grafo const& g) : configuracion(g), N(g.V()) {
		
	}

	int getNumNodosAlcanzables(int v, int ttl) {
		vector<int> dist(N, 0);
		int n = numNodosAlcanzablesMasCortos(dist, v, ttl);
		return N - n;
	}
};

bool resuelveCaso() {
	int N, C;
	cin >> N >> C;

	if (!std::cin)
		return false;

	Grafo g(N);
	for (int i = 0; i < C; i++)
	{
		int v, w;
		cin >> v >> w;
		g.ponArista(v-1, w-1);
	}

	vector<int> respuestas;
	TTL timeToLive(g);
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int v, ttl;
		cin >> v >> ttl;
		respuestas.push_back(timeToLive.getNumNodosAlcanzables(v-1, ttl));
	}

	for (int respuesta: respuestas)
	{
		cout << respuesta << "\n";
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