#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main() {
	
	int n, i, j, k, c;


	cin >> n;
	char s = getc(stdin);
	for( j=0; j<n; j++ ) {
		string linea;
		vector <string> mat;

		for( i=0; i<10; i++ ) {
			getline( cin, linea );
			linea = linea.substr(1, linea.length()-2);
			if( i!=0 && i!=9 )
				mat.push_back(linea);
		}
		s = getc(stdin);
		for( k=0; k<mat[0].length(); k++ ) {
			for( c=32; c<=126; c++ ) {
				for( i=0; i<mat.size(); i++ ) {
					int v = (c/(int)pow( 2, i ))%2 ;
					if( mat[i][k]==47 && v != 0 ) { // si hay un '/'
						break;
					}
					if( mat[i][k]==92 && v != 1 ) { // si hay un '\'
						break;
					}
				}
				if( i==mat.size() ) {
					printf("%c", c);
					break;
				}
			}			
		}
		cout << "\n";
	}

	return 0;
}
