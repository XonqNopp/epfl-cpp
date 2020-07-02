#ifndef parseur_h
#define parseur_h

#include "../univers/univers.h"
#include "../dessinable/dessinable.h"
#include "../erreurs/erreurs.h"
#include <fstream>
#include <sstream>
#include <map>
#include <stack>

// cree l'enum s'il ne l'a pas deja cree ailleurs
#ifndef star
#define star
enum startrek { alleluia, eto, pla, sat, ast };
#endif // star

class newparseur
{
private:
// les attributs:
	bool run;
	bool dessiner;
	dessinable* picasso;
	ifstream flux;
	string file;
	enum tagtype { noo, univ, cor, typ, nm, posi, vite, accel,
				   mass, coule, cam, oei, vis, vertic, pdt, tem };
	enum init { simu, centr, show };//*************************************.
	map< string, tagtype > tags;
	map< string, startrek > spock;
	map< string, init > terminal;
	set< string > collection;// ???
	stack< string > checkstack;
	
// les methodes
	newparseur();
	newparseur( const newparseur& n );
	newparseur& operator=( const newparseur& n );
	void setrun( const bool& b );
	bool getrun() const;
	void setdessiner( const bool& b );
	bool getdessiner() const;
	void settags();
	tagtype gettags( const string& s );
	void kirk();
	startrek enterprise( const string& s );
	void setpicasso( dessinable* d );
	dessinable* getpicasso() const;
	void setfile( const string& n );
	string getfile() const;
	void erreur( erreurs& er, const bool& b );
	void pushloc( const string& l );
	set< string >getcollection() const;
//	void newdessinable();
	//void newunivers( string& str );
	//corps* tralala( string& str ) throw( erreurs );
	//void newcamera( const string& str );
	//void setpdt( const string& str );
	//void settmp( const string& str );
	//bool value( const string& str );
	void gotcha() throw( erreurs );
	void readfile() throw( erreurs );
	void addtostack( const string& bal );
	string gettopstack() const;
	void checknremove( const string& bal ) throw( erreurs );
	void findcase( const string& bal ) throw( erreurs );
	void corpse() throw( erreurs );
	void findcorpse( const string& bal, corps* tralala ) throw( erreurs );
	void typo( corps* gunter ) throw( erreurs );
	bool lsd() throw( erreurs );
	vecteur3d extractvec();
	couleur4d extractcoul();
	template< class CL >
	CL fromstr( const string& i );
	template< class CL >
	string tostr( const CL& i );
	template< class CL >
	CL next();
	
	
public:
	newparseur( const string& n = "" );
	newparseur( const int& a, char *b[] );
	virtual ~newparseur();	
	dessinable* extraire() throw( erreurs );
};

#endif // parseur_h

