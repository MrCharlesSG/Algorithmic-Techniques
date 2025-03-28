#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*bool res(vector<int>& v, int D) {
	int i = 0, size = v.size(), desnivel = 0;
	bool apto = true;
	while (i < size-1 && apto) {
		if (v[i]<v[i+1])
		{
			desnivel += v[i + 1] - v[i];
			if (desnivel > D) {
				apto = false;
			}
			else
				i++;
		}
		else {
			desnivel = 0;
			i++;
		}
	}
	return apto;
}*/

bool resuelveCaso() {
	int  desnivel = 0, D, num;
	bool apto = true;
	cin >> D;
	if (!cin) {
		return false;
	}
	else {
		cin >> num;
		vector<int> v(num);
		cin >> v[0];
		for (int i = 1; i < num; i++)
		{
			cin >> v[i];

			if (v[i] > v[i - 1])
			{
				desnivel += v[i] - v[i - 1];
			}
			else {
				desnivel = 0;
			}

			if (desnivel > D) {
				apto = false;
			}
		}
		if (apto) {
			cout << "APTA\n";
		}
		else
			cout << "NO APTA\n";
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
	return 0;
}