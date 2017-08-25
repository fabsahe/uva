#include <bits/stdc++.h>
#define INFINITO std::numeric_limits<int>::infinity()
using namespace std;

typedef struct nodoG{
    int id;
    int tiempo;
} N;

class comparador{
  public:
    bool operator() (N const &a, N const &b) { return a.tiempo > b.tiempo; }
};

/*
void printVisits(vector<P> visits, int n, int origen){
    printf("Tabla de %d\n", origen);
    for(int i=0; i<n; i++){
        printf("%d  %d  %d\n", origen, visits[i].id, visits[i].tiempo);
       
    }
}*/

int main()  {
	
	int ncasos, n, m, s, t;
	scanf("%d", &ncasos);	
	for( int i=1; i<=ncasos; i++ ) {
		vector<N> grafo[20002];
		scanf( "%d %d %d %d", &n, &m, &s, &t );
		for( int j=0; j<m; j++ ) {
			N nodo; 
			int origen;
			scanf( "%d %d %d", &origen, &nodo.id, &nodo.tiempo );
			N nodo2 = { origen, nodo.tiempo };
			grafo[origen].push_back( nodo );
			grafo[nodo.id].push_back( nodo2 );
		}

		// vector de visitas
		vector<N> visitas;
		for( int j=0; j<n; j++ ) {
			N temp = { j, INFINITO };
			visitas.push_back( temp );
		}

		priority_queue< N, vector<N>, comparador> cola;
		int ini = s;
		N actual = { ini, 0 };
		cola.push(actual);
		visitas[ini].tiempo = 0;

	    while(!cola.empty() && cola.top().id!=t ) {
	        actual = cola.top();
	        cola.pop();
	        vector<N> ady = grafo[ actual.id ];

	        for( int i=0; i<ady.size(); i++ ) {
	            N tmp = { ady[i].id, actual.tiempo+ady[i].tiempo };
	            // relax
	            if(visitas[ ady[i].id ].tiempo == INFINITO || tmp.tiempo < visitas[ ady[i].id ].tiempo ) {
	                cola.push(tmp);
	                visitas[ ady[i].id ].tiempo = tmp.tiempo;
	            }
	            else{
	                //printf("\nNo insertado\n ");
	            }
	        }
	    }
	    //printVisits( visitas, n, ini );
	    if( visitas[t].tiempo!=INFINITO )
	    	printf("Case #%d: %d\n", i, visitas[t].tiempo );
	    else
	    	printf("Case #%d: unreachable\n", i );
	}

	return 0;
}
