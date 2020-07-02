#ifndef erreurs_h
#define erreurs_h

#include <iostream>
#include <string>

using namespace std;

class erreurs
{
private:
	bool wt;
	string fichier;
	string loc;
	string mesg;
public:
	erreurs( const bool& b,
			 const string& f = "",
			 const string& l = "",
			 const string& m = "" );
	~erreurs();
	void setbool( const bool& b );
	void setmsg( const string& m );
	void setloc( const string& l );
	void setfichier( const string& f );
	bool getbool() const;
	string getmsg() const;
	string getloc() const;
	string getfichier() const;
	
};

#endif // erreurs_h
