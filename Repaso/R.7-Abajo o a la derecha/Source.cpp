/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
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