#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

/*
*/

void laSuma(const arr& v, const int n, const int m,int suma,int k, bool& sePuede, const arr& acum) {
	if (!sePuede && k<n) {
		for (int i = 0; i < 2 && !sePuede; i++)
		{
			if (i != 0|| k==0) {
				suma += v[k];
			}
			else {
				suma -= v[k];
			}
			
			if (k == n - 1) {
				if (suma == m) {
					sePuede = true;
				}
			}
			else if (suma + acum[k + 1] > m) {
				laSuma(v, n, m, suma, k + 1, sePuede, acum);
			}
			else if (suma + acum[k + 1] == m) {
				sePuede = true;
			}
			if (i != 0 || k == 0) {
				suma -= v[k];
			}
			else {
				suma += v[k];
			}
		}
	}
	else if (k == 0) {
		sePuede = true;
	}
}

void resuelveCaso() {
	int n, m;
	cin >> m >> n;
	arr v(n), acum;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	acum = v;
	for (int i = n - 1; i > 0; i--)
	{
		acum[i - 1] += acum[i];
	}
	bool sePuede = false;
	laSuma(v, n, m, 0, 0, sePuede, acum);
	if (sePuede) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
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