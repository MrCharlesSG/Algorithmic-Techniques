//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> v;

struct Sol {
    int maxL, numL;
    v eles;
};

Sol heidi(const v& a, const int n, const int l) {
    Sol s;
    s.maxL = 0;
    s.numL = 0;
    int i = n - 1, maxd = -1, current = 0, j = 0;
    while (i >= 0)
    {
        if (maxd <= a[i]) {
            if (i != n - 1 && a[i] == a[i + 1]) {
                current++;
            }
            else {
                if (current >= l) {
                    s.numL++;
                    s.eles.push_back(i + current);
                    if (current > s.maxL) {
                        s.maxL = current;
                    }
                }
                current = 1;
            }
            maxd = a[i];
        }
        else {
            if (current >= l) {
                s.numL++;
                s.eles.push_back(i + current);
                if (current > s.maxL) {
                    s.maxL = current;
                }
            }
            current = 0;
        }
        i--;
    }
    if (current >= l) {
        s.numL++;
        s.eles.push_back(current - 1);
        if (current > s.maxL) {
            s.maxL = current;
        }
    }
    return s;

}

bool resuelveCaso() {
    int n, l;
    cin >> n >> l;
    if (!cin) {
        return false;
    }
    else {
        int aux;
        v a;
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            a.push_back(aux);
        }

        Sol s = heidi(a, n, l);
        cout << s.maxL << " " << s.numL;
        for (int i = 0; i < s.numL; i++)
        {
            cout << " " << s.eles[i];
        }
        cout << "\n";

        return true;
    }
}

/*
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
*/

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

