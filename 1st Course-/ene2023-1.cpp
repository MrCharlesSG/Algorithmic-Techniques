//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int resuelve(vector<int> v, const int n, const int l) {
    int cont = 1, unos = 0, ceros = 0, i=1;
    while (i<n-l+1){
        //Actualizo lo q entra
        if (v[i + l-1] == 0)
            ceros++;
        else if (v[i + l-1] == 1)
            unos++;

        //Actualizo lo q sale
        if (v[i - 1] == 0)
            ceros--;
        else if (v[i - 1] == 1)
            unos--;

        //Contador
        if (ceros == unos)
            cont++;
        
        //Avanzo punteros
        i++;
    }
    return cont;
}

void resuelveCaso() {
    int l, n;
    cin >> l >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << resuelve(v, n, l) << endl;
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
