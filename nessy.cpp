#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, a, b;
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) {
		scanf("%d %d", &a, &b);
		while( a%3!=0 )
			a--;
		while( b%3!=0 )
			b--;
		a /= 3;
		b /= 3; 
		printf( "%d\n", a*b );
	}
	return 0;
}
