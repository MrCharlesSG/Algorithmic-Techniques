// NOMBRE Y APELLIDOS 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//ESPECIFICA la funcion que resuelve el problema
//
//
//

//PRECONDICION:{&longitud(v)  k>=0 && ParaTodo x :0<=x<n:v[x]>=0}

int resolver(std::vector<int> const& v, int impares,int k) {
	int cont = 0, tot=0;
	int p = 0, f = 0;
	if (k > 0)f = k - 1;
	//INVARIANTE:0<=f<=longitud(v) && 0<=p<longitud(v)
	//&&cont=#p,q:0<=p<=q<
	while (f < v.size())
	{
		
		if (v[f] % 2 != 0) {
			cont++;
		}
		
		if (cont <= impares) {
			tot++;
		}
		f++;
		if (v[p] % 2 != 0) cont--;
		p++;
	}
	

	//F. COTA:long(v)-f
	return tot;
}

//POSTCONDICION:{sol=Max(q,p):0<=q<=p<n && NoMas(v,q,p,k):p-q+1}
//
// 
// 
//				Predicados
// -----------------------------------------------
// 
// TodosPares(v,p,q):Paratodo x: p<=x<=p :v[x]%2==0;
// noMas(v,p,q,k)=NoExisten x,y:p<=x<=y<p:y-x+1>k&&TodosPares(v,q,p);
//


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	int numElems = 0, pares = 0; size_t n; int k;
	int sol = 0;
	std::cin >> numElems;
	cin >> k;
	cin >> pares;
	std::vector<int> v(numElems);
	for (int& i : v) std::cin >> i;
	if (k > 0)sol = resolver(v, pares, k);
	else sol = numElems+1;
	
	std::cout << sol << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}