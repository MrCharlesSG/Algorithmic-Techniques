
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;


class Tarzan {
public:
    Tarzan(GrafoValorado<int> const& g): longMin(0) {
        init(g);
    }

    void printSol() {
        if (longMin == -1) {
            cout << "Imposible\n";
        }
        else {
            cout << longMin << "\n";
        }
    }

private:
    int longMin;

    void init(GrafoValorado<int> const& g) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                if (cjtos.num_cjtos() == 1) {
                    longMin = a.valor();
                    break;
                }
            }
        }

        if (cjtos.num_cjtos() != 1) {
            longMin = -1;
        }
    }

};

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int N, M;
    cin >> N >> M;

    if (!cin) return false;
    
    GrafoValorado<int> gv(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gv.ponArista({ a-1, b-1, c });
    }
    
    Tarzan tr(gv);
    tr.printSol();
    


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
