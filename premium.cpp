#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, f, metros, animales, env;
	scanf("%d", &n);
	for( int i=0; i<n; i++ ) {
		scanf("%d", &f);
		int presupuesto=0, suma=0;
		for( int j=0; j<f; j++ ) {
			scanf("%d %d %d", &metros, &animales, &env);
			presupuesto = metros*env;
			suma+=presupuesto;
		}
		printf("%d\n", suma);
	}
	return 0;
}