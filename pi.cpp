#include <bits/stdc++.h>
using namespace std;

int MCD( int a, int b ) {
	if( a%b==0 ) return b;
	return MCD(b, a%b);
}

int main() {
	int n, num;
 	while( scanf("%d", &n)!=EOF ) {

 		if( n==0 ) break;
 		int parejas = 0, utiles=0;
 		vector<int> set;
 		for( int i=0; i<n; i++ ) {
 			scanf("%d", &num);
 			set.push_back(num);
 		}
 		for( int i=0; i<n; i++ ) {
 			for( int j=i+1; j<n; j++ ) {
 				if( MCD( set[i], set[j] )==1 ) {
 					utiles++;
 				}
 				parejas++;
 			}
 		}

 		if( utiles==0 ) {
 			printf( "No estimate for this data set.\n" );
 			continue;
 		}

 		double pi = sqrt( 6*(double)parejas/(double)utiles );
 		printf("%.6lf\n", pi );
 	}

	return 0;
}
