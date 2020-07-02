#ifndef camera_h
#define camera_h

#include "../vecteur3d/vecteur3d.h"

class camera
{
private:
	vecteur3d position;
	vecteur3d visee;
	vecteur3d verticale;
/*
Pour faire les rotations de la camera, on utilise les angles d euler.
psy est l angle psi, la precession.
philo est l'angle phi, la nutation.
theta est l'angle theta, la rotation propre.
*/
	vecteur3d juste;
	vecteur3d ex;
	double rayon;
/*	long double psy;
	long double philo;
	long double theta;*/
	static int acc;
public:
	vecteur3d getpos() const;
	vecteur3d getvis() const;
	vecteur3d getver() const;
	vecteur3d getjuju() const;
	vecteur3d getex() const;
	void setex( const vecteur3d& v );
	double getrayon() const;//-----------------------------------
	int getacc() const;
	void setrayon( const double& r );//--------------------------
	void setpos( const vecteur3d& v );
	void setvis( const vecteur3d& v );
	void setver( const vecteur3d& v );
	void juju( const vecteur3d& v );
	void laser( const double& r );//------------------------------
	void setpos();
	void setvis();
	void setver();
	void juju();
	void setex();
	void laser();//----------------------------------------------
	camera( const vecteur3d& pos, const vecteur3d& vis, const vecteur3d& ver);
	camera();
	virtual ~camera();
	void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, const camera& c );
	void rotateLeftRight( const long double& w );
	void rotateOverUnder( const long double& w );
	void rotateYourself( const long double& w );
	void straight( const double& x );
	void translatedLeftRight( const double& x );
	void translatedUpDown( const double& x );
};

#endif // camera_h
