#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

/*
*/

void minSuper(const matriz& m, const int pr, const int sp,int k, 
	int& minimo, int actual, const arr& acum, arr& marca) {
	for (int s = 0; s < sp; s++)
	{
		//elijo super s para el producto k
		marca[s]++;
		actual += m[s][k];
		//esValida
		if (marca[s] <= 3) {
			//CB
			if (k == pr - 1) {
				if (actual < minimo) {
					minimo = actual;
				}
			}//Caso Recursivo
			else {
				//podo
				if (actual + acum[k+1] <= minimo) {
					minSuper(m, pr, sp, k + 1, minimo, actual, acum, marca);
				}
				
			}
		}
		//deselegimos
		marca[s]--;
		actual -= m[s][k];
	}
}


void resuelveCaso() {
	int s, p, a, min= 2147483647;
	cin >> s >> p;
	arr v(p);
	matriz m;
	arr acum(p); arr marca(s);

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < p; j++)
		{
			cin >> a;
			if (i == 0) {
				acum[j] = a;
			}
			else if (a < acum[j]) {
				acum[j] = a;
			}
			v[j] = a;
		}
		marca[i] = 0;
		m.push_back(v);
	}

	for (int i = p- 1; i > 0; i--)
	{
		acum[i - 1] += acum[i];
	}
	
	minSuper(m, p, s, 0, min, 0, acum, marca);
	cout << min << endl;
	
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