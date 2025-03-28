//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;
typedef vector<arr> cal;
typedef vector<bool> marca;

void invernalia(const arr& caminos, const arr& carros, const cal& calidades, const arr& acum,
    marca& mark, int k, const int n, const int m, int& max, int& actual);

void casoBaseRecursivo(const arr& caminos, const arr& carros, const cal& calidades, const arr& acum,
    marca& mark, int k, const int n, const int m, int& max, int& actual) {
    
    //caso base
    if (k == n - 1) {
        if (actual > max) {
            max = actual;
        }
    }
    //Caso recursivo
    else {
        //Si la mejor solucion posible mas actual es mejor que max llamada recursiva
        if (actual + acum[k + 1] >= max) {
            invernalia(caminos, carros, calidades, acum, mark, k + 1, n, m, max, actual);
        }
    }
}

//Habra que elegirle un camino a cada carro, puede que un carro no tenga camino

void invernalia(const arr& caminos, const arr& carros, const cal& calidades, const arr& acum,
    marca& mark, int k, const int n, const int m, int& max, int& actual) {
    /*
    i => camino
    k => carro
    */

    //Si acum[k] tiene 0 significa que no hay ningún camino optimo para el carro 
    //por lo que habra que pasar de largo o resolver
    if (acum[k] > 0) {
        for (int i = 0; i < m; i++)
        {
            //Si el camino no esta cojido, y el carro es menos ancho
            if (!mark[i] && caminos[i] >= carros[k]) {
             
                //elijo
                actual += calidades[k][i];
                mark[i] = true;

                //Hago caso base o llamda recursiva
                casoBaseRecursivo(caminos, carros, calidades, acum, mark, k, n, m, max, actual);

                //Deselijo
                actual -= calidades[k][i];
                mark[i] = false;
            }
        }
        
    }
    else {
        casoBaseRecursivo(caminos, carros, calidades, acum, mark, k, n, m, max, actual);
    }        
}

void resuelveCaso() {  
    int n, m;
    cin >> n >> m;
    arr caminos(m), carros(n), aux(m), acum(n, 0);
    cal calidades(n);
    for (int i = 0; i < n; i++)
        cin >> carros[i];
    for (int i = 0; i < m; i++)
        cin >> caminos[i];
    for (int i = 0; i < n; i++){
        for (int j = 0; j  < m; j ++){
            cin >> aux[j];
            acum[i] = (j == 0 || acum[i] <= aux[j]) && carros[i]<=caminos[j] ? aux[j] : acum[i];
        }
        calidades[i] = aux;
    }
    for (int i = n- 1; i > 0; i--)
    {
        acum[i - 1] += acum[i];
    }
    marca mark(m, false);
    int max = 0, actual = 0;
    invernalia(caminos, carros, calidades, acum, mark, 0, n, m, max, actual);
    cout << max << endl;
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