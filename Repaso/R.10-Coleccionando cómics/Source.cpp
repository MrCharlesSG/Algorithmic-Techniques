#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

const int INF = 1000000000;

int mejorPosicionEnCola(vector<vector<int>> const& colas, int numComics, int minimo, int numColas) {
    vector<int> comic(numComics+1, INF);
    vector<int> ultimoIndiceColas(numColas);

    for (int i = 0; i < numColas; i++)
    {
        ultimoIndiceColas[i] = colas[i].size()-1;
    }

    for (int i = 1; i <= numComics; i++)
    {
        int minimoColas = INF, indiceMinimo = -1;
        for (int k = 0; k < numColas; k++) {
            if (ultimoIndiceColas[k] >= 0 && minimoColas > colas[k][ultimoIndiceColas[k]]) {
                minimoColas = colas[k][ultimoIndiceColas[k]];
                indiceMinimo = k;
            }
        }
        
        comic[i] = min(comic[i - 1], minimoColas);
        if (comic[i] == minimo) return i;
        ultimoIndiceColas[indiceMinimo]--;
    }

    for (int i = 1; i <= numComics; i++)
    {
        if (comic[i] == comic[numComics]) return i;
    }
    return numComics;
}

struct Comic {
    int id;
    int cola;

    Comic() {}
    Comic(int id, int cola):id(id), cola(cola) {}
};

bool operator<(Comic const& a, Comic const& b) {
    return a.id < b.id;
}

int mejorPosicionEnCola2(vector<vector<Comic>> & colas, int numComics, int numColas) {
    PriorityQueue<Comic> primeros;
    for (int i = 0; i < numColas; i++)
    {
        primeros.push(colas[i][colas[i].size() - 1]);
        colas[i].pop_back();
    }

    int indiceMinimo = -1, minimo = INF;

    for (int i = 1; i <= numComics  && !primeros.empty(); i++)
    {
        Comic prim = primeros.top(); primeros.pop();
        if (prim.id < minimo) {
            indiceMinimo = i;
            minimo = prim.id;
        }
        int sig = colas[prim.cola].size() - 1;
        if (sig >= 0) {
            primeros.push(colas[prim.cola][sig]);
            colas[prim.cola].pop_back();
        }
    }

    return indiceMinimo;
}


bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin) return false;

    int minimo = INF;
    int numComics=0;
	
    vector<vector<Comic>> colas(N);

    for (int n = 0; n < N; n++)
    {
        int K;
        cin >> K;
        numComics += K;
        for (int i = 0; i < K; i++)
        {
            int aux;
            cin >> aux;
            minimo = min(aux, minimo);
            colas[n].push_back({ aux , n});
        }
    }

    cout << mejorPosicionEnCola2(colas, numComics, N)<< "\n";


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
