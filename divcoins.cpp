// 562 Dividing coins
// Fabian Salinas Hernandez
#include <bits/stdc++.h>
using namespace std;

int mochila( int cant, vector<int> val, int nelementos ) {
	vector< vector<int> > k;
	k.resize(105);
	int i, w;

	for( i=0; i<=nelementos; i++ ) {
		k[i].resize(60000);
		for( w=0; w <=cant; w++ ) {
			if( i==0 || w==0 )
				k[i][w] = 0;
			else if( val[i-1]<=w )
				k[i][w] = max( val[i-1]+k[i-1][w-val[i-1]], k[i-1][w] );
			else
				k[i][w] = k[i-1][w];
		}
	}
	return k[nelementos][cant];
}

int main() {
	
	int n, m;
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) {
		vector<int> bolsa;
		int moneda, suma=0;
		scanf("%d", &m);
		for( int j=0; j<m; j++ ) {
			scanf("%d", &moneda);
			bolsa.push_back( moneda );
			suma+=moneda;
		}
		int r = mochila( suma/2, bolsa, m );

		int dif = suma - r*2;
		printf("%d\n", dif);
	}

	return 0;
}
