
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la soluci�n.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

using lli = long long int;

const lli INF = 1000000000000000000;

struct Cuerda {
	lli dim;
	lli coste;
};

lli matematico(vector<Cuerda> const& cuerdas, int N, int L) {
    vector<lli> formas(L + 1, 0);
    formas[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = L; j >= cuerdas[i - 1].dim; j--) {
            formas[j] = formas[j] + formas[j - cuerdas[i - 1].dim];
       
        }
    }
    return formas[L];
}

lli ingeniero(vector<Cuerda> const& cuerdas, int N, int L) {
    vector<lli> cordeles(L + 1, INF);
    cordeles[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = L; j >= cuerdas[i - 1].dim; j--) {
            cordeles[j] = min(
                cordeles[j],
                cordeles[j - cuerdas[i - 1].dim] + 1
            );
        }
    }
    return cordeles[L];
}

lli economista(vector<Cuerda> const& cuerdas, int N, int L) {
    vector<lli> coste(L + 1, INF);
    coste[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = L; j >= cuerdas[i - 1].dim; j--) {
            coste[j] = min(
                coste[j],
                coste[j - cuerdas[i - 1].dim] + cuerdas[i - 1].coste
            );
        }
    }
    return coste[L];
}

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>




bool resuelveCaso() {
	int N, L;
	cin >> N >> L;
	if (!cin) return false;

    vector<Cuerda> cuerdas(N);

    for (int i = 0; i < N; i++)
    {
        int l, c;
        cin >> l >> c;
        cuerdas[i] = { l, c };
    }
	
    lli mat = matematico(cuerdas, N, L),
        ing = ingeniero(cuerdas, N, L),
        eco = economista(cuerdas, N, L);

    if (mat == INF || ing == INF || eco == INF)
        cout << "NO\n";
    else
        cout << "SI " << mat << " " << ing << " " << eco << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
