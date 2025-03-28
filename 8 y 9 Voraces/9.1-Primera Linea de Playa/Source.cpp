
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
