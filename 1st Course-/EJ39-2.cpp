#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

/*
*/

void casanova(const arr& v, const arr& p, const int n, const int d, const arr& acum,
	int k, int d1, int d2, int love, int&maxLove) {

	for (int i = 0; i < 2; i++)
	{
		//elegimos cara para la cancion
		if (i == 0) 
			d1 += v[k];
		else 
			d2 += v[k];
		love += p[k];
		if (d1 <= d && d2 <= d) {
			//caso base
			if (k == n - 1 && love > maxLove) {
				maxLove = love;
			}
			else {
				if (love > maxLove)
					maxLove = love;
				if (love + acum[i + 1] >= maxLove) {
					casanova(v, p, n, d, acum, k + 1, d1, d2, love, maxLove);
				}
			}
		}
		//deshago
		if (i == 0)
			d1 -= v[k];
		else
			d2 -= v[k];
		love -= p[k];
		
	}
}


bool resuelveCaso() {
	int d, n, ml=0;
	cin >> n;
	if (n == 0) {
		return false;
	}
	cin >> d;
	arr v(n), acum, punt(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i]>> punt[i];
	}
	acum = punt;
	for (int i = n - 1; i > 0; i--)
	{
		acum[i - 1] += acum[i];
	}

	casanova(v, punt, n, d, acum, 0, 0, 0, 0, ml);
	cout << ml << endl;

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