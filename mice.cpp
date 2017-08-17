#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
using namespace std;

typedef struct NodoLista{
    int origen;
    int destino;
    int tiempo;
} N;

typedef struct pareja{
    int tiempo;
    int letra;
    stack <int> ruta;
} P;

int main() {
	int k, n, e, t, m;
	scanf("%d", &k);
	for( int i=0; i<k; i++ ) {
		vector<P> visits;
		list<N> lista;
		scanf( "%d %d %d %d", &n, &e, &t, &m );
		for( int j=0; j<m; j++ ) {

		}

	}

	return 0;
}
