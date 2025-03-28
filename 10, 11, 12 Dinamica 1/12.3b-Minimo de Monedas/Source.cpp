/*@ <authors>
 *
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "EnterosInf.h"
using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct Moneda {
	int v;
	int c;

	Moneda(int v, int c) : v(v), c(c){ }
	Moneda() {}
};


EntInf recurrencia(vector<Moneda> const& monedas, int N, int P) {
	vector<EntInf> f(P + 1, Infinito);
	f[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = P; j > 0; j--) {
			int limit = min(monedas[i - 1].c, j / monedas[i - 1].v);
			for (int k = 0; k <= limit; k++)
			{
				auto temp = f[j - k * monedas[i - 1].v] + k;
				if (temp < f[j]) {
					f[j] = temp;
				}
			}
		}
	}
	return f[P];
}

void printRecurrecia(vector<Moneda> const& monedas, int P) {
	int N = monedas.size();
	EntInf res = recurrencia(monedas, N, P);
	if (res == Infinito) {
		cout << "NO\n";
	}
	else {
		cout << "SI " << res << "\n";
	}
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin || N == 0) return false;

	vector<Moneda> monedas(N);
	for (int i = 0; i < N; i++)
	{
		cin >> monedas[i].v;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> monedas[i].c;
	}
	int P;
	cin >> P;

	printRecurrecia(monedas, P);

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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