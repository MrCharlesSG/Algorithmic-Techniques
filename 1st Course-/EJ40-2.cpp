#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

typedef vector<bule> matrizB;

int noMas(const arr& v, const int n, const int k, const int l) {
	int i = k, contI = 0, cont = 1;
	while (i < n) {
		if (v[i] % 2 != 0) {
			contI++;
		}
		if (contI > l) {
			if (v[i - k] % 2 != 0) {
				contI--;
			}
		}
		else {
			cont++;
		}
		i++;
	}
	return cont;
}

void resuelveCaso() {
	int n, k, l;
	cin >> n >> k >> l;
	arr v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int a;
	if (k > 0) {
		a = noMas(v, n, k, l);
	}
	else {
		a = n + 1;
	}
		
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