#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
PRECONDICION
{100.000 >= n >=2 : n= v.size()}

POSTCONDICION
{ParaTodo i: v[i-1]< v[i] : n>i>1 && v[0] < v[1] o ParaTodo i: v[i-1]> v[i] : n>i>1 && v[0] > v[1]


COSTE O(n)
*/
bool sonDalton(vector<int> v, int num) {
    bool ascendente = a[0] < a[1];
    bool correcto = a[0] != a[1];
    int i = 2;
    while (i < n && correcto)
    {
        if ((ascendente && a[i - 1] >= a[i]) || (!ascendente && a[i - 1] <= a[i]))
            correcto = false;
        else
            i++;
    }
    return correcto;
}

bool resuelveCaso() {
    int num;
    cin >> num;
    if (num > 1)
    {
        vector<int> v;
        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
            
        }
        if (!sonDalton(v, num)) {
            cout << "DESCONOCIDOS\n";
        }
        else
            cout << "SON DALTON\n";
        return true;
    }
    else
        return false;
}

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