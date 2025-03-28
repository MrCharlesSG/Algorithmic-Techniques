#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

arr merge(const arr& v, const int i, const int n, int& cont ) {
	if (i == n) {
		arr a;
		a.push_back(v[i]);
		return a;
	}
	else {
		arr a = merge(v, i, (n + i) / 2, cont);
		arr b = merge(v, (n + i) / 2+1, n, cont);
		arr s;
		int k = 0, j = 0, bs=b.size(), as= a.size();
		//MERGE
		//Mezclamos
		while (k<as && j<bs)
		{
			if (a[k] < b[j]) {
				cont += s.size() - k;
				s.push_back(a[k]);
				k++;
			}
			else {
				s.push_back(b[j]);
				j++;
			}
		}
		//añadimos al final a
		while (k<as){
			cont += s.size() - k;
			s.push_back(a[k]);
			k++;
		}
		//añadimos al final b
		while (j < bs) {
			s.push_back(b[j]);
			j++;
		}

		return s;
	}
	
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin) {
		return false;
	}
	arr v(n);
	

	for (int j = 0; j < n; j++)
	{
		cin >> v[j];
	}
	int cont = 0;
	v =merge(v, 0, n-1, cont);

	cout << cont << endl;
	
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