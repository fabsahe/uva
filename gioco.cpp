#include <bits/stdc++.h>
using namespace std;
vector<string> tablero;

void print( ) {
	for( int j=0; j<tablero.size(); j++ )
		cout << tablero[j] << "\n";
}

void avanzar( int fil, int col, char buscar, int *f ) {
	int r = fil;
	int c = col; 
	int filas = tablero.size();
	int cols = tablero[0].length();
    
    if( r==filas-1 )
    	*f = r;
	tablero[r][c] = '#';

    // Arriba
    if( (r-1)>=0 ) {
        if( tablero[r-1][c]==buscar  ) 
        	avanzar( r-1, c, buscar, f );
    }      
    // Arriba-Izquierda
    if( (r-1)>=0 && (c-1)>=0 ) {
        if( tablero[r-1][c-1]==buscar) 
        	avanzar( r-1, c-1, buscar, f );
    }

    // Izquierda
    if( (c-1)>=0 ) {
        if( tablero[r][c-1]==buscar) 
        	avanzar( r, c-1, buscar, f );
    }

	// Abajo
    if( (r+1)<filas ) {
        if( tablero[r+1][c]==buscar ) 
        	avanzar( r+1, c, buscar, f );
    }    
    // Abajo-derecha
    if( (r+1)<filas && (c+1)<cols )
    	if( tablero[r+1][c+1]==buscar )
    		avanzar( r+1, c+1, buscar, f );
    // Derecha
    if( (c+1)<cols ) {
        if( tablero[r][c+1]==buscar ) 
        	avanzar( r, c+1, buscar, f );
    }
}

int main() {
	int n, i, k=1;
	while( scanf("%d", &n)!=EOF && n!=0 ) {
		tablero.clear();
		char c = getc(stdin);
		for( i=1; i<=n; i++ ) {
			string jug;
			cin >> jug;
			tablero.push_back( jug );
		}
		int inf=0, inc=0;
		int fin=-1;
		// caso de las negras
		for( i=0; i<tablero[0].length(); i++ ) {
			if( tablero[0][i]=='b' ) {
				inc=i;
				avanzar( 0, inc, 'b', &fin );
				//print();
				//cout << fin << endl;
				if( fin==n-1 ) {
					cout << k << " " << "B" << endl;
					break;
				}
				else {
					continue;
				}
			}
		}
		if( fin==-1 )
			cout << k << " " << "W" << endl;
		k++;
	}
	return 0;
}
