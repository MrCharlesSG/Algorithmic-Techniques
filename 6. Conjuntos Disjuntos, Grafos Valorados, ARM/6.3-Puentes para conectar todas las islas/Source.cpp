
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


class Islas {
public:
    Islas(GrafoValorado<int> const& gv): coste(0), numIslasRecorridas(0), numIslasTotal(gv.V()){
        PriorityQueue<Arista<int>> pq(gv.aristas());
        ConjuntosDisjuntos cjtos(numIslasTotal);
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                numIslasRecorridas++;
                coste += a.valor();
                if (numIslasRecorridas == numIslasTotal - 1) break;
            }
        }
    }

    void printVeredict() {
        if (numIslasRecorridas == numIslasTotal-1) {
            cout << coste << "\n";
        }
        else {
            cout << "No hay puentes suficientes\n";
        }
    }

private:
    int coste;
    int numIslasRecorridas;
    int numIslasTotal;
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
    int I, P;
    cin >> I >> P;

    if (!cin) return false;
    
    GrafoValorado<int> gv(I);
    for (int i = 0; i < P; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gv.ponArista({ a-1, b-1, c });
    }
    
    Islas islas(gv);
    islas.printVeredict();


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
