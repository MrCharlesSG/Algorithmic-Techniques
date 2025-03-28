
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

struct Festival {
    int grupos;
    int precio;

    Festival() {}
};

int numGrupos(vector<Festival> const& festivales, int N, int P) {
    vector<int> grupos(P + 1, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = P; j >= festivales[i - 1].precio; j--) {
            grupos[j] = max(grupos[j], grupos[j - festivales[i - 1].precio] + festivales[i - 1].grupos);
        }
    }
    return grupos[P];
}



bool resuelveCaso() {
    int N, P;
    cin >> P >> N;
    if (!cin) return false;

    vector<Festival> festivales(N);
    for (int i = 0; i < N; i++)
    {
        cin >> festivales[i].grupos >> festivales[i].precio;
    }

    cout << numGrupos(festivales, N, P) << "\n";

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
