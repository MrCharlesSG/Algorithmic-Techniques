//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct sol {
    int total;
    int maxIzq;
};

sol resuelve(int n, int minDch, int pos) {
    if (n < 10) {
        return { n * 3 + minDch, n };
    }
    else {
        int cifra = n % 10;
        sol res = resuelve(n / 10, cifra < minDch ? cifra : minDch, pos + 1);
        if (pos % 2 == 0)
            res.total += cifra * 2 + res.maxIzq;
        else
            res.total += cifra * 3 + minDch;
        res.maxIzq = cifra > res.maxIzq ? cifra : res.maxIzq;
        return res;
    }
}

void resuelveCaso() {
    int l, n;
    cin >> n;
    cout << resuelve(n, 10, 0).total << endl;
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
