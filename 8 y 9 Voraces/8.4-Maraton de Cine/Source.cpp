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