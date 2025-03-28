#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
using namespace std;

const int INF = 1000000000;

Matriz<int> getCostes(Matriz<int> const& C, int N) {
    Matriz<int> indi = C;

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                indi[i][j] = min(indi[i][j], indi[i][k] + indi[k][j]);
            }
        }
    }

    return indi;
    
}



bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin || N==0) return false;
	
    Matriz<int> C(N, N, INF);
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i + 1; j < N; j++) {
            cin >> C[i][j];
        }
    }

    Matriz<int> indi = getCostes(C, N);

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++) {
            cout << indi[i][j] << " ";
        }
        cout << "\n";
    }

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
