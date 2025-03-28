#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;

struct Actividad {
    int ini;
    int fin;

    Actividad(int i, int f) : ini(i), fin(f) {}
};

bool operator<(Actividad const& a, Actividad const& b) {
    return a.ini < b.ini;
}

int numCompaneros(vector<Actividad> const& actividades, int N) {
    int cont = 0;
    PriorityQueue<int> finales;
    finales.push(0);
    for (Actividad actividad : actividades) {
        if (finales.top() > actividad.ini) {
            cont++;
        }
        else {
            finales.pop();
        }
        finales.push(actividad.fin);
    }
    return cont;
}


bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin || N==0) return false;

    vector<Actividad> actividades;

    for (int i = 0; i < N; i++)
    {
        int ini, f;
        cin >> ini >> f;
        actividades.push_back({ ini, f });
    }

    sort(actividades.begin(), actividades.end());

    cout << numCompaneros(actividades, N) << "\n";

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
