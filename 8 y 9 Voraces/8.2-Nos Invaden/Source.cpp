/*@ <authors>
 *
 *
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
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

int getCiudadesDefendidas(vector<int> const& ciudades, vector<int> const& tropas, int N) {
	int c = 0, t = 0;
	int ciudadesDefendidas=0;
	while (c < N && t < N) {
		if (ciudades[c] <= tropas[t]) {
			c++; t++; ciudadesDefendidas++; //poner tropa
		}
		else {
			c++; //ciudad idefendible
		}
	}

	return ciudadesDefendidas;
}


bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;

	vector<int> ciudades(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ciudades[i];
	}

	vector<int> tropas(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tropas[i];
	}

	sort(ciudades.begin(), ciudades.end(), greater<int>());
	sort(tropas.begin(), tropas.end(), greater<int>());

	cout << getCiudadesDefendidas(ciudades, tropas, N) << "\n";

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