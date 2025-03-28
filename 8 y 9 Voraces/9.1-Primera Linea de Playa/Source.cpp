
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

struct Edificio {
    int inicio;
    int fin;
};

bool operator<(Edificio const& a, Edificio const& b) {
    return a.inicio < b.inicio;
}

int numTuneles(vector<Edificio> const& edificios, int N) {
    int finActual = edificios[0].fin, numTuneles = 1;

    for (int i = 1; i < N; i++)
    {
        if (edificios[i].inicio >= finActual) {
            finActual = edificios[i].fin;
            numTuneles++;
        }
        else if (finActual > edificios[i].fin) {
            finActual = edificios[i].fin;
        }
    }
    return numTuneles;
}

bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin || N == 0) return false;

    vector<Edificio> edificios(N);

    for (int i = 0; i < N; i++)
    {
        cin >> edificios[i].inicio >> edificios[i].fin;
    }

    sort(edificios.begin(), edificios.end());
    cout << numTuneles(edificios, N) << "\n";

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
