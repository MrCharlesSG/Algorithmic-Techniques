#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;
/*
P={0<=p<q<= v.size()}
fun todosPares(v, p, q) return boolean b
Q={b=(paratodo i: p<=i<q : v[i]%2=0)}

P={0<=n y n==v.size()}
fun segmentosPares (v, n) return int a;
Q={a=(#i, w:  0<=i<w<=n : todosPares(v, i, w)}

coste asintótico
	O (n)

INVARIANTE={ cont=(#k, w:  0<=k<w<=i : todosPares(v, k, w)) y tam= (#u : 0<=u<=i: todosPares(v, u, i))}

COTA: n
*/
int segmentosPares(const arr& v, const int n) {
	int tam = 0, cont = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] % 2 == 0) {
			tam++;
		}
		else {
			cont = cont + tam * (tam + 1) / 2;
			tam = 0;
		}
	}
	if (tam > 0) {
		cont = cont + tam * (tam + 1) / 2;
	}
	return cont;
}

void resuelveCaso() {
	int n;
	cin >> n;
	arr v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int s = segmentosPares(v, n);

	cout << s << endl;
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