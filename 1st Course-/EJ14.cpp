//NOmyRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matriz;

//Pre:  { 0 <= n <= size(v)}
//Post: { m = max p, q: 0<=p<=q<n y sonConsec(v, p, q): q-p }

//sonConsec (v, i, j) = {Paratodo w,u: i<=w<u<=j:v[w]-1 == v[u] o v[w]-1 ==v[u]} 

//cota: n-i

//invariante: m = max p, q: 0<=p<=q<i y sonConsec(v, p, q): q-p && 0 <=i <=n 
//              && cont = 1 + #u, w : j <=u<w <=i y sonConsec(v, u, w) y !sonConsec(v, j, u)
int numConsecutivos(const vector<int> v, const int n) {
    int i = 0, cont = 0, max = 0;
    while (i < n)
    {
        if (i == 0) {
            cont = 1;
            max = cont;
        }
        else {
            if (v[i - 1] + 1 == v[i] || v[i - 1] - 1 == v[i]) {
                cont++;
            }
            else {
                max = cont > max ? cont : max;
                cont = 1;
            }
        }
        i++;
    }
    return cont > max ? cont : max;
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> aux(n);

    for (int i = 0; i < n; i++)
    {
        cin >> aux[i];
    }

    cout << numConsecutivos(aux, n) << endl;
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