#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef int marca[20];

typedef vector<vector<int>> total;

void sol(const total t, marca& m, int& actual, int& minimo, int p, int s, int k, const vector<int> acum) {
	for (int i = 0; i < s; i++)
	{
		if (m[i] < 3) {
			int aux = actual + t[i][k];
			if (aux < minimo) {
				m[i]++;
				actual = aux;
				if (k == p - 1) {
					if (minimo > actual) {
						minimo = actual;
					}
				}
				else {
					if (actual + acum[k + 1] < minimo)
						sol(t, m, actual, minimo, p, s, k + 1, acum);
				}
				m[i]--;
				actual -= t[i][k];
			}
		}
	}
}

void resuelveCaso() {
	total t;
	vector<int> f;
	vector<int> acum;
	int s, p, a;
	cin >> s >> p;

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < p; j++)
		{
			cin >> a;
			f.push_back(a);
		}
		t.push_back(f);
		f.resize(0);
	}

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < s; j++)
		{
			a = t[j][i];
			if (j == 0) {
				acum.push_back(a);
			}
			else if (a < acum[i]) {
				acum[i] = a;
			}
		}

	}

	for (int i = (int)acum.size() - 1; i > 0; i--)
	{
		acum[i - 1] += acum[i];
	}

	int minimoF = 2147483647;
	marca m = { 0 };
	a = 0;
	sol(t, m, a, minimoF, p, s, 0, acum);
	cout << minimoF << endl;
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