
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


class Calculator {
public:
    Calculator() {

    }

    int getSteps(int init, int fin) {
        return calc(init, fin);
    }

private:
    const int MAX = 10000;
    const int INF = 1000000000;

    int next(int num, int i) {
        switch (i)
        {
        case 0: return (num + 1) % MAX;
        case 1: return (num * 2) % MAX;
        case 2: return (num / 3);
        default:
            break;
        }
    }

    int calc(int init, int fin) {
        if (init == fin) {
            return 0;
        }
        vector <int> distances(MAX, INF);
        distances[init] = 0;
        queue<int> q;
        q.push(init);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 3; i++)
            {
                int w = next(v, i);
                if (distances[w] == INF) {
                    distances[w] = distances[v] + 1;
                    if (w == fin) return distances[w];
                    q.push(w);
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

    int init, fin;
    cin >> init >> fin;

    if (!std::cin)  // fin de la entrada
        return false;

    Calculator calculator;

    int steps = calculator.getSteps(init, fin);
    cout << steps << "\n";


    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n

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
