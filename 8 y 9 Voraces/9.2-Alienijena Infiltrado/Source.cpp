
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

struct Intervalo {
    int inicio;
    int fin;
};

bool operator<(Intervalo const& a, Intervalo const& b) {
    return a.inicio < b.inicio || a.inicio == b.inicio && a.fin < b.fin;
}

int numIntervalos(vector<Intervalo> intervalos, int C, int F) {
    int fin = C, i = 0, numIntervalos=0;
    while (fin < F && i < intervalos.size() && numIntervalos != -1) {
        int mejorFin = fin;
        while (i < intervalos.size() && fin >= intervalos[i].inicio) {
            mejorFin = max(mejorFin, intervalos[i].fin);
            i++;
        }
        numIntervalos = mejorFin != fin ? numIntervalos + 1 : -1;
        fin = mejorFin;
    }
    return fin >= F ? numIntervalos : -1;
}

bool resuelveCaso() {
    int C, F,N;
    cin >> C >> F>>N;
    if (!cin || N == 0 && C ==0 && F==0) return false;

    vector<Intervalo> intervalos(N);

    for (int i = 0; i < N; i++)
    {
        cin >> intervalos[i].inicio >> intervalos[i].fin;
    }

    sort(intervalos.begin(), intervalos.end());
    int s = numIntervalos(intervalos, C, F);
    if (s == -1) 
        cout << "Imposible" << "\n";
    else
        cout << s << "\n";

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
