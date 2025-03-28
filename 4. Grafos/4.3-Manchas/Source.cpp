
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (TAISXX) de los autores de la solución.
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
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

using Matriz = vector<vector<bool>>;
const char MANCHA = '#';

class ManchaNegra {
private:
	Matriz visit;
	int maxTam;
	int numManchas;

	int getTamanoMancha(Matriz const& manchas, int c, int f, int const C, int const F) {
		if (manchas[f][c] && !visit[f][c]) {
			visit[f][c] = true;
			int tamano = 1;
			if (c > 0) {
				//visit izq
				tamano += getTamanoMancha(manchas, c - 1, f, C, F);
			}
			if (c < C - 1) {
				//visit drcha
				tamano += getTamanoMancha(manchas, c + 1, f, C, F);
			}
			if (f > 0) {
				//visit top
				tamano += getTamanoMancha(manchas, c, f - 1, C, F);
			}
			if (f < F - 1) {
				//visit bott
				tamano += getTamanoMancha(manchas, c, f + 1, C, F);
			}
			return tamano;
		}
		return 0;
	}

public:
	ManchaNegra(Matriz const& manchas, int const F, int const C) : maxTam(0), numManchas(0) {
		visit = Matriz(F, vector<bool>(C, false));
		for (int f = 0; f < F; f++)
		{
			for (int c = 0; c < C; c++)
			{
				int tam = getTamanoMancha(manchas, c, f, C, F);
				if (tam != 0) {
					numManchas++;
					maxTam = max(maxTam, tam);
				}
			}
		}
	}

	int getNumManchas() {
		return numManchas;
	}

	int getMaxTamano() {
		return maxTam;
	}

};



bool resuelveCaso() {
	int F, C;
	cin >> F >> C;

	if (!std::cin)
		return false;

	char aux;
	Matriz manchas(F);
	for (int f = 0; f < F; f++)
	{
		vector<bool> fila(C);
		for (int c = 0; c < C; c++)
		{
			cin >> aux;
			fila[c] = aux == MANCHA;
		}
		manchas[f] = fila;
	}
	ManchaNegra manchaNegra(manchas, F, C);
	cout << manchaNegra.getNumManchas() << " " << manchaNegra.getMaxTamano() << "\n";

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