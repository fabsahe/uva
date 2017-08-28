#include <bits/stdc++.h>
using namespace std;

typedef struct racional {
	int num, denom;
} R;

int main() {

	int num, cont=0;
	int row=0, col=0, dir=1;
	vector<R> results;
	results.resize(10000005);

	for( int i=1; i<=10000001; i++ ) {
		if( row<0 ) {
			row++;
			dir=0;
		}
		else if( col<0 && row<10000002 ) {
			col++;
			dir=1;
		}
		else if( row>10000002 ) {
			row--;
			col+=2;
			dir=1;
		}
		else if( col>10000002 ) {
			row+=2;
			col--;
			dir=0;
		}
		R numero = { row+1, col+1 };
		results[i] = numero;
			
		if( dir==1 ) {
			row--;
			col++;
		}
		else {
			row++;
			col--;
		}
	}

	while( scanf("%d", &num)!=EOF ) {

		printf("TERM %d IS %d/%d\n", num, results[num].num, results[num].denom );

	}

	return 0;
}
