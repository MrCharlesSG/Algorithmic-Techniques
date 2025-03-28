//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<bool> marca;
typedef vector<arr> pacientes;

void hospital(const pacientes& pacs, const arr& capacidades, arr& mark, 
    const arr&acum, const int n, const int m, int k, int& actual, int& min) {
    /*
    k ==> paciente
    i ==> hospital
    */
    for (int i = 0; i < m; i++)
    {
        //Si el hospital puede tenner a paciente
        if (mark[i] < capacidades[i]) {
            //elijo
            actual += pacs[k][i];
            mark[i]++;

            //Caso Base
            if (k == n - 1) {
                min = min > actual ? actual : min;
            }
            else {
                //Miro mejor solución posible
                if (actual + acum[k + 1] < min) {
                    hospital(pacs, capacidades, mark, acum, n, m, k + 1, actual, min);
                }
            }

            //DesEljo
            actual -= pacs[k][i];
            mark[i]--;
        }
    }
}

void resuelveCaso() {  
    int n, m;
    cin >> n >> m;
    arr paciente(m), capacidades(m), acum(n, -1);
    pacientes pacs(n);
    for (int i = 0; i < m; i++)
    {
        cin >> capacidades[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            cin >> paciente[j];
            paciente[j] *= 2;
            acum[i] = acum[i] > paciente[j] ? paciente[j] : acum[i];
        }
        pacs[i] = paciente;
    }
    int min = 1000000, actual = 0;
    arr mark(m, 0);
    hospital(pacs, capacidades, mark, acum, n, m, 0, actual, min);
    cout << min << endl;
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