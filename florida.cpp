#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int area=0;


void printGrid( ) {
	for( int j=0; j<grid.size(); j++ )
		cout << grid[j] << "\n";
}

void floodfill( int r, int c ) {
   
    int up = r-1, left = c-1, down = r+1, right = c+1;
    int filas = grid.size();
    int cols = grid[0].length(); 

    grid[r][c] = '#';
    area++;
    // Arriba
    if( up>=0 ) {
        if( grid[up][c]=='W'  ) 
        	floodfill( up, c );
    }    
    // Arriba-Izquierda
    if( up>=0 && left>=0 ) {
        if( grid[up][left]=='W'  ) 
        	floodfill( up, left );
    }        
    // Izquierda
    if( left>=0 ) {
        if( grid[r][left]=='W' ) 
        	floodfill( r, left );
    }
    // Abajo-Izquierda
    if( down<filas && left>=0 ) {
        if( grid[down][left]=='W' ) 
        	floodfill( down, left );
    }     
    // Abajo
    if( down<filas ) {
        if( grid[down][c]=='W' ) 
        	floodfill( down, c );
    }    
    // Abajo-derecha
    if( down<filas && right<cols ) {
        if( grid[down][right]=='W' ) 
        	floodfill( down, right );
    }      
    // Derecha
    if( right<cols ) {
        if( grid[r][right]=='W' ) 
        	floodfill( r, right );
    }
 	// Arriba-derecha 
 	if( up>=0 && right<cols ) {
 		if( grid[up][right]=='W' )
 			floodfill( up, right );
 	}
}

int main() {

	int casos;
	scanf("%d", &casos);
	char s = getc(stdin);
	string si;
	getline( cin, si );
	for( int t=0; t<casos; t++ ) {
		vector <string> original;
		grid.clear();
		area=0;
		string linea;
		while( getline( cin, linea ) ) {
			if( linea[0]!='L' && linea[0]!='W' ) 
				break;
			original.push_back( linea );
		}
		while( linea[0]>='0' && linea[0]<='9' ) {
			istringstream ss( linea );
			int fila, col;
			ss >> fila;
			ss >> col;
			grid = original;
			floodfill( fila-1, col-1 );
			//printGrid();
			cout << area << endl; 
			area = 0;
			getline( cin, linea );
		}
		if( t!=casos-1 )
			cout << endl;
	}

	return 0;
}
