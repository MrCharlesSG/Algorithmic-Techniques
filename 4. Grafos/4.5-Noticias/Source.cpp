
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


class Noticias {
private:
	std::vector<bool> visit;
	std::vector<int> origenes; // indice origen con el que esta conectado v, si v == a origenes[v] es el origen
	std::vector<int> cardinal; // indice origen con el que esta conectado v

	int dfs(Grafo const& G, int v, int origen) {
		int card = 1;
		if (!visit[v]) {
			visit[v] = true;
			origenes[v] = origen;
			for (int w : G.ady(v)) {
				if (!visit[w]) {
					card += dfs(G, w, origen);
				}
			}
		}
		else {
			card = cardinal[v];
		}
		return card;
	}
public:
	Noticias(Grafo const& g) : visit(g.V(), false), origenes(g.V()), cardinal(g.V()) {
		for (int i = 0; i < g.V(); i++)
		{
			origenes[i] = i;
		}
		for (int i = 0; i < g.V(); i++)
		{
			cardinal[i] = dfs(g, i, i);
		}
	}

	int getConexiones(int v) {
		return cardinal[origenes[v]];
	}
};

bool resuelveCaso() {
	int N, M;
	cin >> N >> M;

	if (!std::cin)
		return false;

	//vector <int*> vect(N, nullptr);
	Grafo g(N);
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		vector<int> usuarios;
		for (int j = 0; j < n; j++)
		{
			int actual;
			cin >> actual;
			for (int usuario : usuarios)
			{
				g.ponArista(usuario, actual - 1);
			}
			usuarios.push_back(actual - 1);
		}
	}
	Noticias noti(g);
	for (int i = 0; i < N; i++)
	{
		cout << noti.getConexiones(i) << " ";
	}
	cout << "\n";

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