#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
vector <string> m;

void printMaze( ) {
	for( int j=0; j<m.size(); j++ )
		cout << m[j] << "\n";
}

void floodfill( int inifil, int inicol ) {
    int r = inifil;
    int c = inicol;
    int filas = m.size();
    int cols = m[0].length();
    
    m[r][c] = '#';
    // Posicion relativa 1
    if( (r-1)>=0 && (c-1)>=0 ) { 
        if( m[r-1][c-1]==' ') 
        	floodfill( r-1, c-1);
    }
    // Posicion relativa 2
    if( (r-1)>=0 ) {
        if( m[r-1][c]==' ' ) 
        	floodfill( r-1, c );
    }  
    // Posicion relativa 3
    if( (r-1)>=0 && (c+1)<cols ) {
        if( m[r-1][c+1]==' ' ) 
        	floodfill( r-1, c+1 );
    }        
    // Posicion relativa 4
    if( (c-1)>=0 ) {
        if( m[r][c-1]==' ' ) 
        	floodfill( r, c-1 );
    }
    // Posicion relativa 5
    if( (c+1)<cols ) {
        if( m[r][c+1]==' ' ) 
        	floodfill( r, c+1 );
    }
    // Posicion relativa 6
    if( (r+1)<filas && (c-1)>=0 ) {
        if( m[r+1][c-1]==' ' ) 
        	floodfill( r+1, c-1 );
    }  
    // Posicion relativa 7
    if( (r+1)<filas ) {
        if( m[r+1][c]==' ' ) 
        	floodfill( r+1, c );
    }  
    // Posicion relativa 8
    if( (r+1)<filas && (c+1)<cols) {
        if( m[r+1][c+1]==' ' ) 
        	floodfill( r+1, c+1 );
    } 	
}

int main() {
	int i=0, n;
	cin >> n;
	char s = getc(stdin);
	while( i<n ) {
		string linea;
		int j=0, r, c;
		m.clear();
		while(1) {

			getline( cin, linea );
			if( linea[0]!='_' ) {
				m.push_back( linea );
				size_t pos = linea.find("*");
				if( pos!=string::npos ) {
					r = j;
					c = pos;
					linea = linea.replace( pos, 1, "#" );
				}
				j++;
			}
			else {
				i++;
				floodfill( r, c );
				printMaze( );
				cout << linea << "\n";
				break;
			}			
		}
	}
	return 0;
}
