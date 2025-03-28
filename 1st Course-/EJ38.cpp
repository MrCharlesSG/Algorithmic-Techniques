#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

typedef vector<bule> matrizB;


/*
* k== posicion
* i==artista
* marca indica si el artista esta ocupada o no
*/

void posi(const matriz& m, const matrizB& m2, const arr& acum, const int n, arr& s, bule& art, int k, int actual, int& max) {
	for (int i = 0; i < n; i++)
	{
		if (!art[i] && (k==0 || m2[i][s[k - 1]])) {
			s[k] = i;
			actual += m[i][k];
			art[i] = true;
			if (k == n - 1) {
				if (actual > max) {
					max = actual;
				}
			}
			else {
				if (acum[k + 1] + actual > max) {
					posi(m, m2, acum, n, s, art, k + 1, actual, max);
				}
			}
			s[k] = -1;
			actual -= m[i][k];
			art[i] = false;
		}
	}
}

void resuelveCaso() {
	int n, max=0;
	cin >> n;
	arr v(n), ac(n, 0), ac1(n, 0);
	bule marca(n, false), aux(n);
	matriz m;
	matrizB m2;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			if (ac[i] < v[i]) {
				ac[i] = v[i];
			}

		}
		m.push_back(v);
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> max;
			aux[i]=max;
		}
		m2.push_back(aux);
	}
	for (int i = n - 1; i > 0; i--)
	{
		ac[i - 1] += ac[i];
	}
	
	max = -1;
	arr s(n);
	posi(m, m2, ac, n, s, marca, 0, 0, max);
	if (max < 0) {
		cout << "NEGOCIA CON LOS ARTISTAS\n";
	}
	else {
		cout << max<< endl;
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