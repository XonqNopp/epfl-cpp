#include "parseur.h"

int main( int argc, char *argv[] )
{
	cout << endl;
	string nom( "" );
	if( argc > 1 ) { nom = argv[ 1 ]; }

	parseur monmien( nom );
/*	while( monmien.getcontent().size() > 1 ){
		try{
			monmien.findtag();
		}
		catch( erreurs er ){
			monmien.erreur( er );
		}
	}
*/
	cout << endl << monmien.extraire() << endl;
	return 0;
}
