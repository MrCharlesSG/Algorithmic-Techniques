#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef int deTres[3];

void mostrar(const vector<int> s) {
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i]) {
		case 0:
			cout << "azul ";
			break;
		case 1:
			cout << "rojo ";
			break;
		case 2:
			cout << "verde ";
			break;
		}
	}
	cout << endl;
}

bool esValida(vector<int> s, deTres col, deTres soll, int n) {
	//hay dos verde juntos?
	if (s[s.size() - 2] == 2 && s[s.size() - 1] == 2) {
		return false;
	}
	else {
		//v<a
		if (soll[2] > soll[0] && soll[2] != 0) {
			return false;
		}
		else {
			//a=los huecos que quedan
			//b la diferencia entre rojos y demas
			//se compara los huecos que quedan y si son suf para reducir esa diferencia
			if (soll[1] - soll[0] - soll[2] <= 0 && abs((soll[1] - soll[0] - soll[2])) >= n - s.size()) {
				return false;
			}
			else {
				return true;
			}
		}

	}
}

void solve(vector<int>& s, deTres& col, deTres& soll, int& n, bool& print) {
	for (int i = 0; i < 3; i++)
	{
		if (col[i] > 0) {
			s.push_back(i);
			soll[i]++;
			col[i]--;
			if (esValida(s, col, soll, n)) {
				if (n == s.size()) {
					print = true;
					mostrar(s);
					int a = s[s.size() - 1];
					soll[a]--;
					col[a]++;
					s.resize(s.size() - 1);
				}
				else {
					solve(s, col, soll, n, print);
				}
			}
			else {
				soll[i]--;
				col[i]++;
				s.resize(s.size() - 1);
			}
		}
	}
	//buscamos otro
	int a = s[s.size() - 1];
	soll[a]--;
	col[a]++;
	s.resize(s.size() - 1);

}

void solucion(vector<int>& s, deTres& col, deTres& soll, int& n) {
	s.push_back(1);
	soll[1]++;
	col[1]--;
	bool print = false;
	solve(s, col, soll, n, print);
	if (!print) {
		cout << "SIN SOLUCION\n";
	}
	cout << endl;
}

bool resuelveCaso() {
	deTres col, soll = { 0 };
	int n;
	vector <int> s;
	cin >> n >> col[0] >> col[1] >> col[2];
	if (n == 0 && col[0] == 0 && col[1] == 0 && col[2] == 0) {
		return false;
	}
	else {
		solucion(s, col, soll, n);
		return true;
	}
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