
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
        dg.ponArista(a, b);
    }

    Digrafo ig = dg.inverso();
    int sumidero = -1;

    for (int i = 0; i < N && sumidero == -1; i++)
    {
        vector<int> salientes = dg.ady(i), entrantes = ig.ady(i);
        if (salientes.size() == 0 && entrantes.size() == N - 1) {
            sumidero = i;
        }
    }

    if (sumidero != -1) {
        cout << "SI " << sumidero << "\n";
    }else{
        cout << "NO\n";
    }

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
