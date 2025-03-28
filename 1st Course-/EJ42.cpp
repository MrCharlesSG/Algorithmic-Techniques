#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

/*
*/

void estilista(const matriz& t, const matriz& z, const int n, int i, int& maximo,
	int actual, const arr& acum, bule& mT, bule&mZ) {
	for (int j = 0; j < n; j++)
	{
		if(mT[j]) {
			mT[j] = false;
			for (int k = 0; k < n; k++)
			{
				if (mZ[k]){
					mZ[k] = false;
					actual += (t[i][j] * z[i][k]);
					//casoBase
					if (i == n - 1) {
						if (maximo < actual) {
							maximo = actual;
						}
					}
					else {
						if (actual + acum[i + 1] > maximo) {
							estilista(t, z, n, i + 1, maximo, actual, acum, mT, mZ);
						}
					}
					actual -= (t[i][j] * z[i][k]);
					mZ[k] = true;
				}
			}
			mT[j] = true;
		}
	}
}


void resuelveCaso() {
	int n,a, max=0;
	matriz t, z;
	cin >> n;
	arr v(n), acum(n), acumz(n);
	bule mt(n);
	for (int i = 0; i < n; i++)
	{
		mt[i] = true;
		for (int j = 0; j < n; j++) {
			cin >> a;
			
			if (j == 0) {
				acum[i] = a;
			}
			else if (acum[i]<a)
			{
				acum[i] = a;
			}
			v[j] = a;
		}
		t.push_back(v);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (j == 0) {
				acumz[i] = a * acum[i];
			}
			else if (acumz[i] < a * acum[i])
			{
				acumz[i] /= acum[i];
				acumz[i] = a* acum[i];
			}
			v[j] = a;
		}
		z.push_back(v);
	}

	for (int i = n - 1; i > 0; i--)
	{
		acumz[i-1] +=acumz[i];
		
	}
	bule mz = mt;
	estilista(t, z, n, 0, max, 0, acumz, mt, mz);
	cout << max << endl;

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