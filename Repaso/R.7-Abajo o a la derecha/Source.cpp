/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
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

int numSaltos(Matriz<int> const& A, int N, int M) {
	Matriz<int> saltos(N, M, 0);
	saltos[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int futI = i + A[i][j];
			int futJ = j + A[i][j];
			if (futI < N) saltos[futI][j] += saltos[i][j];
			if (futJ < M) saltos[i][futJ] += saltos[i][j];
		}
	}

	return saltos[N - 1][M - 1];
}

bool resuelveCaso() {

	int N, M;
	cin >> N >> M;

	if (!std::cin)  // fin de la entrada
		return false;

	Matriz<int> A(N, M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >>  A[i][j];
		}
	}

	cout << numSaltos(A, N, M) << "\n";

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