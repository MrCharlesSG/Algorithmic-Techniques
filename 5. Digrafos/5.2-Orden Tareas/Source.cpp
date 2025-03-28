
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "Digrafo.h"
using namespace std;


class Tareas {
public:
    Tareas(Digrafo const& g) : visit(g.V(), false), apilado(g.V(), false), hayCiclo(false) {
        Digrafo ig = g.inverso();
        for (int i = 0; i < g.V() && !hayCiclo; i++)
        {
            if (!visit[i]) {
                hayCiclo = !dfs(ig, i);
            }
        }
    }

    void printOrden() {
        if (hayCiclo) {
            cout << "Imposible\n";
        }
        else {
            for (int paso : orden)
            {
                cout << paso + 1 << " ";
            }
            cout << "\n";
        }
    }

private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> orden;
    std::vector<bool> apilado;

    bool hayCiclo;

    bool dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                if (!dfs(g, w)) {
                    return false;
                }
            }
            else if (apilado[w]) {
                return false;
            }
        }
        orden.push_back(v);
        apilado[v] = false;
        return true;
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


    Digrafo dg(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        dg.ponArista(a-1, b-1);
    }

    Tareas t(dg);
    t.printOrden();


    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

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
