#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int numUnos(vector<int> v, int j) {
    int i = 0, n = 0;
    while ( i < j) {
        if (v[i]==1)
        {
            n++;
        }
        i++;
    }
    return n;
}
int numCeros(vector<int> v, int j) {
    int i = 0, n = 0;
    while (i<j) {
        if (v[i] == 0)
        {
            n++;
        }
        i++;
    }
    return n;
}
int equilibrio(vector<int> v) {
    int i=v.size()-1;
    bool encontrado = false, hayCero=false;
    while (i>=0 && !encontrado)
    {
       if (numCeros(v, i + 1) == numUnos(v, i + 1)) {
           return i ;
       }
       if (v[i] == 0 || v[i] == 1) {
           hayCero = true;
       }
       i--;
    }
    if (!encontrado && hayCero) {
        return -1;
    }
    else
        return v.size();
}

void resuelveCaso() {
    int num, c, contU = 0, contC = 0, i = 0, result=-2;
    cin >> num;
    vector<int> v;
    while (i < num)
    {
        cin >> c;
        v.push_back(c);
        i++;
    }
    cout << equilibrio(v) << endl;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}