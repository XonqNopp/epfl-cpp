#include "newparseur.h"

int main( int argc, char *argv[] )
{
	newparseur monmien( argc, argv );
	cout << endl << monmien.extraire() << endl;
	return 0;
}
