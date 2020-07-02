#ifndef parseur_h
#define parseur_h

#include "../univers/univers.h" // dans le cadre de notre projet
#include "../dessinable/dessinable.h" /* de toute facon
										 (les ifndef se chargent de ne
										 pas inclure 2 fois un
										 meme fichier )*/
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

class parseur
{
private:
// les attributs:
	bool run;
	bool dessiner;
	dessinable* picasso;
	ifstream flux;
	string file;
	string content;
	enum tagtype { noo, univ, cor, typ, nm, posi, vite, accel,
				   mass, coule, cam, oei, vis, vertic, pdt, tem,
				   argnom, argsim, argcentre };
	enum init { simu, centr, show };//********************************************************************.
	map< string, tagtype >tags;
	map< string, startrek >spock;
	map< string, init >terminal;
	set< string >collection;
	
// les methodes
	parseur();
	void initialisation( const bool& b );
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
	string robbery( const string& str ) const;
	int findablank( const string& str ) const;
	int findnblank( const unsigned int& a, const string& str ) const;
	void filetostr() throw( erreurs );
	string getcontent() const;
	string getnxtag( const string& str ) const;
	void findtag() throw( erreurs );
	void matchtag( const string& tg, string& cont ) throw( erreurs );
	void contenterase( const string& str );
	void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, const parseur& p );
	string inttostr( const int& i );
//	int strtoint( const string& s ) throw( erreurs );
	unsigned int strtouint( const string& s ) throw( erreurs );
	double strtodbl( const string& s ) throw( erreurs );
//	void newdessinable();
	void newunivers( string& str );
	corps* tralala( string& str ) throw( erreurs );
	void newcamera( const string& str );
	void setpdt( const string& str );
	void settmp( const string& str );
	vecteur3d newvecteur3d( const string& source );
	couleur4d newcouleur4d( const string& source );
	int findatag( const string& tg, const string& stri,
				  const int& debut = 0, const int& fin = 0 ) const throw( erreurs );
	string tagtotag( const string& tag, const string& str ) throw( erreurs );
	string betweentags( const string& tag, const string& str ) throw( erreurs );
	void erasecomments( string& str ) throw( erreurs );
	void erreur( erreurs& er, const bool& b );
	void pushloc( const string& l );
	set< string >getcollection() const;
	void check() const throw( erreurs );
	bool value( const string& str );
	
	
public:
	parseur( const string& n = "" );
	parseur( int argc, char *argv[] );
	virtual ~parseur();	
	dessinable* extraire() throw( erreurs );
};

#endif // parseur_h

