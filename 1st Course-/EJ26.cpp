//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matriz;

struct Sol {
    int suma;
    bool esEquilibrada;
};

Sol equilibrada(const matriz& m, int nx, int mx, int ny, int my) {
    //Caso Base
    if (mx - 1 == nx && ny == my - 1) {
        return { m[ny][nx], true };
    }
    else {
        Sol ai, ad, bi, bd;
        int mitadx = mx / 2, mitady = my / 2, mitadnx = nx / 2, mitadny = ny / 2;
        ai = equilibrada(m, nx, mitadx + mitadnx, ny, mitady + mitadny);
        ad = equilibrada(m, mitadnx + mitadx, mx, ny, mitady + mitadny);

        bi = equilibrada(m, nx, mitadx + mitadnx, mitadny + mitady, my);
        bd = equilibrada(m, mitadnx + mitadx, mx, mitadny + mitady, my);
        
        int di = ad.suma * bi.suma, id = ai.suma * bd.suma;
        bool b = ai.esEquilibrada && ad.esEquilibrada && bi.esEquilibrada && bd.esEquilibrada && id == di;
        return { ai.suma * bd.suma, b };
    }
}

void resuelveCaso() {
    int n;
    cin >> n;
    matriz m;
    vector<int> aux(n);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> aux[i];
        }
        m.push_back(aux);
    }
    Sol s = equilibrada(m, 0, n, 0, n);
    if (s.esEquilibrada)
        cout << "SI " << s.suma << endl;
    else
        cout << "NO\n";
   
}


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


/*
int mxin() {

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

*/