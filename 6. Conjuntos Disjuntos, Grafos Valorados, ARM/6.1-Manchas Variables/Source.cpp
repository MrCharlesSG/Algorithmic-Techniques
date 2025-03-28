
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "ConjuntosDisjuntos.h"

using namespace std;


class Manchas {
public:
    Manchas(vector<string> const& matriz, int C, int F): cj(C*F), C(C), F(F), matriz(matriz),
        uniones{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1},{1, -1}, {1, 0}, {1, 1} } 
    {
        int dimMax = -1;
        //Construir conjuntos
        for (int f = 0; f < F; f++)
        {
            for (int c = 0; c < C; c++) {
                auto aux = matriz[f][c];
                if (aux == '#') {
                    int pos = getPosInCj(c, f);
                    //unir con arriba
                    unirPosiciones(pos, c, f - 1);

                    //unir con izq
                    unirPosiciones(pos, c - 1, f);

                    //unir con diag sup-izq
                    unirPosiciones(pos, c - 1, f - 1);

                    dimMax = max(cj.cardinal(pos), dimMax);
                }
            }
        }

        respuestas.push_back(dimMax);
    }

    void nuevaMancha(int c, int f) {
        int pos = getPosInCj(c, f);
        matriz[f][c] = '#';

        unirAdyacentes(c, f);

        int dimMax = respuestas[respuestas.size() - 1];
        dimMax = max(cj.cardinal(pos), dimMax);
        respuestas.push_back(dimMax);
    }

    vector<int> getRespuestas() {
        return respuestas;
    }

private:
    ConjuntosDisjuntos cj;
    int C;
    int F;
    vector<int> respuestas;
    vector<string> matriz;
    vector<pair<int, int>> uniones;

    int getPosInCj(int c, int f) {
        return f * C + c;
    }

    void unirAdyacentes(int c, int f) {
        int pos = getPosInCj(c, f);

        for (pair<int, int> par : uniones) {
            int newCol = c + par.second, newFil = f + par.first;
            unirPosiciones(pos, newCol, newFil);
        }


    }

    void unirPosiciones(int pos, int c, int f) {
        if (f >= 0 && c >= 0 && f < F && c < C && matriz[f][c] == '#') {
            int otherPos = getPosInCj(c, f);
            if (!cj.unidos(pos, otherPos)) {
                cj.unir(pos, otherPos);
            }
        }
    }

};

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
    int C, F;
    cin >> F >> C;

    if (!cin) return false;

    vector<string> matriz(F);
    for (int i = 0; i < F; i++)
    {
        string str;
        cin >> str;
        matriz[i] = str;
    }

    int N;
    cin >> N;
    Manchas manchas(matriz, C, F);
    for (int i = 0; i < N; i++)
    {
        int c, f;
        cin >> f >> c;
        manchas.nuevaMancha(c - 1, f - 1);
    }
    vector<int> respuestas = manchas.getRespuestas();
    for (int resp :respuestas)
    {
        cout << resp << " ";
    }

    cout << "\n";       
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
