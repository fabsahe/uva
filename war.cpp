#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<string> img;

void printImg( ) {
	for( int j=0; j<img.size(); j++ )
		cout << img[j] << "\n";
}

void floodfill( int inifil, int inicol ) {
    int r = inifil;
    int c = inicol;
    int filas = img.size();
    int cols = img[0].length();
    
    img[r][c] = '2';
    // Posicion relativa 1
    if( (r-1)>=0 && (c-1)>=0 ) { 
        if( img[r-1][c-1]=='1' ) 
        	floodfill( r-1, c-1);
    }
    // Posicion relativa 2
    if( (r-1)>=0 ) {
        if( img[r-1][c]=='1' ) 
        	floodfill( r-1, c );
    }  
    // Posicion relativa 3
    if( (r-1)>=0 && (c+1)<cols ) {
        if( img[r-1][c+1]=='1' ) 
        	floodfill( r-1, c+1 );
    }        
    // Posicion relativa 4
    if( (c-1)>=0 ) {
        if( img[r][c-1]=='1' ) 
        	floodfill( r, c-1 );
    }
    // Posicion relativa 5
    if( (c+1)<cols ) {
        if( img[r][c+1]=='1' ) 
        	floodfill( r, c+1 );
    }
    // Posicion relativa 6
    if( (r+1)<filas && (c-1)>=0 ) {
        if( img[r+1][c-1]=='1' ) 
        	floodfill( r+1, c-1 );
    }  
    // Posicion relativa 7
    if( (r+1)<filas ) {
        if( img[r+1][c]=='1' ) 
        	floodfill( r+1, c );
    }  
    // Posicion relativa 8
    if( (r+1)<filas && (c+1)<cols) {
        if( img[r+1][c+1]=='1' ) 
        	floodfill( r+1, c+1 );
    } 	
}

int main() {
	int n, i, j, k=1;
	while( scanf("%d", &n) !=EOF ) {
		char s= getc(stdin);
		int cont=0;
		string linea;
		img.clear();
		for( i=0; i<n; i++ ) {
			getline( cin, linea );
			img.push_back(linea);
		}
		int fin=0;
		while( fin==0 ) {
			int band=0;
			fin=0;
			for( i=0; i<n; i++ ) {
				for( j=0; j<n; j++ ) {
					if( img[i][j]=='1' ) {
						band=1;
						break;
					}
				}
				if( band==1 ) break;
			}
			if( i==n && j==n ) {
				fin=1;
				break;
			}

			//printf("encontrado en %d - %d\n", i, j);
			floodfill(i, j);
			cont++;
			//printImg();		
		}
		printf("Image number %d contains %d war eagles.\n", k++, cont );	
	}
	return 0;
}