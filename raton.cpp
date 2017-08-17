#include <iostream>
#include <cstdio>
#include <queue>
#include <list>
using namespace std;

typedef struct NodoLista{
    int origen;
    int destino;
    int tiempo;
} N;

typedef struct pareja{
    int tiempo;
    int id;
} P;

class comparador{
  public:
    bool operator() (P const &a, P const &b) { return a.tiempo > b.tiempo; }
};

list<N>::iterator findFirst(list <N> *lista, int buscar){

    for (list<N>::iterator it=lista->begin(); it!=lista->end(); ++it)
        if(it->origen == buscar)
            return it;
	return lista->begin();
}

bool ordenar(N const &a, N const &b) {
	return ( a.origen > b.origen );	
}

void printVisits(vector<P> visits, int n, int origen){
    printf("Tabla de %d\n", origen);
    for(int i=0; i<n; i++){
        printf("%d  %d  %d\n", origen, visits[i].id, visits[i].tiempo);
       
    }
}

int main() {
	int k, n, e, t, m;
	scanf("%d", &k);
	for( int i=1; i<=k; i++ ) {

		list<N> lista;
		int a, b, c;
		char esp = getc(stdin);
		scanf( "%d %d %d %d", &n, &e, &t, &m );
		// se insertan los nodos de la lista
		for( int j=0; j<m; j++ ) {
			N nodo;
			scanf( "%d %d %d", &nodo.origen, &nodo.destino, &nodo.tiempo );
			lista.push_back(nodo);
		}

		lista.sort( ordenar );
		//printf("Caso %d\n", i+1);
		int ratones=0;

		for( int h=1; h<=n; h++ ) {
			vector<P> visitas;
			// se inicializa el vector de visitas
			for( int j=0; j<n; j++ ) {
				P temp = { -1, j+1 };
				visitas.push_back(temp);
			}

			priority_queue < P, vector<P>, comparador> cola;
		    int ini = h;
		    P actual = { 0, ini };
	    	cola.push(actual);
	    	visitas[ini-1].tiempo = 0;

		    int iter=1;
		    while(!cola.empty() && iter < 101) {
		        actual = cola.top();
		        cola.pop();
		        list<N>::iterator it = findFirst(&lista, actual.id);
		        for (; it!=lista.end()  && it->origen == actual.id; ++it){

		            P tmp = {actual.tiempo+it->tiempo, it->destino};
		            // relax
		            if(visitas[it->destino-1].tiempo == -1 || tmp.tiempo < visitas[it->destino-1].tiempo ) {
		                cola.push(tmp);
		                visitas[it->destino-1].tiempo = tmp.tiempo;
		            }
		            else{
		                //printf("\nNo insertado\n ");
		            }
		        }
		    }
		    if( visitas[e-1].tiempo<=t && visitas[e-1].tiempo!=-1 )
		    	ratones++;
		    //printVisits( visitas, n, ini );
		    //printf("\n");			
		}
		printf( "%d\n", ratones );
		if( i!=k )
			printf("\n");
	}

	return 0;
}
