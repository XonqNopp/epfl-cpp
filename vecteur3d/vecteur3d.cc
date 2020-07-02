#include "vecteur3d.h"

// constructeur par 3 valeurs donnees
vecteur3d::vecteur3d( const double& a, const double& b, const double& c )
	: x(a), y(b), z(c)
{}

// constructeur par defaut
vecteur3d::vecteur3d()
	:x(0), y(0), z(0)
{}

// constructeur par vecteur3d donné
vecteur3d::vecteur3d( const vecteur3d& v )
	: x( v.getx() ), y( v.gety() ), z( v.getz() )
{}

// destructeur
vecteur3d::~vecteur3d()
{}

// attribution d'une valeur à x
void vecteur3d::setx( const double& a ) { x = a; }

// attribution d'une valeur à y
void vecteur3d::sety( const double& b ) { y = b; }

// attribution d'une valeur à z
void vecteur3d::setz( const double& c ) { z = c; }

// attribution de 3 valeurs à un vecteur3d
void vecteur3d::setvecteur3d( const double& a, const double& b, const double& c )
{
	setx( a );
	sety( b );
	setz( c );
}

// attribution d'un vecteur3d à un vecteur3d
void vecteur3d::setvecteur3d( const vecteur3d& v )
{
	setx( v.getx() );
	sety( v.gety() );
	setz( v.getz() );
}

// donne la valeur x
double vecteur3d::getx() const { return x; }

// donne la valeur y
double vecteur3d::gety() const { return y; }

// donne la valeur z
double vecteur3d::getz() const { return z; }

// l'operateur == teste si le premier vecteur3d est identique au second
bool vecteur3d::operator==( const vecteur3d& v ) const
{
	return ( ( getx() == v.getx() ) &&
			 ( gety() == v.gety() ) &&
			 ( getz() == v.getz() ) );
}

// l'operateur != renvoie teste si les 2 vecteurs sont differents
bool vecteur3d::operator!=( const vecteur3d& v ) const
{
	return ( ( getx() != v.getx() ) &&
			 ( gety() != v.gety() ) &&
			 ( getz() != v.getz() ) );
}

// l'operateur + renvoie la somme de chacune des composantes de 2 vecteur3d donnes
vecteur3d vecteur3d::operator+( const vecteur3d& v ) const
{
	vecteur3d r( getx() + v.getx(), gety() + v.gety(), getz() + v.getz() );
	return r;
}

// l'operateur - renvoie la différence entre chacune des composantes de 2 vecteur3d donnes
vecteur3d vecteur3d::operator-( const vecteur3d& v ) const
{
	vecteur3d r( getx() - v.getx(), gety() - v.gety(), getz() - v.getz() );
	return r;
}

// l'operateur - sans argument apres renvoie l'oppose du vecteur3d donné
vecteur3d vecteur3d::operator-() const
{
	vecteur3d v( -getx(), -gety(), -getz() );
	return v;
}

// l'operateur du produit scalaire
double vecteur3d::operator*( const vecteur3d& v ) const
{
	return ( ( getx() * v.getx() ) +
			 ( gety() * v.gety() ) +
			 ( getz() * v.getz() ) );
}

// l'operateur du produit vectoriel
vecteur3d vecteur3d::operator^( const vecteur3d& v ) const
{
	vecteur3d r;
	r.setx( ( gety() * v.getz() ) - ( getz() * v.gety() ) );
	r.sety( ( getz() * v.getx() ) - ( getx() * v.getz() ) );
	r.setz( ( getx() * v.gety() ) - ( gety() * v.getx() ) );
	return r;
}

// renvoie la norme d'un vecteur3d
double vecteur3d::norme() const
{
	return ( pow( ( getx() * getx() ) +
				  ( gety() * gety() ) +
				  ( getz() * getz() ), 1.0 / 2.0 ) );
}

// l'operateur < teste si le premier vecteur3d est plus petit que le second
bool vecteur3d::operator<( const vecteur3d& v ) const
{
	return ( norme() < v.norme() );
}

// l'operateur > teste si le premier vecteur3d est plus grand que le second
bool vecteur3d::operator>( const vecteur3d& v ) const
{
	return ( norme() > v.norme() );
}

// l'operateur <= teste si le premier vecteur3d est plus petit ou egal au le second
bool vecteur3d::operator<=( const vecteur3d& v ) const
{
	return ( norme() <= v.norme() );
}

// l'operateur >= teste si le premier vecteur3d est plus grand ou egal au le second
bool vecteur3d::operator>=( const vecteur3d& v ) const
{
	return ( norme() >= v.norme() );
}

// l'operateur = met le 2e vecteur3d donné dans le premier
vecteur3d& vecteur3d:: operator=( const vecteur3d& v )
{
	setx( v.getx() );
	sety( v.gety() );
	setz( v.getz() );
}

// l'operateur += renvoie le premier vecteur3d augmenté du second
vecteur3d& vecteur3d::operator+=( const vecteur3d& v )
{
	setx( getx() + v.getx() );
	sety( gety() + v.gety() );
	setz( getz() + v.getz() );
}

// l'operateur -= renvoie le premier vectuer3d soustrait du second
vecteur3d& vecteur3d::operator-=( const vecteur3d& v )
{
	setx( getx() - v.getx() );
	sety( gety() - v.gety() );
	setz( getz() - v.getz() );
}

// l'operateur ++ renvoie le vecteur3d incrémenté de 1
vecteur3d& vecteur3d::operator++()
{
	setx( getx() + 1 );
	sety( gety() + 1 );
	setz( getz() + 1 );
}

// renvoie le vecteur unitaire dans le sens de celui donne
vecteur3d vecteur3d::unitaire() const
{
	vecteur3d r( getx() / norme(), gety() / norme(), getz() / norme() );
	return r;
}

// la fonction d'affichage
void vecteur3d::affiche( ostream& out ) const
{
	out << "( " << getx() << ", " << gety() << ", " << getz() << " )";
}

// l'operateur << affiche le vecteur3d
ostream& operator<<( ostream& out, const vecteur3d& v )
{
	v.affiche( out );
	return out;
}

// l'operateur de multiplication par un scalaire
vecteur3d operator*( const double& a, const vecteur3d& v )
{
	vecteur3d r( a * v.getx(), a * v.gety(), a * v.getz() );
	return r;
}

// la meme chose, mais pour que l'operateur * soit commutatif
vecteur3d operator*( const vecteur3d& v, const double& a )
{
	vecteur3d r( a * v.getx(), a * v.gety(), a * v.getz() );
	return r;
}

// l'operateur de division par un scalaire
vecteur3d operator/( const vecteur3d& v, const double& a )
{
	vecteur3d r( v.getx() / a, v.gety() / a, v.getz() / a );
	return r;
}
