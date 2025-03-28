#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//typedef vector<vector<int>> matriz;

typedef vector<int> arr;

typedef vector<bool> marca;

typedef struct cancion {
	int izq, dch;
	int suma;
};

typedef vector<cancion> matriz;

//t es el total de todas las canciones
//m ==marca si se ha utilizado
//

void sol(const matriz t, marca& m, const int N, const int d, int& izq, int& dch, int& max, int k, int& ini ) {
	for (int i = ini; i < N; i++)
	{
		if (!m[i]) {
			//elijo
			izq += t[i].izq;
			dch += t[i].dch;
			m[i] = true;
			//caso Base
			if (izq <= d && dch <= d) {
				if (izq + dch >= max) {
					max = izq + dch;
					ini++;
					}
				
				else {
					if (izq + dch < max) {
						sol(t, m, N, d, izq, dch, max, k + 1, ini);
					}
				}
			}
			izq -= t[i].izq;
			dch -= t[i].dch;
			m[i] = false;
		}
	}
	
}

bool resuelveCaso() {
	int N, d, a, msuma=0;

	cin >> N;
	if (N == 0) {
		return false;
	}

	matriz t;
	marca m(N, false);
	cancion f;

	cin >> d;

	for (int i = 0; i < N; i++)//filas
	{
		cin >> f.izq >> f.dch;
		f.suma = f.izq + f.dch;
		if (f.suma > msuma) {
			msuma = f.suma;
		}
		if (f.izq < d && f.dch < d) {
			t.push_back(f);
		}
		
	}
	int izq = 0, dch = 0, max = msuma, ini = 0;
	sol(t, m, N, d, izq, dch, max, 0, ini);
	cout << max << endl;

	return true;
}

int main() {
/*
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int cas;
	cin >> cas;
	for (int i = 0; i < cas; i++)
	{
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	*/

	// ajuste para que cin extraiga directamente de un fichero
	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		while (resuelveCaso());


		// restablecimiento de cin
	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("pause");
	#endif
	

}