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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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