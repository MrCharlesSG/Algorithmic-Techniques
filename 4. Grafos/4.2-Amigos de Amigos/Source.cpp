
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <unordered_map>
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


class Friends {
private:
	std::vector<bool> visit;
	int maxNumFriends;
	
	int getNumFriends(Grafo const& G, int v) {
		visit[v] = true;
		int numFriends = 1;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				numFriends += getNumFriends(G, w);
			}
		}
		return numFriends;
	}

public:
	Friends(Grafo const& g) : visit(g.V(), false), maxNumFriends(0) {
		for (int i = 0; i < visit.size(); i++)
		{
			if (!visit[i]) {
				int numFriends = getNumFriends(g, i);
				maxNumFriends = maxNumFriends < numFriends ? numFriends : maxNumFriends;
			}
		}
	}

	int getMaxNumFriends() {
		return maxNumFriends;
	}
};



void resuelveCaso() {
    int V, A;
    cin >> V >> A;
    

	Grafo g(V);
	for (int i = 0; i < A; i++)
	{
		int c, a;
		cin >> c >> a;
		g.ponArista(c-1, a-1);
	}

	Friends friends(g);
	cout << friends.getMaxNumFriends() << "\n";
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
