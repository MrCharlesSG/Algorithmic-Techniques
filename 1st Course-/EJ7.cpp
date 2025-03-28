#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void resuelveCaso() {
    int num, alt, cI = -1, dim = 0, i = 0, c, cif = -1;
    bool enInt = false;
    cin >> num >> alt;
    int cdf = num-1;
    while (i < num)
    {
        cin >> c;
        if (c >= alt && !enInt) {
            enInt = true;
            cI = i;
            
        }
        if (c < alt && enInt) {
            enInt = false;
            if (i - cI - 1 > dim) {
                cdf = i - 1;
                cif = cI;
                dim = cdf - cif;
            }
        }
        i++;
    }
    if (cif == -1) {
        cout << cI << " " << cdf << endl;
    }else
        cout << cif << " " << cdf << endl;
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