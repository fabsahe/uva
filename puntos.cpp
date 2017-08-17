#include <bits/stdc++.h>
using namespace std;

double det( double m[3][3] ) {
	double d = m[0][0]*m[1][1]*m[2][2] + m[1][0]*m[2][1]*m[0][2] + m[0][1]*m[1][2]*m[2][0]
			 - m[0][2]*m[1][1]*m[2][0] - m[1][2]*m[2][1]*m[0][0] - m[1][0]*m[0][1]*m[2][2];
	return d;
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	double h, k, r, c, d, e, neg=-1, uno=1;
			
	while( scanf("%lf", &x1)!=EOF ) {
		scanf( "%lf %lf %lf %lf %lf",  &y1, &x2, &y2, &x3, &y3 );
		double md[3][3] = { {x1, y1, uno}, { x2, y2, uno }, {x3, y3, uno} };
		double mx[3][3] = { {neg*(x1*x1+y1*y1), y1, uno}, { neg*(x2*x2+y2*y2), y2, uno}, { neg*(x3*x3+y3*y3), y3, uno} };
		double my[3][3] = { {x1, neg*(x1*x1+y1*y1), uno}, { x2, neg*(x2*x2+y2*y2), uno}, { x3, neg*(x3*x3+y3*y3), uno} };
		double me[3][3] = { {x1, y1, neg*(x1*x1+y1*y1)}, { x2, y2, neg*(x2*x2+y2*y2) }, { x3, y3, neg*(x3*x3+y3*y3) } };

		c = det(mx)/det(md);
		d = det(my)/det(md);
		e = det(me)/det(md);

		h = c*0.5*neg;
		k = d*0.5*neg;
		r = sqrt( h*h + k*k - e );
		// ecuacion ordinaria
		if( h<0 )
			printf("(x + %.3lf)^2 ", ( h*neg ) );
		else if( h>0 )
			printf("(x - %.3lf)^2 ", h );
		else
			printf("x^2 " );
		if( k<0 )
			printf("+ (y + %.3lf)^2 ", (k*neg) );
		else if( k>0 )
			printf("+ (y - %.3lf)^2 ", k);
		else
			printf("+ y^2 ");
		printf("= %.3lf^2\n", r );

		// ecuacion general
		printf( "x^2 + y^2 " );
		if( c < 0 )
			printf( "- %.3lfx ", (c*neg) );
		else if( c>0 )
			printf( "+ %.3lfx ", c );
		if( d < 0 )
			printf( "- %.3lfy ", (d*neg) );
		else if( d>0 )
			printf( "+ %.3lfy ", d );
		if( e < 0 )
			printf( "- %.3lf ", (e*neg) );
		else if( e>0 )
			printf( "+ %.3lf ", e );

		printf("= 0\n\n" );
	}


	return 0;
}