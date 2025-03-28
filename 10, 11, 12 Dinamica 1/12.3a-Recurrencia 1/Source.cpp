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

struct Valor {
	int v;
	int c;

	Valor(int v, int c) : v(v), c(c){ }
	Valor() {}
};


EntInf recurrencia(vector<Valor> const& valores, int N, int P) {
	vector<EntInf> f(P + 1, Infinito);
	f[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = P; j > 0; j--) {
			int limit = min(valores[i - 1].c, j / valores[i - 1].v);
			for (int k = 0; k <= limit; k++)
			{
				auto temp = f[j - k * valores[i - 1].v] + k;
				if (temp < f[j]) {
					f[j] = temp;
				}
			}
		}
	}
	return f[P];
}

void printRecurrecia(vector<Valor> const& valores, int P) {
	int N = valores.size();
	EntInf res = recurrencia(valores, N, P);
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

	vector<Valor> valores(N);
	for (int i = 0; i < N; i++)
	{
		cin >> valores[i].v;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> valores[i].c;
	}
	int P;
	cin >> P;

	printRecurrecia(valores, P);

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