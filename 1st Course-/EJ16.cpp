//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<bool> marca;
typedef vector<vector<int>> matriz;


int complementario(int n) {
    //Caso Base
    if (n < 10) {
        return 9 - n;
    }
    else {
        int c = n % 10;
        int r = complementario(n / 10);
        return r * 10 + 9 - c;
    }
}

struct tsolI {
    int s, d;
};

tsolI complemnetarioInverso(int n) {
    //Caso Base
    if (n < 10) {
        return { 9 - n, 10 };
    }
    else {
        int c = 9 - n % 10;
        tsolI r = complemnetarioInverso(n / 10);
        return { c * r.d + r.s, r.d * 10 };
    }
}

void resuelveCaso() {
    int n, d = 1;
    cin >> n;

    cout << complementario(n) << " " << complemnetarioInverso(n).s << endl;
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