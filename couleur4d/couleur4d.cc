#include "couleur4d.h"

// constructeur par 4 valeurs donnees
couleur4d::couleur4d( const double& r,
					  const double& v,
					  const double& b,
					  const double& t )
	: rouge( r ), vert( v ), bleu( b ), transp( t )
{}

// constructeur par defaut
couleur4d::couleur4d()
	: rouge( 1.0 ), vert( 1.0 ), bleu( 1.0 ), transp( 1.0 )
{}

// constructeur par couleur4d donné
couleur4d::couleur4d( const couleur4d& c )
	: rouge( c.getr() ), vert( c.getv() ), bleu( c.getb() ), transp( c.gett() )
{}

// destructeur
couleur4d::~couleur4d()
{}

// attribution d'une valeur à rouge
void couleur4d::setr( const double& r ) { rouge = r; }

// attribution d'une valeur à vert
void couleur4d::setv( const double& v ) { vert = v; }

// attribution d'une valeur à bleu
void couleur4d::setb( const double& b ) { bleu = b; }

// attribution de la transparence
void couleur4d::sett( const double& t ) { transp = t; }

// attribution de 4 valeurs a une couleur
void couleur4d::setcouleur( const double& r,
							const double& v,
							const double& b,
							const double& t )
{
	setr( r );
	setv( v );
	setb( b );
	sett( t );
}

// attribution d'une couleur a une couleur
void couleur4d::setcouleur( const couleur4d& c )
{
	setr( c.getr() );
	setv( c.getv() );
	setb( c.getb() );
	sett( c.gett() );
}

// donne la valeur de rouge
double couleur4d::getr() const { return rouge; }

// donne la valeur de vert
double couleur4d::getv() const { return vert; }

// donne la valeur de bleu
double couleur4d::getb() const { return bleu; }

// donne la valeur de la transparence
double couleur4d::gett() const { return transp; }

// l'operateur == teste si la premiere couleur4d est identique a la seconde
bool couleur4d::operator==( const couleur4d& c ) const
{
	return ( ( getr() == c.getr() ) &&
			 ( getv() == c.getv() ) &&
			 ( getb() == c.getb() ) &&
			 ( gett() == c.gett() ) );
}

// l'operateur = met la 2e couleur4d donnée dans la premiere
couleur4d& couleur4d::operator=( const couleur4d& c )
{
	setr( c.rouge );
	setv( c.vert );
	setb( c.bleu );
	sett( c.transp );
}

// la fonction d'affichage
void couleur4d::affiche( ostream& out ) const
{
	out << "( " << getr()
		<< ", " << getv()
		<< ", " << getb()
		<< ", " << gett() << " )";
}

// l'operateur << affiche la couleur4d
ostream& operator<<( ostream& out, const couleur4d& c )
{
	c.affiche( out );
	return out;
}
