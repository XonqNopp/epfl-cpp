#include "camera.h"

/*** Constructeur de camera ***/
camera::camera( const vecteur3d& pos, const vecteur3d& vis, const vecteur3d& ver )
	: position(pos), visee(vis), verticale(ver)
{
	juju();
	laser();
	setver( getrayon() * getver().unitaire() );
	setex();
}

camera::camera()
	: position( vecteur3d( 8.0, 6.0, 4.0 ) ),
	  visee( vecteur3d( 1.0, 1.0, 1.0 ) ),
	  verticale( vecteur3d( -0.40824, -0.40824, 0.81649 ) )
{
	juju();
	laser();
	setver( getrayon() * getver().unitaire() );
	setex();

}

/*** Destructeur de camera ***/
camera::~camera()
{}

/*** Facteur d'acceleration modifiable ***/
int camera::acc = 1;

/*** Fonctions "get" pour les attributs ***/
vecteur3d camera::getpos() const { return position; }
vecteur3d camera::getvis() const { return visee; }
vecteur3d camera::getver() const { return verticale; }
vecteur3d camera::getjuju() const { return juste; }
vecteur3d camera::getex() const { return ex; }
double camera::getrayon() const { return rayon; }
int camera::getacc() const { return acc; }

/*** Fonctions set pour attribuer des valeurs au attributs ***/
void camera::setex( const vecteur3d& v ) { ex = v; }
void camera::setrayon( const double& r ) { rayon = r; }
void camera::setpos( const vecteur3d& v ) { position = v; }
void camera::setvis( const vecteur3d& v ) { visee = v; }
void camera::setver( const vecteur3d& v ) { verticale = v; }
void camera::juju( const vecteur3d& v ) { juste = v; }

  /********************* Fonctions set automatiques *************************/
 /***        Elles permettent de mettre a jour les angles et vecteurs  	****/
/****        qui changent lors des modifications de la camera.		  	***/
void camera::setpos() { position = getvis() - getjuju(); }
void camera::setvis() { visee = getpos() + getjuju(); }//???
void camera::setver() { verticale = getrayon() * ( getjuju() ^ getex() ).unitaire(); }
void camera::juju() { juste = getvis() - getpos(); }
void camera::setex() { ex = getrayon() * ( ( getver() ^ getjuju() ).unitaire() ); }
void camera::laser() { rayon = juste.norme(); }

// Fonction d'affichage
void camera::affiche( ostream& out ) const
{
	out << "Position: " << getpos() << endl
		<< "Visee: " << getvis() << endl
		<< "Verticale: " << getver() << endl
		<< "Juste : " << getjuju() << endl
		<< "Ex : " << getex() << endl;
}

// Operateur d'affichage
ostream& operator<<( ostream& out, const camera& c )
{
	c.affiche( out );
	return out;
}

  /********************************************************/
 /********** * * * Fonction des rotations * * * **********/
/********************************************************/
void camera::rotateLeftRight( const long double& w )
{
	vecteur3d j( cos( w ) * getjuju() - sin( w ) * getex() );
	vecteur3d x( sin( w ) * getjuju() + cos( w ) * getex() );
	juju( getrayon() * j.unitaire() );
	setex( getrayon() * x.unitaire() );
}

void camera::rotateOverUnder( const long double& w )
{
	vecteur3d j( cos( w ) * getjuju() - sin( w ) * getver() );
	vecteur3d v( sin( w ) * getjuju() + cos( w ) * getver() );
	juju( getrayon() * ( j.unitaire() ) );
	setver( getrayon() * ( v.unitaire() ) );
}

void camera::rotateYourself( const long double& w )
{
	vecteur3d x( cos( w ) * getex() + sin( w ) * getver() );
	vecteur3d v( cos( w ) * getver() - sin( w ) * getex() );
	setver( getrayon() * v.unitaire() );
	setex( getrayon() * x.unitaire() );
}

  /***************************************************************/
 /********** * * * Fonctions de repositionnement * * * **********/
/***************************************************************/
void camera::straight( const double& x )
{
	juju( getjuju() + getjuju().unitaire() * x * getacc() );
	setrayon( getjuju().norme() );
	setex( getrayon() * getex().unitaire() );
	setver( getrayon() * getver().unitaire() );
}

void camera::translatedUpDown( const double& x )
{
	setvis( getvis() + getver().unitaire() * x * getacc() );
	setpos( getpos() + getver().unitaire() * x * getacc() );
}

void camera::translatedLeftRight( const double& x )
{
	setvis( getvis() + getex().unitaire() * x * getacc() );
	setpos( getpos() + getex().unitaire() * x * getacc() );
}

