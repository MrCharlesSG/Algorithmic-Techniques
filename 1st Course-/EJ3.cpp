#include <iostream>

using namespace std;
bool resuelveCaso(const int tamano, const int pos);

int main() {
    int numCasos, anterior = -1;
    cin >> numCasos;


    for (int i = 0; i < numCasos; i++)
    {
        int tamano, pos;
        cin >> tamano >> pos;
        if (resuelveCaso(tamano, pos))
            cout << "SI\n";
        else
            cout << "NO\n";
    }

    return 0;
}

bool resuelveCaso(const int tamano, const int pos) {
    bool bul = true;
    int mayor = -60, actual = 0;

    for (int i = 0; i < pos + 1; i++)
    {
        cin >> actual;
        if (actual > mayor)
        {
            mayor = actual;
        }
    }
    int i = pos + 1;
    while (bul && i < tamano)
    {
        cin >> actual;
        if (actual <= mayor)
            bul = false;
        else
            i++;

    }
    return bul;
}