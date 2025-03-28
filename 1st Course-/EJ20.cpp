#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

typedef vector<bule> matrizB;

int elBongo(const arr& v, const int k, int ini, int fin) {
	if (ini == fin - 1) {
		if (v[ini] == ini + k) {
			return v[ini];
		}
		else {
			return -57;
		}
	}
	else {
		int m = (ini + fin) / 2;
		if (v[m] > m + k) {
			return elBongo(v, k, ini, m);
		}
		else {
			return elBongo(v, k, m, fin);
		}
	}
}

void resuelveCaso() {
	int n, k;
	cin >> n>>k;
	arr v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int a = elBongo(v, k, 0, n);
	if (a == -57) {
		cout << "NO\n";
	}
	else {
		cout << a << endl;
	}
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