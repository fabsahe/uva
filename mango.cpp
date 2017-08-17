#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int t, n , l, num;
	scanf("%d", &t);
	for( int i=1; i<=t; i++ ) {
		scanf("%d %d", &n, &l);
		int band=1;
		vector<int> plato;
		vector<int> limite;
		int suma=0;
		for( int j=0; j<n; j++ ) {
			scanf("%d", &num);
			plato.push_back(num);
			suma+=num;
		}
		for( int j=0; j<n; j++ ) {
			scanf("%d", &num);
			limite.push_back(num);
			if( num<plato[j] ) band=0;
		}		
		if( suma>l )
			band=0;
		if( band==1 )
			printf( "Case %d: Yes\n", i );
		else
			printf( "Case %d: No\n", i );

	}
	return 0;
}