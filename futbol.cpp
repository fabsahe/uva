#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef struct eq {
	int puntos;
	int jugados;
	int ganados;
	int empates;
	int perdidos;
	int goles_dif;
	int goles_favor;
	int goles_contra;
	bool operator <( struct eq const& a ) const {
		return puntos < a.puntos;
	}
} Equipo;

template <typename T1, typename T2>
struct comparador {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
    	Equipo aa = a.second;
    	Equipo bb = b.second;
    	string s1 = a.first;
    	string s2 = b.first;
    	transform( s1.begin(), s1.end(), s1.begin(),(int (*)(int))tolower );
		transform( s2.begin(), s2.end(), s2.begin(),(int (*)(int))tolower );

        return aa.puntos > bb.puntos || 
        (aa.puntos==bb.puntos) && (aa.ganados>bb.ganados) ||
        (aa.puntos==bb.puntos) && (aa.ganados==bb.ganados) && (aa.goles_dif>bb.goles_dif) ||
        (aa.puntos==bb.puntos) && (aa.ganados==bb.ganados) && (aa.goles_dif==bb.goles_dif) && (aa.goles_favor>bb.goles_favor) ||
        (aa.puntos==bb.puntos) && (aa.ganados==bb.ganados) && (aa.goles_dif==bb.goles_dif) && (aa.goles_favor==bb.goles_favor) && (aa.jugados<bb.jugados) ||
        (aa.puntos==bb.puntos) && (aa.ganados==bb.ganados) && (aa.goles_dif==bb.goles_dif) && (aa.goles_favor==bb.goles_favor) && (aa.jugados==bb.jugados) && s1 < s2;
    }
};

int main() {

	int i, j, n, t, g;
	string torneo;
	char *ptr;
	scanf("%d", &n);
	char c = getc(stdin);
	for(i=0;i<n;i++) {    			// ciclo de los torneos
		map<string, Equipo> equipos;		
		getline(cin, torneo);
		cout << torneo << "\n";
		scanf("%d", &t);
		c = getc(stdin);
		
		for(j=0;j<t;j++) {			// ciclo de los equipos
			Equipo temp={0};
			string nom_eq;
			
			getline(cin, nom_eq);
			equipos.insert( pair<string, Equipo>(nom_eq, temp) );
		}

		scanf("%d", &g);
		c = getc(stdin);
		for( j=0;j<g;j++ ) {		// ciclo de los juegos
		
			char partido[101];
			fgets(partido,101,stdin);
			
			ptr=strtok(partido,"#@\n\t");			
			string eq1(ptr);

			ptr=strtok(NULL,"#@\n\t");
			int gol1 = atoi(ptr); 

			ptr=strtok(NULL,"#@\n\t");
			int gol2 = atoi(ptr); 

			ptr=strtok(NULL,"#@\n\t");
			string eq2(ptr);
			// se agregan los puntos 
			if( gol1>gol2 ) {
				equipos.at(eq1).puntos += 3;
				equipos.at(eq1).ganados += 1;
				equipos.at(eq2).perdidos += 1;
			}
			else if( gol1<gol2 ) {
				equipos.at(eq2).puntos += 3;
				equipos.at(eq2).ganados += 1;
				equipos.at(eq1).perdidos += 1;
			}
			else {
				equipos.at(eq1).puntos += 1;
				equipos.at(eq2).puntos += 1;
				equipos.at(eq1).empates += 1;
				equipos.at(eq2).empates += 1;
			}
			// se suman los juegos totales
			equipos.at(eq1).jugados += 1;
			equipos.at(eq2).jugados += 1;
			// se suman los goles
			equipos.at(eq1).goles_favor += gol1;
			equipos.at(eq1).goles_contra += gol2;

			equipos.at(eq2).goles_favor += gol2;
			equipos.at(eq2).goles_contra += gol1;

			// se calcula la diferencia de goles
			equipos.at(eq1).goles_dif += gol1-gol2; 
			equipos.at(eq2).goles_dif += gol2-gol1; 

		}
		vector< pair<string, Equipo> > mapac( equipos.begin(), equipos.end() );
		
		sort( mapac.begin(), mapac.end(), comparador<string, Equipo>() );
		int k=1;
		for( vector< pair<string, Equipo> >::iterator it=mapac.begin(); it!=mapac.end(); ++it ) {
			cout << k << ") " << it->first << " "; 
			cout << it->second.puntos << "p, ";
			cout << it->second.jugados << "g ";
			cout << "(" << it->second.ganados;
			cout << "-" << it->second.empates;
			cout << "-" << it->second.perdidos << "), ";
			cout << it->second.goles_dif << "gd " ;			
			cout << "(" << it->second.goles_favor;
			cout << "-" << it->second.goles_contra << ")\n";
			k++;
		}
		if(i<n-1)
			cout << "\n";
	} 
	return 0;
}
