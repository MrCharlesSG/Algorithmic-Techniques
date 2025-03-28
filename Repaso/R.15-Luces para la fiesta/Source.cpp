#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "EnterosInf.h"
using namespace std;


struct Luz {
    int coste;
    int potencia;

    Luz(){}
};


void potencias(vector<Luz> const& luces, int const PMax, int const PMin, int N) {
    vector<EntInf> costes(PMax + 1, Infinito);
    costes[0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = luces[i-1].potencia; j <= PMax; ++j) {
            costes[j] = min(costes[j], costes[j - luces[i - 1].potencia] + luces[i - 1].coste);
        }
    }

    EntInf minimo = Infinito;
    int indice;

    for (int i = PMin; i <= PMax; i++)
    {
        if (costes[i] < minimo) {
            minimo = costes[i];
            indice = i;
        }
    }

    if (minimo != Infinito) {
        cout << minimo << " " << indice<< "\n";
    }
    else {
        cout << "IMPOSIBLE\n";
    }

}

bool resuelveCaso() {
    int N, PMax, PMin;
    cin >> N >> PMax >> PMin;
    if (!cin) return false;

    vector<Luz> luces(N);

    for (int i = 0; i < N; i++)
    {
        int p; 
        cin >> p;
        luces[i].potencia = p;
    }

    for (int i = 0; i < N; i++)
    {
        int c;
        cin >> c;
        luces[i].coste = c;
    }

    potencias(luces, PMax, PMin, N);

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
