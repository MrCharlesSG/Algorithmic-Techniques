#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

int degradado(const arr &m, const int n, const int k, bool& deg) {
	if (deg) {
		//caso BAse
		if (n == k - 1) {
			int a = m[n], b = m[k];
			if (a < b) {
				return a + b;
			}
			else {
				deg = false;
			}
		}
		//caso recursivo
		else {
			int a, b;
			a = degradado(m, n, (k + n) / 2, deg);
			b = degradado(m, ((k + n) / 2) + 1, k, deg);
			if (a < b) {
				return a + b;
			}
			else {
				deg = false;
			}
		}
	}
	return 0;
}

bool resuelve(const matriz ma, const int n, const int m) {
	int i = 0;
	bool deg = true;
	while (i < n && deg) {
		degradado(ma[i], 0, m - 1, deg);
		i++;
	}
	return deg;
}

bool resuelveCaso() {
	int n, m;
	cin >> n >> m;
	if (!cin) {
		return false;
	}
	matriz v(n, arr(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}

	}

	if (resuelve(v, n, m)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
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