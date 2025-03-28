
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "DigrafoValorado.h"
#include "IndexPQ.h"

using namespace std;


template <typename Valor>
class Caminos {
public:
	Caminos(DigrafoValorado<Valor> const& g, int orig) : distBfs(g.V(), 0), caminoSizeDijstra(g.V(), 0), distDijstra(g.V(), INF), visit(g.V(), false) {
		bfs(g, orig); 
		dijkstra(g, orig);
	}


	bool hayCamino(int v) const { return visit[v]; }
	int  distanciaMinima(int v) { return distDijstra[v]; }
	bool esCaminoMinimoCorto(int v) { return distBfs[v] == caminoSizeDijstra[v]; }

private:
	const Valor INF = 1000000;
	std::vector<Valor> distDijstra;
	std::vector<int> caminoSizeDijstra;
	std::vector<int> distBfs;
	vector<bool> visit;

	void dijkstra(DigrafoValorado<Valor> const& g, int origen) {
		IndexPQ<Valor> pq(g.V());
		distDijstra[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v))
				relajar(a, pq);
		}
	}


	void relajar(AristaDirigida<Valor> a, IndexPQ<Valor>& pq) {
		int v = a.desde(), w = a.hasta();
		if (distDijstra[w] > distDijstra[v] + a.valor()) {
			distDijstra[w] = distDijstra[v] + a.valor(); 
			caminoSizeDijstra[w] = caminoSizeDijstra[v] + 1;
			pq.update(w, distDijstra[w]);
		}
		else if (distDijstra[w] == distDijstra[v] + a.valor() && caminoSizeDijstra[w] > caminoSizeDijstra[v] + 1){
			caminoSizeDijstra[w] = caminoSizeDijstra[v] + 1;
		}
	}

	void bfs(DigrafoValorado<Valor> const& g, int origen) {
		std::queue<int> q;
		distBfs[origen] = 0; visit[origen] = true;
		q.push(origen);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto w : g.ady(v)) {
				if (!visit[w.hasta()]) {
					distBfs[w.hasta()] = distBfs[v] + 1; visit[w.hasta()] = true;
					q.push(w.hasta());
				}
			}
		}
	}
};





/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;

    if (!cin) return false;
    
	DigrafoValorado<int> g(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.ponArista({ a-1, b-1, c });
        g.ponArista({ b-1, a - 1, c });
    }

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		Caminos<int> cam(g, a-1);

		if (cam.hayCamino(b-1)) {
			cout << cam.distanciaMinima(b-1);
			if (cam.esCaminoMinimoCorto(b-1)) {
				cout << " SI\n";
			}
			else {
				cout << " NO\n";
			}
		}
		else {
			cout << "SIN CAMINO\n";
		}
	}
	cout << "---\n";

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
