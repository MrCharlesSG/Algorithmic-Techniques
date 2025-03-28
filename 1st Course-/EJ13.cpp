#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

typedef vector<bule> matrizB;

int noMas(const int n, const arr& v, const int k) {
	int contP=0, cont = 0, i=0, max=0;
	while (i < n) {
		if (v[i] % 2 == 0) {
			contP++;
			if (contP > k) {
				contP = k;
				if (cont > max) {
					max = cont;
				}
				cont = k-1;
			}
		}
		else {
			contP = 0;
		}
		cont++;
		i++;
		
	}
	if (cont > max) {
		max = cont;
	}
	return max;
}

void resuelveCaso() {
	int n, k;
	cin >> n>>k;
	arr v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int a = noMas(n, v, k);
	cout << a << endl;
}

int main() {

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
/*
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
	
*/	
}