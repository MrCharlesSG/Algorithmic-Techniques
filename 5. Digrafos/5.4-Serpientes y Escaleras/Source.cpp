
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
#include "Digrafo.h"

using namespace std;


class Juego {
public:
    Juego(unordered_map<int, int> serpientesYEscaleras, int N, int K) : dist(N* N, N* N), dadoDim(K), visit(N* N, false), tableroFin(N* N - 1) {
        setMinDist(serpientesYEscaleras);
    }

    int const getMinDist() const {
        return dist[tableroFin];
    }


private:
    vector<int> dist;
    vector<bool> visit;
    int tableroFin;
    int dadoDim;

    int setMinDist(unordered_map<int, int> const& serpientesYEscaleras) {
        queue<int> q;
        dist[0] = 0; visit[0] = true;
        q.push(0);
        while (!q.empty())
        {
            int v = q.front(); q.pop();

            for (int d = 1; d <= dadoDim; d++)
            {
                int w = getSig(serpientesYEscaleras, v + d);
                if (w != tableroFin) {
                    if (!visit[w]) {
                        dist[w] = dist[v] + 1;
                        visit[w] = true;
                        q.push(w);
                    }
                    else if (dist[v] + 1 < dist[w]) {
                        dist[w] = dist[v] + 1;
                    }
                }
                else {
                    if (dist[v] + 1 < dist[w]) {
                        dist[w] = dist[v] + 1;
                    }
                    break;
                }
            }
        }
        return dist[tableroFin];
    }

    int getSig(unordered_map<int, int> const& serpientesYEscaleras, int w) {
        if (serpientesYEscaleras.find(w) == serpientesYEscaleras.end()) {
            return w;
        }
        else {
            int next = serpientesYEscaleras.at(w);
            while (serpientesYEscaleras.find(next) != serpientesYEscaleras.end())
            {
                next = serpientesYEscaleras.at(next);
            }
            return next;
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

    int N, K, S, E;
    cin >> N >> K >> S >> E;

    if (N == 0 && K == 0 && S == 0 && E == 0)  // fin de la entrada
        return false;

    unordered_map<int, int> inicioSerpiente;

    // Registrar el inicio de serpientes y escaleras
    for (int i = 0; i < E + S; i++) {
        int inicio, fin;
        cin >> inicio >> fin;
        inicioSerpiente[inicio - 1] = fin - 1;
    }

    Juego juego(inicioSerpiente, N, K);
    cout << juego.getMinDist() << "\n";


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
