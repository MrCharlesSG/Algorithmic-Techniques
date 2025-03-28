//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> v;

/*
{0<=n<=100 && n== a.size}
int pistas(v a, int n} return m
{m = {max #i : 0 < i < n : a[i-1] >= a[i]}

COSTE: O(n)
*/

int pistas(const v& a, const int n) {
    int maxLength = n == 1 ? 1 : 0, current = n == 0 ? 0 : 1, i = 1;
    while (i < n)
    {
        //Si hay descenso
        if (a[i - 1] >= a[i]) {
            current++;
        }
        //Si cambio de pista
        else {
            //actualizar maximo
            if (maxLength < current)
                maxLength = current;
            current = 1;
        }
        i++;
    }
    if (maxLength < current)
        maxLength = current;
    return maxLength;
}

void resuelveCaso() {
    int n;
    cin >> n;
    if (n < 0) {

    }
    else {
        int aux;
        v a;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a.push_back(aux);
        }

        cout << pistas(a, n) << "\n";


    }
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

/*
int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
*/
