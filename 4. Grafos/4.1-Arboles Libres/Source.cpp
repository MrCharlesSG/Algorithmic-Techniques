
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <unordered_map>
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


class FreeTree {
private:
	std::vector<bool> visit;
	std::vector<int> ant;
	bool freeTree;
	
	bool dfs(Grafo const& G, int v) {
		visit[v] = true;
		bool hayCiclo = false;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				hayCiclo = dfs(G, w);
			}
			else if(ant[v] != w){
				hayCiclo = true;
			}
			if (hayCiclo) return hayCiclo;
		}
		return hayCiclo;
	}

	bool allConected() {
		for (bool v : visit) {
			if (!v) return false;
		}
		return true;
	}

public:
	FreeTree(Grafo const& g) : visit(g.V(), false), ant(g.V()) {
		bool hayCiclo = dfs(g, 0);
		freeTree = hayCiclo ? false : allConected();
	}

	bool isFreeTree() {
		return freeTree;
	}	
};



bool resuelveCaso() {
    int V, A;
    cin >> V >> A;
    
    if (!cin) return false;

	Grafo g(V);
	for (int i = 0; i < A; i++)
	{
		int c, a;
		cin >> c >> a;
		g.ponArista(c, a);
	}

	FreeTree freeTree(g);
	if (freeTree.isFreeTree())
		cout << "SI\n";
	else
		cout << "NO\n";

   
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
