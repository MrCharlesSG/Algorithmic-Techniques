/*@ <authors>
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
#include <queue>
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


struct Chorizo {
	int disponible;
	int necesarios;
	int pan;
	int precio;
	int cantidad;

	Chorizo(int disponibleC, int necesariosC, int pan, int precio) : 
		disponible(disponibleC), necesarios(necesariosC), pan(pan), precio(precio), cantidad(disponibleC/necesariosC)
	{}

	Chorizo() {}
};

int ganancias(vector<Chorizo> const& chorizos, int N, int P) {
	vector<int> facturacion(P+1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = P; j >= 0; j--)
		{
			for (int k = 1; k <= chorizos[i-1].cantidad && k  * chorizos[i-1].pan <= j; k++)
			{
				facturacion[j] = max(
					facturacion[j],
					facturacion[j - chorizos[i - 1].pan * k] + k * chorizos[i - 1].precio
				);
			}
			
		}
	}
	
	return facturacion[P];
	
}

bool resuelveCaso() {
	int N, P;
	cin >> N >> P;
	if (!cin) return false;

	vector<Chorizo> chorizos(N);
	for (int i = 0; i < N; i++)
	{
		int d, g, p, c;
		cin >> d >> g >> p >> c;
		chorizos[i] = { d, g, p, c };
	}

	cout << ganancias(chorizos, N, P) << "\n";

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