/*@ <authors>
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

int adjudicaCamisetas(vector<int> const& necesitamos, vector<int> const& tenemos, int N, int M) {
	int n = 0, t = 0;
	int camisetasAdjudicadas = 0;
	while (n < N && t < M) {
		if (necesitamos[n] == tenemos[t] || necesitamos[n] + 1 == tenemos[t]) {
			n++; t++; camisetasAdjudicadas++;
		}
		else if(necesitamos[n] > tenemos[t]){
			n++;
		}
		else {
			t++;
		}
	}

	return N - camisetasAdjudicadas;
}


bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;

	vector<int> necesitamos(N);
	for (int i = 0; i < N; i++)
	{
		cin >> necesitamos[i];
	}

	vector<int> tenemos(M);
	for (int i = 0; i < M; i++)
	{
		cin >> tenemos[i];
	}

	sort(necesitamos.begin(), necesitamos.end(), greater<int>());
	sort(tenemos.begin(), tenemos.end(), greater<int>());

	cout << adjudicaCamisetas(necesitamos, tenemos, N, M) << "\n";

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