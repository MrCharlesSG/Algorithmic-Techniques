
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

int numAplastamientos(vector<int> rivales, vector<int> broncos, int N) {
    int i = 0, suma = 0;
    while (i < N && rivales[i] < broncos[i]) {
        suma += broncos[i] - rivales[i];
        i++;
    }
    return suma;
}


bool resuelveCaso() {
    int N;
    cin >> N;

    if (!cin || N == 0) return false;

    vector<int> rivales(N);
    vector<int> broncos(N);

    for (int i = 0; i < N; i++)
    {
        cin >> rivales[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> broncos[i];
    }
    sort(broncos.begin(), broncos.end(), greater<int>());
    sort(rivales.begin(), rivales.end());
    cout << numAplastamientos(rivales, broncos, N) << "\n";
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
