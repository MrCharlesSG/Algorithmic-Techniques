
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
