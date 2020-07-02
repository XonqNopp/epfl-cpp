#include "erreurs.h"

// le constructeur par valeur (pas de constructeur par defaut ni de copie)
erreurs::erreurs( const bool& f, const string& file, const string& l, const string& m )
	:wt( f ), fichier( file ), loc( l ), mesg( m )
{}

// le destructeur
erreurs::~erreurs()
{}

// attribue f au booleen wt
void erreurs::setbool( const bool& f ) { wt = f; }

// attribue m au string mesg
void erreurs::setmsg( const string& m ) { mesg = m; }

// attribue l au string loc
void erreurs::setloc( const string& l ) { loc = l; }

// attribue file au string fichier
void erreurs::setfichier( const string& file ) { fichier = file; }

// retourne la valeur de wt
bool erreurs::getbool() const { return wt; }

// retourne mesg
string erreurs::getmsg() const { return mesg; }

// retourne loc
string erreurs::getloc() const { return loc; }

// retourne fichier
string erreurs::getfichier() const { return fichier; }

