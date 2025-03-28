#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> arr;

typedef vector<arr> matriz;

typedef vector<bool> bule;

/* a)
* P={0<=i<j<=v.sike() y l>=0}
* fun noMas(vector<int> v,int i,int j,int l) return bool b;
* b ={ l>={#k: 0<=i<=k<j<=v.sike() : v[k]%2!=0}
* 
* B)
* 
* P={0<=k<=v.size()}
* boolean TodosPares(vector<int> v, int k) return b;
* b={ forall i: 0<=i<k: v[i]%2==0}
* 
* 
* P={todosPares(v, k) y 0<=k<=n y l>=0 y n=v.size()}
* fun seg(vector<int> v, int n, int k,int l) return int n
* n={#p,q: 0<=p<q<n y q-p=k: noMas(v, q,p, l)}
* 
* 5) O(n)
* 
*/

int seg(const arr& v,const int n, const int k, const int l) {
	int cont = 1, i = k, contI=0;
	while (i < n) {
		if (v[i] % 2 != 0) {
			contI ++;
		}
		if (contI <= l) {
			cont++;
			
		}
		if (v[i - k] % 2 != 0) {
			contI--;
		}
		i++;
	}
	return cont;
}


void resuelveCaso() {
	int n, l, k;
	cin >> n>> k >> l ;
	
	arr v(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	int cont = seg(v, n, k,l);
	cout << cont<< endl;
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