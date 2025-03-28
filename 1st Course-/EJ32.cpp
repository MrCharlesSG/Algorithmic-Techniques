#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matriz;

typedef vector<int> arr;

typedef vector<bool> marca;

void sol(const int N, int k, const matriz t, const arr acum, marca& m, int& actual, int& minimo ){
	for (int i = 0; i < N; i++)
	{
		//si no esta marcado
		if (!m[i]) {
			//elijo y marco
			actual += t[k][i];
			m[i] = true;
			//si es caso base
			if (k == N - 1) {
				//es caso base ==> miro si es mejor solucion que la que llevo
				if (actual < minimo) {
					//es el nuevo minimo
					minimo = actual;
				}
			}
			else {
				//No es caso base ==> podo
				if (actual + acum[k + 1] < minimo) {
					sol(N, k + 1, t, acum, m, actual, minimo);
				}
			}
			//desmarco y quito elección
			m[i] = false;
			actual -= t[k][i];
		}
	}

}

bool resuelveCaso() {
	int N, a;
	cin >> N;
	if (N < 1 || N > 20) {
		return false;
	}
	else {
		arr f;
		arr acum;
		matriz t;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> a;
				f.push_back(a);
			}
			t.push_back(f);
			f.resize(0);
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
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

		for (int i = N-1; i >0; i--)
		{
			acum[i - 1] += acum[i];
		}
		a = acum[0] * 1000;
		int b=0;
		marca m(N, false);
		sol(N, 0, t, acum, m, b, a);
		cout << a << endl;
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