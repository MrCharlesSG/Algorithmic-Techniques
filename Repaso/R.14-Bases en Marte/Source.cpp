#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include "IndexPQ.h"
using namespace std;

const int INF = 1000000000;

struct Bateria {
    int id;
    int base;
    int duracion;

    Bateria() {}
    Bateria(int id, int base, int duracion) : id(id), base(base), duracion(duracion) {}
};

bool operator<(Bateria const& a, Bateria const& b) {
    return a.duracion < b.duracion || a.duracion == b.duracion && a.id < b.id;
}

void printVeredicto(vector<Bateria> const& bateriasVect, queue<Bateria> & reserva, int Z, int T, int B, int R) {
    IndexPQ<Bateria> baterias(B+R);
    for (Bateria bat : bateriasVect) {
        baterias.push(bat.id, bat);
    }

    while (!baterias.empty() && baterias.top().prioridad.duracion <= T)
    {
        Bateria b = baterias.top().prioridad;
        b.base -= Z;
        b.duracion += b.base;
        if (b.base <= 0) { // aunque recargue no va a aguantar
            baterias.pop();
            if (!reserva.empty()) { // añado una bateria de reserva
                Bateria r = reserva.front(); 
                r.duracion += b.duracion;
                baterias.push(r.id, r);
                reserva.pop();
            }
        }
        else { // si recargo aguanta
            baterias.update(b.id, b);
        }
    }

    if (baterias.empty())
        cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    else if (baterias.size() < B)
        cout << "FALLO EN EL SISTEMA\n";
    else
        cout << "CORRECTO\n";

    while (!baterias.empty())
    {
        Bateria b = baterias.top().prioridad; baterias.pop();
        cout << b.id + 1 << " " << b.duracion << "\n";
    }
    cout << "---\n";

}


bool resuelveCaso() {
    int B;
    cin >> B;
    if (!cin) return false;

    vector<Bateria> baterias;
    int R, Z, T;
    queue<Bateria> reservas;

    for (int i = 0; i < B; i++)
    {
        int d;
        cin >> d;
        baterias.push_back({ i, d, d });
    }
    cin >> R;
    for (int i = 0; i < R; i++)
    {
        int d;
        cin >> d;
        reservas.push({ B+i, d, d });
    }
    cin >> Z >> T;
    printVeredicto(baterias, reservas, Z, T, B, R);

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
