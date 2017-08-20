#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	while( scanf( "%d", &n )!=EOF ) {
		scanf( "%d", &k );
		if( n==0 && k==0 ) break;
		unsigned long long comb=1;
		int kk = k < (n-k)?k : (n-k);
		if( kk==1 ) {
			printf("%d\n", n);
			continue;
		}
		for( int i=1; i<=kk; i++ ) {
			comb *= (n-kk+i);
			comb /= i;
		}

		printf("%llu\n", comb);
	}
	return 0;
}
