#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

typedef struct mat {
	int row;
	int col;
} Matriz;

void printStack(stack<int> s) {
	while( !s.empty() ) {
		printf("%c ", s.top());
		s.pop();
	}
	printf("\n");
}

int main() {
	int n, i, j;
	char linea[101];
	vector<Matriz> matrices;
	
	scanf("%d", &n);
	for( i=0;i<n;i++ ) {
		Matriz m;	
		scanf("%s %d %d", linea, &m.row, &m.col);
		matrices.push_back(m);
	}
	int cont=matrices.size()-1;

	char c = getc(stdin);

	while( fgets(linea,101,stdin)!=NULL ) {

		stack<int> pila;
		int a, b, c, d, mult=0, band=1;		
		for( j=0 ; j<strlen(linea) ; j++ ) {
			
			//printStack(pila);
			
			if( linea[j]=='(' ) continue;
			else if( linea[j]==')' ) {
				c = matrices.at( pila.top()-65 ).row;
				d = matrices.at( pila.top()-65 ).col;
				pila.pop();
				a = matrices.at( pila.top()-65 ).row;
				b = matrices.at( pila.top()-65 ).col;
				pila.pop();	
				
				if(  b != c ) {
					printf("error\n");
					band=0;
					break;
				}
				Matriz aux = { a, d };
				matrices.push_back(aux);
				cont++;

				pila.push(cont+65);

				mult+=a*b*d;
				//printf("%d\n", mult);
			}
			else {
				pila.push(linea[j]);
			}
		}
		if(band==1)
			printf("%d\n", mult);
	}
	return 0;
}
