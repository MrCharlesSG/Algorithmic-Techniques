
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
