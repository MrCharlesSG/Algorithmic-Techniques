#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

using lli = long long int;

lli numGorrasRepartidas(vector<lli> seguidores) {
	PriorityQueue<lli> pq(seguidores);
	lli numGorras=0;
	while (pq.size() > 1)
	{
		lli a = pq.top(); pq.pop();
		lli b = pq.top(); pq.pop();
		lli t = a + b;
		numGorras += t;
		pq.push(t);
	}
	return numGorras;
}



bool resuelveCaso() {
    int N;
    cin >> N;
    if (!cin || N==0) return false;
	vector<lli> seguidores(N);
	for (int i = 0; i < N; i++)
	{
		cin >> seguidores[i];
	}
	cout << numGorrasRepartidas(seguidores) << "\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
