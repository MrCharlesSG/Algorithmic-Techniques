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

vector <int> vec(int n) {
	int a;
	vector <int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

int minimo(vector <int> v, int i, int f) {
	if (i == f - 1) {
		if (v[i] > v[f]) {
			return v[f];
		}
		else { return v[i]; }
	}
	else if (i == f) {
		return v[i];
	}
	else {
		if (v[i] > v[f]) {
			return v[f];
		}
		else {
			f--;
			int dcha = minimo(v, i, (i + f) / 2);
			int izq = minimo(v, (i + f) / 2, f);
			
			if (dcha > izq) { return izq; }
			else { return dcha; }
		}
	}
	/*
	else {
		if (v[i] < v[f]) {
			return minimo(v, i, (i + f) / 2);
		}
		else {
			return minimo(v, (i + f) / 2, f);
		
		}}*/

	
}

bool resuelveCaso() {
	char  a, z;
	int n;
	cin >> n;
	if (!cin) {
		return false;
	}
	else {
		vector <int> v = vec(n);
		cout << minimo(v, 0, n - 1) << endl;

		return true;
	}

}

int main() {

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
