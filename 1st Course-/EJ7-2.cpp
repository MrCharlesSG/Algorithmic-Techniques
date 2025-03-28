#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

pair<int, int> equilibrio(const arr a, const int n, const int t) {
	int iniMax = 0, ini = 0, longMax = 0, longA = 0;
	bool in = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > t) {
			longA++;
			if (longA > longMax) {
				longMax = longA;
				iniMax = i - longMax + 1;
			}
		}
		else {
			longA = 0;
		}
	}

	return { iniMax, longMax + iniMax - 1 };
}

void resuelveCaso() {
	int n, t;

	cin >> n >> t;

	arr a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	pair <int, int> s = equilibrio(a, n, t);

	cout << s.first << " " << s.second << endl;
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