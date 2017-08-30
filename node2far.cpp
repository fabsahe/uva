#include <bits/stdc++.h>
#define INFINITO std::numeric_limits<int>::max()
using namespace std;

typedef struct nodoG {
    int id;
    int peso;
} N;

class comparador{
  public:
    bool operator() (N const &a, N const &b) { return a.peso > b.peso; }
};

int contar( map<int, int> visitas, int ttl ) {
	int cont=0;
	for( map<int, int>::iterator it = visitas.begin(); it!=visitas.end(); it++ ) {
        if( it->second>ttl )
        	cont++;
    }
    return cont;
}

map<int, int> clear_visits( map<int, int> visitas ) {
	map<int, int> reset;
    for( map<int, int>::iterator it = visitas.begin(); it!=visitas.end(); it++ )
    	reset[ it->first ] = INFINITO;
    return reset;
}

void print_visits( map<int, int> visitas, int origen){
    printf("Tabla de %d\n", origen);
    for( map<int, int>::iterator it = visitas.begin(); it!=visitas.end(); it++ )
        printf("%d  %d  %d\n", origen, it->first, it->second);
}

int main()  {
	
	int nc, caso=1;
	
	while( scanf("%d", &nc)!=EOF && nc!=0 ) {
		map<int, map< int, int> > grafo;
		map< int, int> visitas;	
		// creacion del grafo
		for( int j=0; j<nc; j++ ) {
			int a, b;
			scanf( "%d %d", &a, &b );

			grafo[a][b] = 1;
			grafo[b][a] = 1;
			// inicializacion del mapa de visitas
			visitas[a] = INFINITO;
			visitas[b] = INFINITO;
		}
		int ini, ttl;
		while( 1 ) {
			visitas = clear_visits( visitas );
			scanf("%d %d", &ini, &ttl);
			if( ini==0 && ttl==0 ) break;
			// comienzo del dijkstra
			priority_queue< N, vector<N>, comparador> cola;
			N actual = { ini, 0 };
			cola.push(actual);
			visitas[ini] = 0;

		    while(!cola.empty() ) {
		        actual = cola.top();
		        cola.pop();
		        map<int, int> ady = grafo[ actual.id ];

		        for( map<int, int>::iterator it = ady.begin(); it!=ady.end(); it++ ) {
		            N tmp = { it->first, actual.peso+it->second };
		            // relax
		            if(visitas[ it->first ] == INFINITO || tmp.peso < visitas[ it->first ] ) {
		                cola.push(tmp);
		                visitas[ it->first ] = tmp.peso;
		            }
		        }
		    }		
		    //print_visits( visitas, ini );
		    int res = contar( visitas, ttl );
		    printf( "Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caso, res, ini, ttl );
		    caso++;
		}
	}
	
	return 0;
}
