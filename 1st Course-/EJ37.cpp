#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

int multiplicativo(const int n, int& cont) {
	if (n < 10) {
		if (n == 1) {
			cont++;
		}
		return n;
	}
	else {
		int acum = multiplicativo(n/10, cont);
		if (acum % 10 == n % 10) {
			cont++;
		}
		return acum *= n%10;
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	
	int cont=0,s = multiplicativo(n, cont);
	cout << cont << endl;

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