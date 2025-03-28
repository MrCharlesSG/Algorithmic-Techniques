//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<int> arr;

/*

* noMas(v,i,j,l) = {l >= (#u : i <=u<j : v[u]%2==1)}

* PRECONDICION: 
    { k,l >=0 y k<=n<=v.size()}

* POSTCONTIDICION: 
    {cont = #i,j: 0<=i<j<=n y i-j==k: noMas(v,i,j,l)}

* COTA:
    n-i

* INVARIANTE
    {
* 
*/

int segmento(const vector<int>& v, const int n, const int k) {
    int actual = 0, max = 0, numPares = 0, i = 0;
    while (i<n)
    {
        if (v[i] % 2 == 0) {
            numPares++;
        }
        else {
            numPares = 0;
        }
        if (numPares <= k) {
            actual++;
        }
        else {
            max = max < actual ? actual : max;
            actual = k;
            numPares = k;
        }
        i++;
    }
    return max > actual ? max : actual;
}

void resuelveCaso() {  
    int n, l, k;
    cin >> n >> k;
    arr v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << segmento(v, n, k) << endl;
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