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
#include "Matriz.h"
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

const int NUM_LETRAS = 4;

int letraToInt(char letra) {
	switch (letra)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	default:
		return NUM_LETRAS;
	}
}

int recurrencia2(Matriz<int> const& a, string v, string u, int N, int M) {
	Matriz<int> f(N + 1, M + 1, 0);
	for (int j = 1; j <= M; j++)
	{
		f[0][j] = a[NUM_LETRAS][letraToInt(v[j - 1])] + f[0][j-1];
	}
	for (int i = 1; i <= N; i++)
	{
		f[i][0] = a[letraToInt(u[i - 1])][NUM_LETRAS] + f[i - 1][0];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) {
			int prim, seg, ter;
			prim = a[letraToInt(u[i - 1])][NUM_LETRAS] + f[i-1][j];
			seg = a[NUM_LETRAS][letraToInt(v[j - 1])] + f[i][j-1];
			ter = a[letraToInt(u[i - 1])][letraToInt(v[j - 1])] + f[i-1][j-1];
			prim = max(prim, seg);
			f[i][j] = max(prim, ter);
		}
	}
	return f[N][M];
}

void resuelveCaso() {
	Matriz<int> a(NUM_LETRAS + 1, NUM_LETRAS + 1);
	for (int i = 0; i <= NUM_LETRAS; i++)
	{
		for (int j = 0; j <= NUM_LETRAS; j++) {
			int aux;
			cin >> aux;
			a[i][j] = aux;
		}
	}

	int P;
	cin >> P;
	vector<int> soluciones;

		for (int i = 0; i < P; i++) {
			string u, v;
			cin >> u >> v;
			int N = u.length(), M = v.length();
			soluciones.push_back(recurrencia2(a, v, u, N, M));
		}
	


	for (int sol : soluciones) {
		cout << sol << "\n";
	}
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}