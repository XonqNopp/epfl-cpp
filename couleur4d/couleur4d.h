#ifndef couleur4d_h
#define couleur4d_h

#include <iostream>

using namespace std;


class couleur4d
{
private:
	double rouge;
	double vert;
	double bleu;
	double transp;
public:
	couleur4d( const double& r,
			   const double& v,
			   const double& b,
			   const double& t );
	couleur4d();
	couleur4d( const couleur4d& c );
	virtual ~couleur4d();
	void setr( const double& r );
	void setv( const double& v );
	void setb( const double& b );
	void sett( const double& t );
	void setcouleur( const double& r,
					 const double& v,
					 const double& b,
					 const double& t );
	void setcouleur( const couleur4d& c );
	double getr() const;
	double getv() const;
	double getb() const;
	double gett() const;
	bool operator==( const couleur4d& c ) const;
	couleur4d& operator=( const couleur4d& c );
	void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, const couleur4d& c );
};


#endif // couleur4d_h
