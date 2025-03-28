#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
bool sonLosDalton(vector<int> const& v) {

	bool dalton = true;
	bool orden = false;
	int cambio;
	int i = 2;

	if (v[0] == v[1] - 1) {
		orden = true;
	}
	else if (v[0] == v[1] + 1) {
		orden = false;
	}
	else {
		dalton = false;
	}
	cambio = v[1];
	while (i < size(v) && dalton) {
		if (cambio != v[i]) {
			if (orden) {
				if (cambio == v[i] - 1) {
					dalton = true;
				}
				else {
					dalton = false;
				}
			}
			else {
				if (cambio == v[i] + 1) {
					dalton = true;
				}
				else {
					dalton = false;
				}
			}
			cambio = v[i];
			i++;
		}
		else {
			dalton = false;
		}
	}
	return dalton;
}

bool resuelveCaso() {
	int numHermanos;
	cin >> numHermanos;
	if (numHermanos == 0) return false;
	else {
		vector<int>v(numHermanos);
		for (int i = 0; i < numHermanos; i++) {
			cin >> v[i];
		}
		if (sonLosDalton(v)) {
			cout << "DALTON";
		}
		else {
			cout << "DESCONOCIDOS";
		}
		cout << endl;
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
}*/

void res(vector<int> v, long long int& suma, int& num_datos) {
	int  min = v[0], i = 0, usos = 0, aux;
	suma = 0;
	num_datos = v.size();

	while (i < num_datos) {
		aux = v[i];
		if (aux == min) {
			usos++;
		}
		else if (aux < min) {
			suma += usos * min;
			min = aux;
			usos = 1;
		}
		else
			suma += aux;

		i++;
	}
	num_datos -= usos;
}

void resuelveCaso() {
	int num, nun_datos = 0;
	long long int suma = 0;
	cin >> num;
	if (num > 0 && num <= 1000)
	{
		vector<int> v(num);
		for (int i = 0; i < num; i++)
		{
			cin >> v[i];
		}
		res(v, suma, nun_datos);
		cout << suma << " " << nun_datos << endl;
	}
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++)
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