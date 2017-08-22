#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	while( scanf( "%d", &n )!=EOF ) {
		scanf( "%d", &k );
		if( n==0 && k==0 ) break;
		unsigned long long comb=1;
		int kk = k < (n-k)?k : (n-k);

		for( int i=1; i<=kk; i++ ) {
			comb *= (n-kk+i);
			comb /= i;
		}

		printf("%d things taken %d at a time is %llu exactly.\n", n, k, comb);
	}
	return 0;
}
