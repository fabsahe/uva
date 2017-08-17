#include <iostream>
using namespace std;

int main() {
	int num, i=1;

	while( cin >> num ) {

		if( num<0 ) break;

		int suma=1, sumat=2, cont=0;

		if( num==1 )
			cont=0;
		while( suma<num ) {
			suma*=2;
			cont++;
		}

		cout << "Case " << i << ": " << cont << "\n";
		i++;
	}

	return 0;
}