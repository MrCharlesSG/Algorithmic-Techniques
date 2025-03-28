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
/*
int suma(vector <int> v, int i, int f, bool& deg) {
	if (deg) {
		if (i == f) {
			return v[i];
		}

		int m = (i + f)/2;
		int si = suma(v, i, m, deg);
		int sd = suma(v, m+1 , f, deg);

		if (si<sd) {
			return si + sd;
		}
		else {
			deg = false;
			return 0;
		}
	}
	return 0;
}*/

pair <bool, int> s(vector <int> v, int i, int f) {
	if (i == f-1) {
		return { true,v[i] };
	}
	else {
		int m = (i + f) / 2;
		pair<bool, int> si = s(v, i, m);
		pair<bool, int> sd = s(v, m, f);

		return { si.second < sd.second&& si.first&& sd.first, si.second + sd.second };
	}
}

bool degradado(vector <vector<int>> v, int c,int r) {
	int i = 0;
	bool deg = true;
	while (deg && i < c-1) {
		deg = s(v[i], 0, r).first;
		i++;
	}
	return deg;

}

bool resuelveCaso() {
	int col, row;
	cin >> col>> row;
	if (!cin) {
		return false;
	}
	else {
		//vector <int> v = vec(col, ro);
		vector <vector<int>> v(col, vector<int>(row));

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				cin >> v[i][j];
			}
		}

		if (degradado(v, col,row)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
}


/*
void resuelveCaso() {
	int n, cant;
	cin >> n>> cant;

	vector <int> v = vec(n);
	
	int pos = posicion(v, 0, n - 1, cant);

	if (pos == -1) {
		cout << "NO" << endl;
	}
	else {
		cout << pos << endl;
	}



}*/

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
