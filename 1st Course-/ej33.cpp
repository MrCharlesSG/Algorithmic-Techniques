//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> f;
typedef vector<f> funcionarios;
typedef vector<bool> marca;

void ministerio(const funcionarios& fs, marca& m, const f& acum, int k, const int n, int& min, int& actual) {
    /*
    i => tarea
    k => funcionario
    */
    for (int i = 0; i < n; i++)
    {
        //Si tarea no cojida
        if (!m[i]) {
            //elijo
            actual += fs[k][i];
            m[i] = true;

            //Caso Base
            if (k == n - 1) {
                if (min > actual) {
                    min = actual;
                }
            }
            //caso recursivo, sigo elijiendo
            else {
                //Si juntando el mejor caso del siguiente, el actual no mejora no entro en llamada
                if (acum[k + 1] + actual <= min) {
                    ministerio(fs, m, acum, k + 1, n, min, actual);
                }
            }
            //Deselijo
            actual -= fs[k][i];
            m[i] = false;
        }
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0)
        return false;
    f aux(n), acum(n);
    marca m(n);
    funcionarios fs(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            cin >> aux[j];
            if (i == 0)
                acum[j] = aux[j];
            else
                acum[j] = acum[j] > aux[j] ? aux[j] : acum[j];
        }

        fs[i] = aux;
        m[i] = false;


    }
    for (int i = n - 2; i >= 0; i--)
        acum[i] += acum[i + 1];
    int actual = 0;
    int min = 10000 * n + 1;
    ministerio(fs, m, acum, 0, n, min, actual);
    cout << min << endl;
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
