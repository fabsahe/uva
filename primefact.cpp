#include <bits/stdc++.h>
#define MAX std::numeric_limits<int>::max()
using namespace std;

void criba( vector<int> *primos, int n ) {
	vector <int> numeros( n, 0 );
	int fin = (int)ceil( sqrt(n) );

	for( int i=2; i<=fin; i++ ) {
		if( numeros[i]==0 ) {
			for( int j=i; j<=n/i; j++ )
				numeros[i*j] = 1;
		}
	}
	for( int i=2; i<n; i++ )
		if( numeros[i]==0 )
			(*primos).push_back( i );
}

int main() {

	vector<int> primos;
	int n = sqrt(MAX)+10;
	criba( &primos, n );

	int num;
	while( scanf("%d", &num)!=EOF && num!=0 ) {
		int j=0, cont=0;
		cout << num << " = ";
		if( num<0 ) {
			cout << "-1 x ";
			num *= -1;
		}

		while( num>1 && j<primos.size() ) {
			if( num%primos[j]==0 ) {
				if( cont!=0 ) 
					cout << " x ";
				cout << primos[j];
				num /= primos[j];
				cont++;
			}
			else {
				j++;
			}
		}
		if( cont==0 ) cout << num;
		cout << endl;		
	}
	return 0;
}
