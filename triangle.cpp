#include <iostream>
#include <cstdio>

int main() {
	int n, amplitud, frecuencia, s=0;
	scanf("%d", &n);
	for( int i=0;i<n;i++ ) {
		char c = getc(stdin);
		scanf("%d", &amplitud);
		scanf("%d", &frecuencia);

		for(int j=0;j<frecuencia;j++) {

			if(s!=0)
				printf("\n");
			
			for(int k=1;k<=amplitud;k++) {
				for(int h=0;h<k;h++)
					printf("%d", k);
				printf("\n");	
				s=1;			
			}
			for(int k=amplitud-1;k>0;k--) {
				for(int h=0;h<k;h++)
					printf("%d", k);
				printf("\n");				
			}	

		}
	}
	return 0;
}