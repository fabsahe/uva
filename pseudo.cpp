#include <bits/stdc++.h>
using namespace std;

bool hayciclo( vector<long> *v, long l ) {
	for( int i=0; i<v->size(); i++ ) {
		if( v->at(i)==l )
			return true;
	}
	return false;
}

int main() {
	long z, i, m, l, ini, next;
	int caso=1;
	while( 1 ) {
		scanf("%ld %ld %ld %ld", &z, &i, &m, &l);
		if( z==0 && i==0 && m==0 && l==0 )
			break;
		int cont=0;
		vector<long> rnd;
		ini = l;
		next = (z*l+i)%m;
		//rnd.push_back(ini);
		//rnd.push_back(next);

		while( !hayciclo( &rnd, next ) ) {
			rnd.push_back(next);
			l = next;	
			next = (z*l+i)%m;

			//sort( rnd.begin(), rnd.end() );
			cont++;
		}
		printf("Case %d: %d\n", caso, cont );
		caso++;
	}

	return 0;
}
