
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"
#include "Matriz.h"

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

struct Tesoro {
    int profundidad;
    int valor;
};

EntInf botin_rec(vector<Tesoro> const& tesoros, int i, int j,
    Matriz<EntInf>& botin) {
    if (botin[i][j] != -1) 
        return botin[i][j];
    if (i == 0 || j == 0) botin[i][j] = 0;
    else if (tesoros[i - 1].profundidad*3 > j)
        botin[i][j] = botin_rec(tesoros, i - 1, j, botin);
    else
        botin[i][j] = max(botin_rec(tesoros, i - 1, j, botin),
            botin_rec(tesoros, i - 1, j - tesoros[i - 1].profundidad * 3, botin)
            + tesoros[i - 1].valor);
    return botin[i][j];
}

pair<EntInf, int> botin(vector<Tesoro> const& tesoros, int T, vector<bool>& sol) {
    int n = tesoros.size();
    Matriz<EntInf> botin(n + 1, T + 1, -1);
    EntInf valor = botin_rec(tesoros, n, T, botin);

    int i = n, j = T;
    sol = vector<bool>(n, false);
    int numTrue = 0;
    while (i > 0 && j > 0) {
        if (botin[i][j] != botin[i - 1][j]) {
            sol[i - 1] = true; j = j - tesoros[i - 1].profundidad * 3; numTrue++;
        }--i;
    }
    return { valor, numTrue };
}



bool resuelveCaso() {
    int T,N;
    cin >> T >> N;
    if (!cin) return false;

    vector<Tesoro> tesoros;
    for (int i = 0; i < N; i++)
    {
        int g, c;
        cin >> g >> c;
        tesoros.push_back({ g, c });
    }

    vector<bool> sol;
    pair<EntInf, int> s = botin(tesoros, T, sol);
    cout << s.first << "\n" << s.second << "\n";
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[i]) {
            cout << tesoros[i].profundidad << " " << tesoros[i].valor << "\n";
        }
    }
    cout << "---\n";

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
