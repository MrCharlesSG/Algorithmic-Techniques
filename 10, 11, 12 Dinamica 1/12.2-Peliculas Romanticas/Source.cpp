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
		for (int j = i+1; j < N; j++) { // se podr�a utilizar el vector ordenado para encontrarlo antes
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