#include <bits/stdc++.h>
#define MAX 30002
using namespace std;

	const int monedas[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	long long resultados[MAX];

int main() {

	double n;
	resultados[0]=1;
	for( int i=0; i<11; ++i ) {
		for( int j=monedas[i]; j<MAX; ++j ) {
			resultados[ j ] += resultados[ j - monedas[i] ];
		}
	}

	while( scanf("%lf", &n)!=EOF ) {
		if( n==0.0 ) break;
		int pos = (int)((n+0.001)*100);

		printf("%6.2lf %16lld\n", n, resultados[pos]);
	}
	return 0;
}
