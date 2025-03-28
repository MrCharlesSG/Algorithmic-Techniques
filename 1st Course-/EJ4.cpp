#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int numUnos(vector<int> v, int j) {
    int i = 0, n = 0;
    while (i < j) {
        if (v[i] == 1)
        {
            n++;
        }
        i++;
    }
    return n;
}
int numCeros(vector<int> v, int j) {
    int i = 0, n = 0;
    while (i < j) {
        if (v[i] == 0)
        {
            n++;
        }
        i++;
    }
    return n;
}
int equilibrio(vector<int> v) {
    int size = v.size() - 1;

    while (size >= 0)
    {
        int resta = abs(numCeros(v, size + 1) - numUnos(v, size + 1));
        if (resta == 0) {
            return size;
        }
        else {
            size -= resta;
        }
    }
    return -1;
}

void resuelveCaso() {
    int num, c;
    cin >> num;
    vector<int> v;
    if (num > 0)
    {
        num--;
        while (num >= 0)
        {
            cin >> c;
            v.push_back(c);
            num--;
        }
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