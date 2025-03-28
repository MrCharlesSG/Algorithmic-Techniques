
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


class Aeropuertos {
public:
    Aeropuertos(GrafoValorado<int> const& g, const int costeAeropuerto): costeAeropuerto(costeAeropuerto){
        init(g);
    }

    void printSol() {
        cout << costeTotal << " " << numAeropuertos << "\n";
    }

private:
    int costeAeropuerto;
    int costeTotal;
    int numAeropuertos;

    void init(GrafoValorado<int> const& g) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        ConjuntosDisjuntos cjtos(g.V());
        int numCiudadesConectadas=0;
        int coste=0;
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w) && a.valor() < costeAeropuerto) {
                cjtos.unir(v, w);
                coste += a.valor();
                numCiudadesConectadas++;
                if (numCiudadesConectadas == g.V() - 1) {
                    break;
                }
            }
            else if(a.valor() >= costeAeropuerto){
                break;
            }
        }
        numAeropuertos = cjtos.num_cjtos();
        costeTotal = numAeropuertos * costeAeropuerto + coste;
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
    int N, M, A;
    cin >> N >> M >> A;

    if (!cin) return false;
    
    GrafoValorado<int> gv(N);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gv.ponArista({ a-1, b-1, c });
    }
    
    Aeropuertos aer(gv, A);
    aer.printSol();


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
