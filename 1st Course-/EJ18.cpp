#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
	P={N>0 y esConcava(v)  y 0<=i <f <=N}
	fun minimo(v[0..N], int i, int f)
	Q={ r = min u: 0<= u <N: v[u]}


	donde:
		-esConcava(v) = ( existe m: 0<m<N : creciente(v, m) y decrecente(v,m))
		-creciente(v, m) =(noExiste i: 0<m<i<N: v[i]<v[m])
		-decreciente( v, m) =(noExiste i: 0<i<m<N: v[i]> v[m])
*/

vector <char> vec(int n) {
	char a;
	vector <char> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}


char falta(vector <char> v, int i, int f, char ini, char fin) {
	if (i == f - 1) {
		if (v[i] == ini) {
			return fin;
		}
		else {
			return ini;
		}
	}
	else {
		int m = (i + f) / 2;
		char me = (ini + fin) / 2;
		if (v[m] > me) {
			return falta(v, i, m, ini, me);
		}
		else {
			return falta(v, m, f, me, fin);
		}
	}
}


void resuelveCaso() {
	char  a, z;
	int n;
	cin >> a >> z;
	n = z - a;
	if (n != 0) {
		vector <char> v = vec(n);
		cout << falta(v, 0, n-1, a, z ) << endl;
	}

}

int main() {
/*
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
*/
	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++)
	{
		resuelveCaso();
	}
	return 0;
}
