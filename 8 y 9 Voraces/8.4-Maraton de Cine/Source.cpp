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

	Pelicula(int comienzo, int duracion) : inicio(comienzo), fin(comienzo + duracion) { }
};

bool operator<(Pelicula const& a, Pelicula const& b) {
	return a.fin < b.fin;
}

int getNumPeliculasQueSePuedenVer(vector<Pelicula> const& peliculas, int N) {
	int numPeliculas = 0, ultima = 0;
	for (int i = 0; i < N; i++)
	{
		if (ultima <= peliculas[i].inicio) {
			ultima = peliculas[i].fin; numPeliculas++;
		}
	}
	return numPeliculas;
}

bool resuelveCaso() {
	int N, M;
	cin >> N;
	if (!cin || N==0) return false;

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