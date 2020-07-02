#include "erreurs.h"

int main( int argc, char *argv[] )
{
	erreurs f( true, "Nan", "ici", "test" );
	cout << f.getbool() << endl << f.getfichier() << endl << f.getloc()
		 << endl << f.getmsg() << endl;
	return 0;
}
