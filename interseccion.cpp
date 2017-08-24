#include <bits/stdc++.h>
#define INFINITO std::numeric_limits<double>::infinity()
using namespace std;

typedef struct ecuacion {
	double m;
	double c;
} EC;

EC punto_punto( double x1, double y1, double x2, double y2  ) {
	EC ecu; 
	if( x1==x2 && y1==y2 ) {
		ecu.m = INFINITO;
		ecu.c = INFINITO;
	}
	else if( x1 != x2 ) {
		ecu.m = (y2-y1)/(x2-x1);
		ecu.c = ecu.m*x1*(-1.0)+y1;		
	}
	else {
		ecu.m = INFINITO;
		ecu.c = x1;
	}
	return ecu;
}
 
int main() {
	
	int casos;
	scanf("%d", &casos);
	for( int i=0; i<casos; i++ ) {
		int band=0;
		double x1, y1, x2, y2;
		double dx1, dx2, ay, by, temp;
		
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &dx1, &ay, &dx2, &by );
			if( dx1 > dx2 ) {
				temp = dx1;
				dx1 = dx2;
				dx2 = temp;
			}
			if (by > ay ) {
				temp = ay;
				ay = by;
				by = temp;
			}
		EC recta[4];
		recta[2] = recta[3] = punto_punto( x1, y1, x2, y2 );
		recta[0] = recta[1] = { 1/recta[2].m, (recta[2].c/recta[2].m)*(-1.0) };

		double fa, fb;
		double delta[] = { dx1, dx2, by, ay };
		double aeval[] = { ay, ay, dx1, dx1 };
		double beval[] = { by, by, dx2, dx2 };
		EC test;
		if( (x1<dx1 && x2<dx1) || (x1>dx2 && x2>dx2) || (y1<by && y2<by) || (y1>ay && y2>ay)  ) {
			//cout << "nel" << endl;
			band=0;
		}
		// busqueda de intersecciones en cada lado, caso normal
		else if( recta[2].m != INFINITO && recta[2].m != 0 ) {
			//cout << "entra aqui" << endl;
			for( int j=0; j<4; j++ ) {
				test.m = recta[j].m;
				test.c = recta[j].c-delta[j];
				fa = test.m*aeval[j] + test.c;
				fb = test.m*beval[j] + test.c;
				//cout << fa << " " << fb << endl;
				if( fa*fb <= 0 ) {
					band=1;		
					break;	
				}
			}			
		}
		// caso de la asintota
		else if( recta[2].m == INFINITO && recta[2].c != INFINITO ) {

			if( recta[2].c >= dx1 && recta[2].c <= dx2 )
				band=1;
		}
		// caso del punto
		else if( recta[2].m == INFINITO && recta[2].c == INFINITO  ) {
			//cout << "a ber" << endl;
			if( (x1 >= dx1 && x1 <= dx2) && ( y1 >= by && y1 <= ay ) )
				band = 1;		
		}
		// caso de la pendiente cero
		else if( recta[2].m == 0 ) {

			if( recta[2].c >= by && recta[2].c <= ay )
				band=1;			
		}

		if( band==0 )
			cout << "F";
		else
			cout << "T";
		//if( i!=casos-1 )
			cout << endl;
	}

	return 0;
}
