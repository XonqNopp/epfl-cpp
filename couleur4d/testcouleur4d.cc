#include "couleur4d.h"

int main()
{
	couleur4d c1;
	couleur4d c2( 1.0, 1.0, 0.0, 0.7 );

//	if( c1 == c2 ){ cout << 'y'; }
//	else{ cout << 'n'; }

//	cout << endl << c2 << endl;

/*	cout << c2.getr();

	cout << c1 << endl;

	c1.setcouleur( 0.0, 0.0, 1.0, 0.5 );

	cout << c1 << endl;

	c1.setcouleur( c2 );

	cout << c1 << endl;

	couleur4d c3( c2 );

	cout << c3 << endl;
*/
	couleur4d c4;

	cout << c2 << endl << c4 << endl;

	c4 = c2;

	cout << c4 << endl;
}
