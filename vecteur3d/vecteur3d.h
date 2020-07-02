#ifndef vecteur3d_h
#define vecteur3d_h

#include <iostream>
#include <cmath>
using namespace std;


class vecteur3d {
protected:
	double x;
	double y;
	double z;
public:
	vecteur3d( const double& a, const double& b, const double& c );
	vecteur3d();
	vecteur3d( const vecteur3d& v );
	virtual ~vecteur3d();
	void setx( const double& a );
	void sety( const double& b );
	void setz( const double& c );
	void setvecteur3d( const double& a, const double& b, const double& c );
	void setvecteur3d( const vecteur3d& v );
	double getx() const;
	double gety() const;
	double getz() const;
	bool operator==( const vecteur3d& v ) const;
	bool operator!=( const vecteur3d& v ) const;
	vecteur3d operator+( const vecteur3d& v ) const;
	vecteur3d operator-( const vecteur3d& v ) const;
	vecteur3d operator-() const;
	double operator*( const vecteur3d& v ) const;
	vecteur3d operator^( const vecteur3d& v ) const;
	double norme() const;
	bool operator<( const vecteur3d& v ) const;
	bool operator>( const vecteur3d& v ) const;
	bool operator<=( const vecteur3d& v ) const;
	bool operator>=( const vecteur3d& v ) const;
	vecteur3d& operator=( const vecteur3d& v );
	vecteur3d& operator+=( const vecteur3d& v );
	vecteur3d& operator-=( const vecteur3d& v );
	vecteur3d& operator++();
	vecteur3d unitaire() const;
	void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, const vecteur3d& v );
	friend vecteur3d operator*( const double& a, const vecteur3d& v );
	friend vecteur3d operator*( const vecteur3d& v, const double& a );
	friend vecteur3d operator/( const vecteur3d& v, const double& a );
};


#endif // vecteur3d_h

