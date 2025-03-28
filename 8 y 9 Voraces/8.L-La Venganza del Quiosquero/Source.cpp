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