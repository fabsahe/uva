#include <bits/stdc++.h>
using namespace std;

int main() {
	string linea;
	while( getline(cin, linea) ) {
		map<char, int> mapa;
		for( int i=0; i<linea.length(); i++ ) {
			mapa[linea[i]]++;
		}
		int max=0;
		char c;
		for( map<char, int>::iterator it = mapa.begin(); it!=mapa.end(); it++) {
			if( it->second > max && ( (it->first>='A' && it->first<='Z') || (it->first>='a' && it->first<='z') ) ) {
				max = it->second;
				c = it->first;
			}
		}
		vector<char> res;
		for( map<char, int>::iterator it = mapa.begin(); it!=mapa.end(); it++) {
			if( it->second == max && ( (it->first>='A' && it->first<='Z') || (it->first>='a' && it->first<='z') ) ) {
				res.push_back(it->first);
			}
		}		
		for( int i=0; i<res.size(); i++ )
			cout << res[i];
		cout << " " << max << endl;

	}	

}
