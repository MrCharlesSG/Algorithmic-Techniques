
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

using namespace std;


class Camiones {
public:
    Camiones(GrafoValorado<int> const & gv) : gv(gv), visit(gv.V()) {

    }

    bool llegaCamion(int a, int b, int u) {
        for (int i = 0; i < gv.V(); i++)
        {
            visit[i] = false;
        }
        dfs(b, u);
        return visit[a];
    }

private:
    GrafoValorado<int> const gv;
    vector<bool> visit;

    void dfs(int v, int umbral) {
        visit[v] = true;
        for (auto a : gv.ady(v)) {
            if (a.valor() >= umbral) {
                int w = a.otro(v);
                if (!visit[w])
                    dfs(w, umbral);
            }
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
    int V, E;
    cin >> V >> E;

    if (!cin) return false;

    GrafoValorado<int> gv(V);
    for (int i = 0; i < E; i++)
    {
        int a, b, u;
        cin >> a >> b >> u;
        gv.ponArista({ a-1, b-1, u });
    }

    Camiones cam(gv);
    int K;
    cin >> K;
    vector<bool> respuestas(K);
    for (int i = 0; i < K; i++)
    {
        int a, b, u;
        cin >> a >> b >> u;
        respuestas[i] = cam.llegaCamion(a-1, b-1, u);
    }

    for (bool respuesta: respuestas)
    {
        if (respuesta) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }
    }

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
