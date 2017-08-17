#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char s = getc(stdin);
	char e = getc(stdin);
	for(int i=0; i<n; i++) {
		string linea;
		map<string, int> mapita;
		int cont=0;
		while( 1 ) {
			getline(cin, linea);
			if( linea=="" ) break;
			mapita[linea]++;
			cont++;
		}	
		for( map<string, int>::iterator it = mapita.begin(); it!=mapita.end(); it++ ) {
			cout << it->first << " ";
			printf("%.4f\n", (double)it->second/(double)cont*100 );
		}	
		if( i!=(n-1) )
			cout << endl;
	}

	return 0;
}
