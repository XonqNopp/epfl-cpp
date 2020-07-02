#include <iostream>
#include "vecteur3d.h"
using namespace std;

int main()
{
	vecteur3d v1( 1.0, 2.0, -0.1);
	vecteur3d v2( 2.0, 3.0, 4.0);
//	vecteur3d v3( v1 );
	double a(3);
	

	cout << "vecteur 1 : " << v1 << endl << "vecteur 2 : " << v2 << endl;

/*	cout << "v1 v2 = " << ( v1 * v2 ) << endl <<
 *		"v1 ^ v2 = " << ( v1 ^ v2 ) << endl <<
 *		" 3 * v1 = " << ( 3 * v1 ) << endl << endl;*/

/*	cout << "3 * v1 = " << ( 3 * v1 ) << endl
 *		 << "v1 * 3 = " << ( v1 * 3 ) << endl
 *		 << "v1 / 3 = " << ( v1 / 3 ) << endl << endl;*/

/*	cout << "v1 = " << v1 << endl
 *		 << "v1.unitaire() = " << v1.unitaire() << endl
 *		 << "Norme de v1.unitaire() = " << ( v1.unitaire() ).norme() << endl << endl;*/

	++v1;
	cout << "++v1 : " << v1 << endl;
	v1 += v2;
	cout << "v1 += v2 : " << v1 << endl;
	v1 -= v2;
	cout << "v1 -= v2 : " << v1 << endl << endl;
}
