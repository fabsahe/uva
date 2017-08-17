#include <iostream>
#include <string>
using namespace std;

int main() {
	int i=1;
	string linea;
	while( cin >> linea ) {
		string lang;
		if( linea=="#" )
			break;
		if( linea=="HELLO" ) 
			lang = "ENGLISH";
		else if( linea=="HOLA" )
			lang = "SPANISH";
		else if( linea=="HALLO" )
			lang = "GERMAN";
		else if( linea=="BONJOUR" )
			lang = "FRENCH";
		else if( linea=="CIAO" )
			lang = "ITALIAN";
		else if( linea=="ZDRAVSTVUJTE" )
			lang = "RUSSIAN";
		else
			lang = "UNKNOWN";
		cout << "Case " << i << ": " << lang << "\n";
		i++;
	}

	return 0;
}