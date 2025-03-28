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

struct Pelicula {
	int inicio;
	int fin;
	int duracion;

	Pelicula(int comienzo, int duracion) : inicio(comienzo), fin(comienzo + duracion), duracion(duracion-10){ }
};

bool operator<(Pelicula const& a, Pelicula const& b) {
	return a.inicio < b.inicio;
}

int getNumPeliculasQueSePuedenVer(vector<Pelicula> const& peliculas, int N) { //O(n*n)
	vector<int> duracion(N, 0);
	int i = N - 2;
	duracion[N - 1] = peliculas[N - 1].duracion;
	while (i>=0)
	{
		int duracionDeJ = 0;
		for (int j = i+1; j < N; j++) { // se podría utilizar el vector ordenado para encontrarlo antes
			if (peliculas[j].inicio >= peliculas[i].fin) {
				duracionDeJ = duracion[j];
				break;
			}
		}

		duracion[i] = max(duracion[i + 1], duracionDeJ + peliculas[i].duracion);
		i--;
	}
	return duracion[0];
}

bool resuelveCaso() {
	int N, M;
	cin >> N;
	if (!cin || N == 0) return false;

	vector<Pelicula> peliculas;
	for (int i = 0; i < N; i++)
	{
		char aux;
		int iniHora, iniMin, duracion;
		cin >> iniHora >> aux >> iniMin >> duracion;
		int ini = iniHora * 60 + iniMin;
		peliculas.push_back({ ini, duracion + 10 });
	}

	sort(peliculas.begin(), peliculas.end());

	cout << getNumPeliculasQueSePuedenVer(peliculas, N) << "\n";

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