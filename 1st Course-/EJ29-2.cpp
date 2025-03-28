#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

void mostrar(const arr& s, const int n) {
	for (int i = 0; i < n; i++)
	{
		switch (s[i])
		{
		case 0: cout << "azul "; break;
		case 1: cout << "rojo "; break;
		case 2: cout << "verde "; break;
		}
		
	}
	cout << endl;
}

bool esValida(const arr&s,const arr& numC, const int n, const arr& colores, const int k) {
	//me queden bloques de ese color
	if (colores[s[k]]<0) {
		return false;
	}
	//v<=a
	else if (numC[0] < numC[2]) {
		return false;
	}
	//si las fichas que puedo poner es mayor a la diferencia que quedan de rojos es decir
	// v+a<r al final
	else if ((numC[1]+n-k-1)<= (numC[0]+numC[2])) {
		return false;
	}
	//la primera pieza es roja
	else if (k == 0 && s[k] != 1) {
		return false;
	}
	//no hay dos verdes juntos
	else if (k>0 &&s[k] == s[k - 1] && s[k] == 2) {
		return false;
	}
	return true;
}

void construye(arr& s,arr& numC, const int n, arr& colores, bool& printed, int k){
	for (int i = 0; i < 3; i++)
	{
		s.push_back(i);
		colores[i]--;
		numC[i]++;
		if (esValida(s, numC, n, colores, k)) {
			//casoBase
			if (k == n - 1) {
				mostrar(s, n);
				printed = true;
			}
			//NO es CB 
			else {
				construye(s, numC, n, colores, printed, k+1);
			}
		}
		colores[i]++;
		numC[i]--;
		s.resize(k);
	}
}

bool resuelveCaso() {
	int n, a,r, v;
	cin >> n;
	if (!cin || n==0) {
		return false;
	}
	arr colores(3), s, numC(3);
	cin >> colores[0] >> colores[1] >> colores[2];
	bool printed = false;
	construye(s,numC, n, colores, printed, 0);

	if (!printed) {
		cout << "SIN SOLUCION\n";
	}

	cout << endl;

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