#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<string> grid;

void printGrid( ) {
	for( int j=0; j<grid.size(); j++ )
		cout << grid[j] << "\n";
}

void floodfill( int inifil, int inicol ) {
    int r = inifil;
    int c = inicol;
    int filas = grid.size();
    int cols = grid[0].length();
    
    grid[r][c] = '2';

    // Arriba
    if( (r-1)>=0 ) {
        if( grid[r-1][c]=='x' || grid[r-1][c]=='@'  ) 
        	floodfill( r-1, c );
    }      
    // Izquierda
    if( (c-1)>=0 ) {
        if( grid[r][c-1]=='x' || grid[r][c-1]=='@' ) 
        	floodfill( r, c-1 );
    }
    // Abajo
    if( (r+1)<filas ) {
        if( grid[r+1][c]=='x' || grid[r+1][c]=='@' ) 
        	floodfill( r+1, c );
    }    
    // Derecha
    if( (c+1)<cols ) {
        if( grid[r][c+1]=='x' || grid[r][c+1]=='@' ) 
        	floodfill( r, c+1 );
    }
 
}

int main() {
	int t, n;
	scanf( "%d", &t );
	for( int i=0; i<t; i++ ) {
		grid.clear();
		scanf( "%d", &n );
		char salto = getc(stdin);
		for( int j=0; j<n; j++ ) {
			string linea;
			getline( cin, linea );
			grid.push_back(linea);
		}
		//printGrid();
		int fin=0, r, c, cont=0;
		while( fin==0 ) {
			int band=0;
			fin=0;
			for( r=0; r<n; r++ ) {
				for( c=0; c<n; c++ ) {
					if( grid[r][c]=='x' ) {
						band=1;
						break;
					}
				}
				if( band==1 ) break;
			}
			if( r==n && c==n ) {
				fin=1;
				break;
			}

			//printf("encontrado en %d - %d\n", r, c);
			floodfill(r, c);
			cont++;
			//printGrid();		
		}
		cout << "Case " << i+1 << ": " << cont << endl;		
	}

	return 0;
}

