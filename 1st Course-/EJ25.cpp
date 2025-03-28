#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

arr merge(const arr& s1, const arr& s2, long long int& cont) {
	arr s;
	int j = 0, i = 0, q1 = s1.size(), q2 = s2.size();

	while (i < q1 && j < q2) {
		if (s1[i] > s2[j]) {
			s.push_back(s2[j]);
			cont += q1 - i;
			j++;
		}
		else {
			s.push_back(s1[i]);
			i++;
		}
	}
	for (int k= i; k < q1; k++)
	{
		s.push_back(s1[k]);
	}
	for (int l = j; l < q2; l++)
	{
		s.push_back(s2[l]);
	}
	return s;
}

arr numInv(const arr& v, const int ini, const int fin, long long  int& cont) {
	arr s1;
	if (ini == fin - 1) {
		s1.push_back(v[ini]);
		return s1;
	}
	else {
		arr  s2, s;
		int m = (ini + fin) / 2;
		s1 = numInv(v, ini, m, cont);
		s2 = numInv(v, m, fin, cont);

		return merge(s1, s2, cont);
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	
	if (n == 0) {
		cout << 0<< endl;
	}
	else {
		arr v(n);
	
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		long long int cont = 0;
		numInv(v, 0, n, cont);
		cout << cont << endl;
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