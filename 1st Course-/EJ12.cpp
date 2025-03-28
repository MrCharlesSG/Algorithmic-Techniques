#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int invertir(int n, int ni) {
	int l;
	if (n <= 0) {
		l = ni;
	}
	else {

		l = invertir(n / 10, n % 10 + ni * 10);
	}
	return l;
}

int complementario(int n, int nc) {
	int l;
	if (n <= 0) {
		l = nc;
	}
	else {

		l = complementario(n / 10, (9 - (n % 10)) + nc * 10);
	}
	return l;
}

void resuelveCaso() {
	int  n, comp;
	cin >> n;
	if (!cin || n == 0) {
		return false;
	}
	else {
		comp = complementario(n, 0);
		cout << invertir(comp, 0) << " " << comp << "\n";
		return true;
	}
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++)
	{
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}