#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	scanf( "%d", &n );
	for( int i=0; i<n; i++ ) {
		int tren[52] = {0};
		scanf("%d", &l);
		for( int j=0; j<l; j++ ) {
			scanf( "%d", &tren[j] );
		}
		int aux, cambios=0;
		for( int j=1; j<l; j++ ) {
			for( int k=0; k < (l-j); k++ ) {
				if( tren[k] > tren[k+1] ) {
					aux = tren[k];
					tren[k] = tren[k+1];
					tren[k+1] = aux;
					cambios++;				
				}

			}
		}
			cout << "Optimal train swapping takes " << cambios << " swaps." << endl;
	}	
	return 0;
}
