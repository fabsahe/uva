#include <bits/stdc++.h>
using namespace std;

int mochila( int cant, vector<int> val, vector<int> wt, int nelementos ) {
	int k[1000][1000];
	int i, w;
	for( i=0; i<=nelementos; i++ ) {
		for( w=0; w <=cant; w++ ) {
			if( i==0 || w==0 )
				k[i][w] = 0;
			else if( wt[i-1]<=w )
				k[i][w] = max( val[i-1]+k[i-1][w-wt[i-1]], k[i-1][w] );
			else
				k[i][w] = k[i-1][w];
		}
	}
	return k[nelementos][cant];
}

int main() {
	int casos, n;
	scanf("%d", &casos);
	for( int t=0; t<casos; t++ ) {
		vector<int> precios;
		vector<int> pesos;
		int p, w, g, mw;
		scanf("%d", &n);
		for( int i=0; i<n; i++ ) {
			scanf("%d %d", &p, &w);
			precios.push_back(p);
			pesos.push_back(w);
		}
		scanf("%d", &g);
		int suma=0;
		for( int i=0; i<g; i++ ) {
			scanf("%d", &mw);
			suma += mochila( mw, precios, pesos, n );
		} 
		cout << suma << endl;
	}
	return 0;

}