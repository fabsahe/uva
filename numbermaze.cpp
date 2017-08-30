#include <bits/stdc++.h>
#define T 1000
#define INFINITO std::numeric_limits<int>::max()
using namespace std;

struct N {
	int f, c, suma;
};

struct compara {
	public:
		bool operator()(N const &a, N const &b){
			return a.suma > b.suma;
		}
};

void leer(int m[T][T], int f, int c);
void reset(int m[T][T], int f, int c);
void dijkstra(int m[T][T], int f, int c);

int main(){
	int ncasos, f, c, m[T][T];
	scanf("%d", &ncasos);

	while(ncasos--){
		scanf("%d %d", &f, &c);
		leer(m, f, c);
		dijkstra(m, f, c);
	}
	return 0;
}

void leer(int m[T][T], int f, int c){
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++)
			scanf("%d", &m[i][j]);
	}
}

void dijkstra(int m[T][T], int f, int c){
	int v[T][T];
	reset(v, f, c);

	//cola de prioridad
	priority_queue <N, vector<N>, compara> q;
	N actual={0, 0, m[0][0]};
	q.push(actual);
	//matriz de sumas
	v[0][0]=m[0][0];

	while(!q.empty()){
		actual = q.top();
		q.pop();
		//printf("(%d, %d) s:%d\n", actual.f , actual.c, actual.suma);
		if(f-1==actual.f  && c-1==actual.c) {
			printf("%d\n", actual.suma );
			return;
		}
		//derecha
		if(actual.c < c-1 && v[actual.f][actual.c]+m[actual.f][actual.c+1]<v[actual.f][actual.c+1]){
			N tmp = {actual.f, actual.c+1, v[actual.f][actual.c]+m[actual.f][actual.c+1]};
			q.push(tmp);
			v[actual.f][actual.c+1]=v[actual.f][actual.c] + m[actual.f][actual.c+1];
		}
		//izquierda
		if(actual.c > 0 && v[actual.f][actual.c]+m[actual.f][actual.c-1]<v[actual.f][actual.c-1]){
			N tmp = {actual.f, actual.c-1, v[actual.f][actual.c]+m[actual.f][actual.c-1]};
			q.push(tmp);
			v[actual.f][actual.c-1]=v[actual.f][actual.c] + m[actual.f][actual.c-1];
		}
		//abajo
		if(actual.f < f-1 && v[actual.f][actual.c]+m[actual.f+1][actual.c]<v[actual.f+1][actual.c]){
			N tmp = {actual.f+1, actual.c, v[actual.f][actual.c]+m[actual.f+1][actual.c]};
			q.push(tmp);
			v[actual.f+1][actual.c]=v[actual.f][actual.c] + m[actual.f+1][actual.c];
		}
		//arriba
		if(actual.f > 0 && v[actual.f][actual.c]+m[actual.f-1][actual.c]<v[actual.f-1][actual.c]){
			N tmp = {actual.f-1, actual.c, v[actual.f][actual.c]+m[actual.f-1][actual.c]};
			q.push(tmp);
			v[actual.f-1][actual.c]=v[actual.f][actual.c] + m[actual.f-1][actual.c];
		}
	}
}

void reset(int m[T][T], int f, int c) {
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++)
			m[i][j]=INFINITO;
	}
}
