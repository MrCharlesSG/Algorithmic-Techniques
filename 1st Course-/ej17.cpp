//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<bool> marca;
typedef vector<vector<int>> matriz;

/*
COSTE => 
            { c1 si n<=0;
    T(n) = { 1(T(N/2)) + c si n>0

    T(n) => O(log(n))

*/

int concava(const arr& v, int i, int n) {
    if (i == n - 1) {
        return v[i];
    }
    else {
        int m = (n + i) / 2;
        //Si estamos en la parte creciente
        if (v[m - 1] < v[m]) {
            return concava(v, m, n);
        }
        else {
            return concava(v, i, m);
        }
        //Si estamos en la decreciente
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin || n <= 0)
        return false;
    arr v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << concava(v, 0, n) << endl;
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
