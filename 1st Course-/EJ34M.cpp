#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matriz;

typedef vector<int> arr;

typedef vector<bool> marca;

//aqn == anchuras qn
//aca == anchuras caminos
//cal ==calidades n*m
//ac==conteo actual
//maximo==conteo maximo por ahora
//i == qn
//k== caminos
//man==marca de qn
//mam == marca caminos

void sol(const arr aqn, const arr aca, const matriz cal, int& ac, int& max, int k,marca& mam, const int n, const int m, const arr acum) {
	for (int i = 0; i < m; i++)
	{
		//camino ya ocupado o anchura insuf
		if (!mam[i] && aqn[k] <= aca[i]) {
			//camino inocupado y anchura suf ==> ocupo camino y marco
			ac += cal[k][i];
			mam[i] = true;
			//caso base
			if (k == n - 1) {
				if (ac > max) {
					max = ac;
				}
			}
			else {
				if (ac + acum[k + 1]>max) {
					sol(aqn, aca, cal, ac, max, k + 1, mam, n, m, acum);
				}
			}
			ac -= cal[k][i];
			mam[i] = false;
		}
		//miro al siguiente camino
	}
}

void resuelveCaso() {
	int n,m, a, max=0, ac=0;

	cin >> n >> m;

	arr an(n), am(m),acum, f;//an==anchuras quiN,,, am== acnchuras caminos |||||   acum acumulado
	matriz cal;//ar==artistas   y    p == posiciones
	marca man(n, false), mam(m, false); //man==marca qn ||||  mam==marca caminos

	//rellenamos anchuras qn
	for (int i = 0; i < n; i++)
	{
		cin >> an[i];
	}

	//rellenamos anchura caminos
	for (int i = 0; i < m; i++)
	{
		cin >> am[i];
	}

	//rellenamos calidad y acumulado
	for (int i = 0; i < n; i++)//filas
	{
		for (int j = 0; j < m; j++)//columnas
		{
			cin >> a;
			f.push_back(a);
			if (i == 0) {
				acum.push_back(a);
			}
			else if (a > acum[j]) {
				acum[j] = a;
			}
		}
		cal.push_back(f);
		f.resize(0);
		}
		
	
	//preparamos acumulado
	for (int i = m - 1; i > 0; i--)
	{
		acum[i - 1] += acum[i];
	}
	a = 0;
	sol(an, am, cal, ac, max, a,mam, n, m, acum);
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