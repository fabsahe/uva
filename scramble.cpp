#include <bits/stdc++.h>
using namespace std;

string invertir( string s ) {
	char inv[10000];
	int j=0;
	for( int i=s.length()-1; i>=0; i-- ) {
		inv[j] = s[i];
		j++;
	}
	inv[j]='\0';
	string ret(inv);
	return ret;
}

int main() {
	string linea;
	while( getline( cin, linea ) ) {
		int i=0, pe=0;
		int espacios[10000]={0};
		char prev=linea[0];
		// contar espacios
		for( int j=0; j<linea.length(); j++ ) {
			if( linea[j]==' '  ) {
				espacios[pe] += 1;
			}
			else if( linea[j]!=linea[j+1] && linea[j+1]==' ' ) {
				pe++;
			}
		}
		// tokens
		istringstream token(linea);
		while( token ) {
			string s;
			token >> s;
			s = invertir(s);
			for( int k=0; k<espacios[i]; k++ )
				cout << " ";
			cout << s;
			i++;
		}
		cout << endl;
	}
	return 0;
}
