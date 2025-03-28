
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "EnterosInf.h"
#include "Matriz.h"
#include <unordered_map>

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

EntInf Floyd(Matriz<EntInf> const& G, int P, int R) {
    Matriz<EntInf> C = G;
    for (int k = 0; k < P; ++k) {
        for (int i = 0; i < P; ++i) {
            for (int j = 0; j < P; ++j) {
                auto temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) {
                    C[i][j] = temp;
                }
            }
        }
    }
    EntInf max = 0;
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            
            if (max < C[i][j]) {
                max = C[i][j];
            }
        }
    }

    return max;
}



int getIndex(unordered_map<string, int>& nombreIndice, vector<string>& indiceNombre, string const& str, Matriz<EntInf>& G) {
    auto inMap = nombreIndice.find(str);
    int index;
    if (inMap != nombreIndice.end()) {
        index = inMap->second;
    }
    else {
        indiceNombre.push_back(str);
        index = indiceNombre.size()-1;
        nombreIndice[str] = index;
    }
    return index;
}

bool resuelveCaso() {
    int P, R;
    cin >> P >> R;
    if (!cin) return false;

    unordered_map<string, int> nombreIndice;
    vector<string> indiceNombre;
    Matriz<EntInf> G(P, P, Infinito);
    for (int i = 0; i < P; i++)
    {
        G[i][i] = 0;
    }
    for (int i = 0; i < R; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        
        int index1 = getIndex(nombreIndice, indiceNombre, str1, G),
            index2 = getIndex(nombreIndice, indiceNombre, str2, G);
        G[index1][index2] = 1;
        G[index2][index1] = 1;
    }
    EntInf max = Floyd(G, P, R);
    if (max == Infinito) {
        cout << "DESCONECTADA\n";
    }
    else {
        cout << max << "\n";
    }
    
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
