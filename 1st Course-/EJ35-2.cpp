#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;
/*COSTE 
*		  {co			si n==1	
*	T(N) ={1*(T(n/2) + c* n^0  si n>1
*	b=2, a=1, k=0
* 
*	O(N)= O(n*log(n))
*	
*/
int progre(const arr& v, const int ini, const int fin, const int d, const int p, const bool inversa) {
	if (ini == fin - 1) {
		return v[ini] + d;
	}
	else {
		int m = (ini + fin) / 2, t=p+d*m;
		if (v[m] > t && !inversa || v[m]<t && inversa) {
			return progre(v, ini, m, d, p, inversa);
		}
		else {
			return progre(v, m, fin, d, p, inversa);
		}
	}
}

void resuelveCaso() {
	int n, d;
	cin >> n >> d;
	arr v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int s = progre(v, 0, n, d, v[0], v[0]>v[n-1]);

	cout << s << endl;

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