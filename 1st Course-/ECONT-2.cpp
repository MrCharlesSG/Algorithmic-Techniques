//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<bool> marca;
typedef vector<vector<int>> matriz;

int resuelve(const arr& v, int i, int n) {
    if (i == n || v[i]%2==1) {
        return v[i];
    }
    else {
        int m = (i + n) / 2;
        int e = m * 2 + v[0];
        if (v[m] == e) {
            return resuelve(v, m + 1, n);
        }
        else {
            return resuelve(v, i, m);
        }
    }
}

bool resuelveCaso() {
    int n, d=1;
    cin >> n;
    if (n==0)
        return false;

    arr v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << resuelve(v, 0, n)<< endl;
    return true;
}

/*
int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinyuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinyuf);
    system("PAUSE");
#endif

    return 0;
}
*/


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinyuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinyuf);
    system("pause");
#endif
    return 0;
}
