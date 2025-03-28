//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<bool> marca;
typedef vector<vector<int>> matriz;

void invernalia(const arr& carros, const arr& caminos, const matriz& calidades, marca& mark,
    const int n, const int m, int& mejor, int& actual, int k, const arr& acum) {
    /*
    k => patrulla
    i => camino
    */
    if (k < n) {
        for (int i = 0; i < m; i++)
        {
            //Si el camino no esta elejido y el carro cabe
            if (!mark[i] && caminos[i] >= carros[k]) {
                //Elejimos
                actual += calidades[k][i];
                mark[i] = true;

                //Caso Base
                if (k == n - 1) {
                    mejor = actual > mejor ? actual : mejor;
                }
                //Caso recursivo
                else {
                    //Mejor caso Posible
                    if (acum[k + 1] + actual > mejor) {
                        invernalia(carros, caminos, calidades, mark, n, m, mejor, actual, k + 1, acum);
                    }
                }
                actual -= calidades[k][i];
                mark[i] = false;
            }
        }

        //Si la mejor opcion pasa por no elejir este

        //Caso Base
        if (k == n - 1) {
            mejor = actual > mejor ? actual : mejor;
        }
        //Caso recursivo
        else {
            //Mejor caso Posible
            if (acum[k + 1] + actual > mejor) {
                invernalia(carros, caminos, calidades, mark, n, m, mejor, actual, k + 1, acum);
            }
        }
    }
}

void resuelveCaso() {
    int n, m;
    cin >> n >> m;
    arr carros(n), caminos(m), aux(m), acum(n);
    marca mark(m);
    matriz calidades(n);
    for (int i = 0; i < n; i++)
    {
        cin >> carros[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> caminos[j];
        mark[j] = false;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> aux[j];
            acum[i] = acum[i] < aux[j] || j == 0 ? aux[j] : acum[i];
        }
        calidades[i] = aux;
    }
    for (int i = n - 1; i > 0; i--)
    {
        //acum[i - 1] += acum[i];
    }
    int actual = 0, mejor = 0;
    invernalia(carros, caminos, calidades, mark, n, m, mejor, actual, 0, acum);
    cout << mejor << endl;
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