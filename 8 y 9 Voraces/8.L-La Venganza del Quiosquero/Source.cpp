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



long long int getCosteTotal(int N, int S) {
	int coste = 0, cont = 0;
	long long int omnio = 1;
	while (cont < N) {
		if (S - omnio >= omnio || omnio >= S) {
			coste += omnio;
			cont++;
		}
		omnio++;
	}
	return coste;
}

bool resuelveCaso() {
	int N, S;
	cin >> N >> S;
	if (!cin) return false;

	//cout << getCosteTotal(N, S) << "\n";
	long long int resultado = (N * (N - 1)) / 2;
	cout << resultado << "\n";

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