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
bool dDivertido(vector<int> v, int d, int actual, int j) {
	int cont = 0, size=j, i=0;
	bool esDivertido = true;
	while (esDivertido && i < size) {
		if (v[i] == actual)
			cont++;
		if (cont >= d) {
			esDivertido = false;
		}
		i++;
	}
	return esDivertido;
}


void resuelveCaso() {
	int d, size, actual;
	bool esDC = true;

	cin >> d >> size;
	vector<int> v(size);

	cin >> actual;
	v[0] = actual;

	for (int i = 1; i < size; i++)
	{
		cin >> actual;
		if (esDC) {
			if (v[i-1] != actual - 1 && v[i-1] != actual) {
				esDC = false;
			}
			else {
				if (!dDivertido(v, d, actual, i)) {
					esDC = false;
				}
			}
		}
		v[i]=actual;
	}
	if (esDC)
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		resuelveCaso();
	}

		// restablecimiento de cin
#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}