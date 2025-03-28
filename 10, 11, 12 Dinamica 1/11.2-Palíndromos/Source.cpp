
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 /*
 *   palindromo (k, l) = numero de letras que habría que añadir de la k a la l
 *
 *   CASO BASE
 *       - palindromo (k, k) = 0 => tenemos dos palabra iguales
 *       - palindromo (k, l) = 0, i k > l => no quedan palabra por revisar
 *
 *   CASO RECURSIVO (k < l)
 *       - las palabra k y l son iguales (palabra[k] == palabra[l]), no se suma
 *           - palindromo (k, l) = palindromo (k+1, l-1)
 *
 *       - las palabra k y l son distintas, minimo entre una menos en la izq o una menos en la derecha mas la letra que hay que sumar
 *           - palindromo (k, l) =  min(palindromo(k+1, l), palindromo(k, l-1)) + 1
 *
 *
 */
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

int palindromo_rec(string const& palabra, int i, int j, Matriz<int>& palindromo) {
    int& res = palindromo[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = 0;
        else if (palabra[i] == palabra[j])
            res = palindromo_rec(palabra, i + 1, j - 1, palindromo);
        else
            res = min(
                palindromo_rec(palabra, i + 1, j, palindromo),
                palindromo_rec(palabra, i, j - 1, palindromo)) + 1;
    }
    return res;
}

void reconstruir(string const& letras, Matriz<int> const& palindromo, int k, int l, string& sol_izq, string& sol_der) {
    if (k > l) return;
    if (k == l) {
        sol_izq.push_back(letras[k]);
    }
    else if (letras[k] == letras[l]) {
        sol_izq.push_back(letras[k]);
        reconstruir(letras, palindromo, k + 1, l - 1, sol_izq, sol_der);
        sol_der.push_back(letras[l]);
    }
    else if (palindromo[k + 1][l] < palindromo[k][l - 1]) {
        sol_izq.push_back(letras[k]);
        reconstruir(letras, palindromo, k + 1, l, sol_izq, sol_der);
        sol_der.push_back(letras[k]);
    }
    else {
        sol_izq.push_back(letras[l]);
        reconstruir(letras, palindromo, k, l - 1, sol_izq, sol_der);
        sol_der.push_back(letras[l]);
    }
}

bool resuelveCaso() {
    string palabra;
    cin >> palabra;
    if (!cin) return false;

    int N = palabra.size();

    Matriz<int> palindromo(N, N, -1);

    int res = palindromo_rec(palabra, 0, N - 1, palindromo);

    string sol_izq = "", sol_der = "";
    reconstruir(palabra, palindromo, 0, palabra.length() - 1, sol_izq, sol_der);

    cout << res << " " << sol_izq + sol_der << "\n";

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
