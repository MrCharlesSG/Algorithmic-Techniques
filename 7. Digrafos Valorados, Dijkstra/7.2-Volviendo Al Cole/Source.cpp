
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


class Camino {
public:
    Camino(DigrafoValorado<int> const& g): dist(g.V(), 1000000000), pq(g.V()), anteriores(g.V(), 0) {
        dist[0] = 0;
        anteriores[0] = 1;
        pq.push(0, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }

    void printTotales() {
        cout << anteriores[anteriores.size()-1] << "\n";
    }

private:
    std::vector<int> dist;
    vector<int> anteriores;
    IndexPQ<int> pq;
    const int INF = 1000000000;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor();
            anteriores[w] = anteriores[v];
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor()) {
            anteriores[w] += anteriores[v];
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
    }

    Camino cam(g);
    cam.printTotales();


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
