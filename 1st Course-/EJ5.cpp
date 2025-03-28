#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*bool esPastoso(vector<int> v, int n) {
    int dim = v.size(), i = n + 1, suma = 0, num = v[n];
    bool noLoEs = true;
    while (noLoEs && i < dim)
    {
        suma += v[i];
        i++;
    }
    if (suma == num) {
        return true;
    }
    else
        return false;
}void resuelveCaso() {
    int num, c;
    cin >> num;
    vector<int> v;
    if (num > 0)
    {
        num--;
        while (num >= 0)
        {
            cin >> c;
            v.push_back(c);
            num--;
        }
        int i = v.size() - 1;
        if (i == 0) {
            cout << "No\n";
        }
        else {
            bool bul = false;
            while (!bul && i >= 0) {
                bul = esPastoso(v, i);

                if (!bul)
                    i--;

            }

            if (bul)
                cout << "Si " << i << endl;

            else
                cout << "No\n";
        }
    }
    else
        cout << "No\n";

}
*/

void resuelveCaso() {
    int num, c;
    cin >> num;
    vector<int> v;
    if (num > 0)
    {
        num--;
        while (num >= 0)
        {
            cin >> c;
            v.push_back(c);
            num--;
        }
        int i = v.size() - 1;
        int suma = 0;
        bool bul = false;
        while (!bul && i >= 0) {
            if (v[i] == suma)
                bul = true;
            else {
                suma += v[i];
                i--;
            }
        }

        if (bul)
            cout << "Si " << i << endl;

        else
            cout << "No\n";
    }
    else
        cout << "No\n";
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