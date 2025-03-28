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

int getMinDuracion(vector<int> const& actividades, int total, int N) {
	vector<int> duracion(total + 1);
	for (int i = 0; i <= total; i++)
	{
		duracion[i] = max(i, total - i);
	}

	for (int k = N - 1; k >= 0; k--)
	{
		for (int j = 0; j <= total - actividades[k]; j++)
		{
			duracion[j] = min(
				duracion[j],
				duracion[j + actividades[k]]
			);
		}
	}

	return duracion[0];
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;

	vector<int> actividades(N);
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> actividades[i];
		total += actividades[i];
	}
	cout << getMinDuracion(actividades, total, N) << "\n";
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