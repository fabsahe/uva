#include <bits/stdc++.h>
using namespace std;

int main() {
	string linea;
	while( getline( cin, linea ) ) {
		for( int i=0; i<linea.length(); i++ ) {
			if( (linea[i]>='A' && linea[i]<='Z') || (linea[i]>='a' && linea[i]<='z') ) {
			}
			else {
				linea[i]=' ';
			}
		}
		istringstream token( linea );
		int cont=0;
		while( token ) {
			string s;
			token >> s;
			cont++;
		}
		cout << cont-1 << endl;
	}
	return 0;
}
