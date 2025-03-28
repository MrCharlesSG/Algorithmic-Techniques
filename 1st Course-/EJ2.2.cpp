#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

bool resuelve(const arr a, const int n) {
	bool asc = a[0] < a[1], dalton=a[0]!=a[1];
	int i = 1;

	while (dalton && i<n-1)
	{
		if (asc && a[i] >= a[i + 1] || !asc && a[i] <= a[i + 1]) {

			dalton = false;

		}
		i++;
	}

	return dalton;
}

bool resuelveCaso() {
	int n;
	

	cin >> n;
	if (n == 0) {
		return false;
	}
	arr a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (resuelve(a, n)) {
		cout << "DALTON\n";
	}
	else {
		cout << "DESCONOCIDOS\n";
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