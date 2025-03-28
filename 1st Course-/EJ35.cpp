#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
* ACLARACIONES
* N = v.size();
* 
* RECURRENCIA
* T(N) = { k1			si N=0 || N=1;}
*		 { T(N/2) + k2  si N>1;}
*		
*			a*T(N/b) + k2 + n^k
* COSTE
* Segun T D (siendo a=1,b=2 y k=0) a=b^k : O(log N)
	
	23638
	s.acumulado = numero;
	if(numero<=1){
	s.contador=1;}
	s.contador = 0;
	else{
		s = rec(numero/10);
		if(s.acumulado%10==numero%10){
		s.contados++;}
		s.acumulado*=numero%10;}
		return s;
*/

/*
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

vector <vector<int>> vec(int col, int row) {
	vector <vector<int>> v(col, vector<int>(row));

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cin >> v[i][j];
		}
	}
	return v;
}
*/

int falta(const vector<int>v, int i, int f, const int d) {
	//CB
	if (i == f-1) {
		if (v[i] + d == v[f]) {
			return v[f] + d;
		}
		else {
			return v[i] + d;
		}

	else if (i == f) {
		return v[i] + d;
	}
	//CR
	else {
		int m = (i + f) / 2;
		if (v[m] == v[0] + d * m) {
			return falta(v, m, f, d);
		}
		else {
			return falta(v, i, m, d);
		}
	}
}


void resuelveCaso() {
	int n, d;
	cin >> n >> d;

	vector <int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		
	}

	cout << falta(v, 0, n-1, d) << endl;
}

/*

bool resuelveCaso() {
	int col, row;
	cin >> col >> row;
	if (!cin) {
		return false;
	}
	else {

		if (degradado(v, col, row)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
}


}*/

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