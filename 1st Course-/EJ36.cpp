//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<bool> marca;
typedef vector<arr> matriz;

struct sol {
    int sp, pp, si, pi;
    bool estrano;
};

sol estrano(const arr& v, int i, int n) {
    //Caso Base
    if (i == n - 1) {
        int c = v[i];
        //Si par devuelve 1 en producto inpar y 0 en suma inpar y cifra en los demas
        if (c % 2 == 0)
            return { c, c, 0, 1, true };
        else
            return { 0, 1, c, c, true };
    }
    else {
        sol li, ld;
        int m = (i + n) / 2;
        li = estrano(v, i, m);
        ld = estrano(v, m, n);

        int sp, pp, si, pi;
        bool estrano = (li.sp + li.pi <= ld.pp + ld.si) && (li.estrano || ld.estrano);

        sp = li.sp + ld.sp;
        si = li.si + ld.si;
        pp = li.pp * ld.pp;
        pi = li.pi * ld.pi;


        return  { sp, pp, si, pi, estrano };
        
    }
}

void resuelveCaso() {  
    int n;
    cin >> n;
    arr v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (v.size() == 0 || estrano(v, 0, n).estrano)
        cout << "SI\n";
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
*/