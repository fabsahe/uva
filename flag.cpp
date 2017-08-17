#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n, len;
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) {
		scanf("%d", &len);
		double width = (double)len*6/10;
		double area_r = (double)len*width;
		double area_c = acos(-1)*len*len*0.04;
		area_r -= area_c;
		printf("%.2f %.2f\n", area_c, area_r);
	}

	return 0;
}
