#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

void resuelve(const arr a, int& picos, int& valles,const int n) {
	for (int i = 1; i < n-1; i++)
	{
		if (a[i]< a[i+1] && a[i-1]> a[i]) {
			valles++;
		}
		else if (a[i]> a[i + 1] && a[i - 1]< a[i]) {
			picos++;
		}
		
	}
}

void resuelveCaso() {
	int n;
	

	cin >> n;
	arr a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int picos=0, valles=0;

	resuelve(a, picos, valles,n);
	cout << picos << " " << valles<< endl;

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