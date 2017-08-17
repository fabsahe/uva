#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int mismaFila( char m[5][5], char c1, char c2 ) {
	int fila;
	for( int i=0; i<5; i++ ) {
		for( int j=0; j<5; j++ ) {
			if( m[i][j]==toupper(c1) )
				fila = i;
		}
	}
	for( int j=0; j<5; j++ ) {
		if( m[fila][j]==toupper(c2) ) {
			return fila;
		}
	}
	return -1;
}

int mismaColumna( char m[5][5], char c1, char c2 ) {
	int columna;
	for( int i=0; i<5; i++ ) {
		for( int j=0; j<5; j++ ) {
			if( m[i][j]==toupper(c1) )
				columna = j;
		}
	}	
	for( int i=0; i<5; i++ ) {
		if( m[i][columna]==toupper(c2) ) {
			return columna;
		}
	}
	return -1;
}

void cxf( char m[5][5], char d[2002][2], char c1, char c2, int filam, int filad ) {
	int pos;
	for( int j=0; j<5; j++ ) {
		if( m[filam][j] == toupper( c1 ) ) {
			pos=j;
			if( pos==4 ) {
				pos = -1;
			}
			d[filad][0] = m[filam][pos+1]; 
		}	
		if( m[filam][j] == toupper( c2 ) ) {
			pos=j;
			if( pos==4 ) {
				pos = -1;
			}
			d[filad][1] = m[filam][pos+1]; 
		}		
	}
}

void cxc( char m[5][5], char d[2002][2], char c1, char c2, int colm, int filad ) {
	int pos;
	for( int i=0; i<5; i++ ) {
		if( m[i][colm] == toupper( c1 ) ) {
			pos=i;
			if( pos==4 ) {
				pos = -1;
			}
			d[filad][0] = m[pos+1][colm]; 
		}	
		if( m[i][colm] == toupper( c2 ) ) {
			pos=i;
			if( pos==4 ) {
				pos = -1;
			}
			d[filad][1] = m[pos+1][colm]; 
		}		
	}
}

void cxe( char m[5][5], char d[2002][2], char c1, char c2, int filad ) {
	int pos, fil1, col1, fil2, col2;
	for( int i=0; i<5; i++ ) {
		for( int j=0; j<5; j++ ) {
			if( m[i][j] == toupper(c1) ) {
				fil1 = i;
				col1 = j;
			}
			if( m[i][j] == toupper(c2) ) {
				fil2 = i;
				col2 = j;
			}
		}
	}

	d[filad][0] = m[fil1][col2];
	d[filad][1] = m[fil2][col1];
}

int main() {
	
	int n, i, j;
	char tabla[5][5];
	char digrafo[2002][2];

	scanf("%d", &n);
	char c = getc(stdin);

	for( i=0; i<n; i++ ) {

		int abc[28] = {0};
		char linea[1002];
		char msg[1002];

		fgets(linea, 1002, stdin);
		fgets(msg, 1002, stdin);
		int x=0, y=0;
		// lectura de la frase de cifrado
		for( j=0; j<strlen(linea)-1; j++ ) {

			if( x==5 ) {
				x=0;
				y++;
			}
			if(y==5) break;
			if( linea[j]==' ' ) {
				continue;
			}
			if( abc[linea[j]-97]==0 ) {
				tabla[y][x] = toupper( linea[j] );
				x++;
			}						
			abc[linea[j]-97]=1;
		}

		// relleno de la tabla
		for( j=97; j<=122; j++ ) {
			if( x==5 ) {
				x=0;
				y++;
			}
			if(y==5) break;
			if( j==113 ) continue;

			if( abc[j-97]==0 ) {
				tabla[y][x] = toupper( char(j) );
				x++;
			}
			abc[j-97]=1;
		}
		x=0;
		y=0;
		j=0;
		int cont=0;
		// lectura de la frase a cifrar
		while( j<strlen(msg) ) {
			//printf("analizando %c\n", msg[j]);
			if( msg[j]=='\n' )
				break;
			if( x==2 ) {
				x=0;
				y++;
			}
			if( msg[j]==' ' ) {
				j++;
				continue;
			}
			if( x==1 && digrafo[y][0]==msg[j] ) {
				digrafo[y][x] = 'x';
				x++;
				//cont++;
				continue;
			}
			else {
				digrafo[y][x] = msg[j];
				j++;
				x++;
				cont++;
			}	
		}
		//printf("%d\n", cont);
		if( digrafo[y][1]<97 || digrafo[y][1]>122 )
			digrafo[y][1]='x';

		//printf("ultimo digrafo %c - %c\n", digrafo[y][0], digrafo[y][1] );
		for( j=0; j<=y; j++ ) {
			int fil=0, col=0;
			
			fil = mismaFila( tabla, digrafo[j][0], digrafo[j][1] ); 
			col = mismaColumna( tabla, digrafo[j][0], digrafo[j][1] );

			if( fil >= 0 ) {				
				cxf( tabla, digrafo, digrafo[j][0], digrafo[j][1], fil, j );
			}

			else if( col >= 0 ) {
				cxc( tabla, digrafo, digrafo[j][0], digrafo[j][1], col, j );
			}
			else {
				cxe( tabla, digrafo, digrafo[j][0], digrafo[j][1], j );
			}
			printf("%c%c", digrafo[j][0], digrafo[j][1]);			
		}
		printf("\n");
	}
	return 0;
}
