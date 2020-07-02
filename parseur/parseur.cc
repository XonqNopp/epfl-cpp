#include "parseur.h"

// le constructeur par defaut
parseur::parseur()
	:picasso(), run( true ), dessiner( true )
{}

/* Il faut mettre la fonction check directement dans l'execution de la conversion. Si on peut se passer du string intermediaire c'est encore mieux! */
// ce qu'on fait a chaque changement du nom du fichier
void parseur::initialisation( const bool& b )
{
	if( b ){
		settags();
		kirk();
	}
	try{
		check();
		filetostr();
		erasecomments( content );
		while( getcontent().size() != 0 && getrun() ){
			findtag();
		}
	}
	catch( erreurs& er ){
		erreur( er, true );
	}
}

// le consstructeur par argc-argv
parseur::parseur( int argc, char *argv[] )
	:picasso(), file( "universtest.xml" ), run( true ), dessiner( true )
{
	if( argc > 1 && *( argv[ argc - 1 ] ) != '-' ) { file = argv[ argc - 1 ]; }
	initialisation( true );
}

// le constructeur par valeur
parseur::parseur( const string& n )
	: picasso(), file( n ), run( true ), dessiner( true )
{
	if( file == "" ) { file = "universtest.xml"; }
	initialisation( true );
}

// le destructeur
parseur::~parseur()
{
	delete picasso;
}

// les get/set pour le booleen qui pautorise l'execution du programme
void parseur::setrun( const bool& b ) { run = b; }
bool parseur::getrun() const { return run; }

// les get/set pour le booleen qui verifie qu'on ne cree pas 2 dessinables
void parseur::setdessiner( const bool& b ) { dessiner = b; }
bool parseur::getdessiner() const { return dessiner; }

// les get/set pour les balises
void parseur::settags()
{
	tags[ "aga" ] = noo;// pour si la valeur demandee par gettags n'est pas dans la liste
	tags[ "univers>" ] = univ;
	tags[ "corps>" ] = cor;
	tags[ "type>" ] = typ;
	tags[ "nom>" ] = nm;
	tags[ "position>" ] = posi;
	tags[ "vitesse>" ] = vite;
	tags[ "acceleration>" ] = accel;
	tags[ "masse>" ] = mass;
	tags[ "couleur>" ] = coule;
	tags[ "camera>" ] = cam;
	tags[ "oeil>" ] = oei;
	tags[ "visee>" ] = vis;
	tags[ "verticale>" ] = vertic;
	tags[ "pasdetemps>" ] = pdt;
	tags[ "temps>" ] = tem;
}
parseur::tagtype parseur::gettags( const string& s ) { return tags[ s ]; }

// les get/set pour le type de corps
void parseur::kirk()
{
	spock[ "aga" ] = alleluia;// idem que le couple aga noo dans tags
	spock[ "etoile" ] = eto;
	spock[ "planete" ] = pla;
	spock[ "satellite" ] = sat;
}
startrek parseur::enterprise( const string& s ) { return spock[ s ]; }

// les get/set pour le pointeur sur un dessinable
void parseur::setpicasso( dessinable* d ) { picasso = d; }
dessinable* parseur::getpicasso() const { return picasso; }

// les get/set pour le nom du fichier a extraire
void parseur::setfile( const string& n )
{
	file = n;
	initialisation( false );
}
string parseur::getfile() const { return file; }

// a blank robbery ;)
string parseur::robbery( const string& str ) const
{
	string s( str );
	while( s[0] == ' ' ){
		s.replace( 0, 1, "" );
	}
	while( s[ s.size() - 1 ] == ' ' ){
		s.replace( s.size() - 1, 1, "" );
	}
	return s;
}

// retourne la position du prochain espace dans une chaine de caractere
int parseur::findablank( const string& str ) const
{
	return str.find( ' ' );
}

// retourne la position du n-ieme espace dans une chaine de caractere
int parseur::findnblank( const unsigned int& a, const string& str ) const
{
	if( a == 0 )
	{
		return string::npos;
	}else{
		int f( 0 );
		string s( str );
		for( int i( 0 ); i < a; ++i ){
			f += s.find( " " );
			++f;
			s.replace( 0, s.find( " " ) + 1, "" );
		}
		return f ;
	}
}

// convertit le fichier externe en string
void parseur::filetostr() throw( erreurs )
{
	content = "";
	if( getfile() != "" ){
		flux.open( getfile().c_str() );
		if( flux.fail() ){
			string message( "Le fichier *" + getfile() + "* ne peut pas etre ouvert." );
			throw erreurs( false, "parseur.cc", "void filetostr", message );
		}else{
			while( !flux.eof() ){
				string dodu( "" );
				flux >> dodu;
				content += dodu + " ";
			}
		}
	}
}

// retourne le contenu du string dans lequel on a stocke le fichier externe
string parseur::getcontent() const { return content; }

// retourne la prochaine balise d'une chaine de caractere
string parseur::getnxtag( const string& str ) const
{
	string s( str );
	s = robbery( s );
	s.replace( 0, s.find( "<" ) + 1, "" );
	string t( s.substr( 0, s.find( ">" ) + 1 ) );
	return t;
}

// cherche la prochaine balise du string qui contient le fichier externe
void parseur::findtag() throw( erreurs )
{
	content = robbery( content );
	if( content == "" ){
		throw erreurs( false, "parseur.cc", "void findtag", "Le fichier est vide." );
	}else{
		string tag( getnxtag( content ) );
		string cont( tagtotag( tag, content ) );
		matchtag( tag, cont );
	}
}

//cherche la correspondance entre la balise lue et les balises autorisees
void parseur::matchtag( const string& tg, string& cont ) throw( erreurs )
{
	string futur( "" );
	switch( gettags( tg ) ){
		case univ:
			futur = tagtotag( "univers", cont );
			newunivers( futur );
			contenterase( tagtotag( "univers", cont ) );
			break;
		default:
			string message( "La balise " + tg + " n'est pas aurotisee (du moins ici)..." );
			throw erreurs( true, "parseur.cc", "void matchtag", message );
			break;
	}
}

// efface du debut du string principal jusqu'a la chaine de caractere donnee
void parseur::contenterase( const string& str )
{
	content.replace( content.find( str ), str.size(), "" );
}

// fonction d'affichage
void parseur::affiche( ostream& out ) const
{
	out << "Nom du fichier : " << getfile() << endl
		<< "Contenu du fichier : " << getcontent() << endl;
}

// operateur d'affichage
ostream& operator<<( ostream& out, const parseur& p )
{
	p.affiche( out );
	return out;
}

// convertit un entier en string
string parseur::inttostr( const int& i )
{
	ostringstream os;
	os << i;
	return os.str();
}

/* Nous n'avons pas besoin de cette fonction dans le cadre de notre projet
// convertit un string en entier
int parseur::strtoint( const string& s ) throw( erreurs )
{
	int ext( 0 );
	istringstream anubis( s );
	anubis >> ext;
	if( anubis.fail() ){
		anubis.clear();
		string message( s + " n'est pas un entier..." );
		throw erreurs( false, "parseur.cc", "int strtoint", message );
	}
	return ext;
}
*/

// convertit un string en entier positif
unsigned int parseur::strtouint( const string& s ) throw( erreurs )
{
	unsigned int ext( 0 );
	istringstream amon( s );
	amon >> ext;
	if( amon.fail() ){
		amon.clear();
		string message( s + " n'est pas un unsigned int..." );
		throw erreurs( false, "parseur.cc", "unisgned int parseur::strtoint", message );
	}
	return ext;
}

// convertit un string en nombre rationnel
double parseur::strtodbl( const string& s ) throw( erreurs )
{
	double ext( 0 );
	istringstream osiris( s );
	osiris >> ext;
	if( osiris.fail() ){
		osiris.clear();
		string message( s + " n'est pas un double..." );
		throw erreurs( true, "parseur.cc", "double strtodbl", message );
	}
	return ext;
}

/*
void parseur::newdessinable()
{
// Nous n'avons rien a mettre ici dans le cadre de notre projet
}
*/

 // cree un univers
void parseur::newunivers( string& str )
{
	if( !getdessiner() ){
		throw erreurs( true, "parseur.cc", "void newunivers", "Il y a deja un dessinable qui existe." );
	}else{
		setpicasso( new univers() );
		try{
			settmp( betweentags( "temps", str ) );
		}
		catch( erreurs& er ){
			picasso->settemps( 365 );
			erreur( er, false );
			cerr << " -> Toutefois, une valeur de temps par defaut (365) est attribuee a votre univers." << endl;
		}
		try{
			setpdt( betweentags( "pasdetemps", str ) );
		}
		catch( erreurs& er ){
			picasso->setpas( 1 );
			erreur( er, false );
			cerr << " -> Toutefois, une valeur de pas de temps par defaut (1) est attribuee a votre univers." << endl;
		}

		if( getrun() ){
			try{
				while( findatag( "corps", str ) != string::npos ){
					picasso->ajoutcorps( tralala( str ) );
				}
			}
			catch( erreurs& er ){
				if( getpicasso()->empty() ){
					erreur( er, false );
					cerr << " -> Votre univers ne contient donc aucun corps et ne peut par consequent pas etre dessine." << endl;
				}
			}
		}
		try{
			newcamera( betweentags( "camera", str ) );
		}
		catch( erreurs& er ){
			erreur( er, false );
			cerr << " -> La camera sera centree sur le centre de masse de l'univers"
				 << endl;
			picasso->setleviathanvis( getpicasso()->cdm() );
			picasso->setleviathanex();
			picasso->setleviathanver();
		}
		double m( 0 );
		vecteur3d forces;
		bool nul( true );
		for( set< corps* >::iterator i( getpicasso()->begin() ); i != getpicasso()->end(); ++i ){
			forces = vecteur3d( 0.0, 0.0, 0.0 );
			for( set< corps* >::iterator j( getpicasso()->begin() ); j != getpicasso()->end(); ++j ){
				if( ( *j )->geta() != vecteur3d( 0.0, 0.0, 0.0 ) ) { nul = false; }
				if( *i != *j ){
					try{
						forces += ( *i )->interaction(  *j, getpicasso()->g(), true );
					}
					catch( bool& er ){}//*************************************************************************************************************3
				}
			}
			if( nul ){
				( *i )->setattraction( forces );
			}
		}
		setdessiner( false );
	}
}

// cree un corps
corps* parseur::tralala( string& str ) throw( erreurs )
{
	corps* dingdingdong;
	string message( "" );
	int choix( 0 ), nb( 0 );
	string s( tagtotag( "corps", str ) );
	try{
		switch( enterprise( robbery( betweentags( "type", s ) ) ) ){
			case eto:
				dingdingdong = new etoile();
				choix = 1;
				break;
			case pla:
				dingdingdong = new planete();
				choix = 2;
				break;
			case sat:
				dingdingdong = new satellite();
				choix = 3;
				break;
			default:
				message = "Le type " + robbery( betweentags( "type", s ) ) + " n'est pas autorise.";
				throw erreurs( true, "parseur.cc", "corps* tralala", message );
				break;
		}
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> Votre corps sera donc initialise par defaut (planete)." << endl;
		dingdingdong = new planete();
		choix = 2;
	}
	string sonnom( "" );
	try{
		sonnom = betweentags( "nom", s );
	}
	catch( erreurs& er ){
		erreur( er, false );
		vector< string >noms;
		noms.push_back( "PAS DE TYPE" );
		noms.push_back( "etoile #" );
		noms.push_back( "planete #" );
		noms.push_back( "satellite #" );
		bool existepas( true );
		do{
			existepas = true;
			nb = rand()%1000;
			try{
				getpicasso()->findacorps( noms[ choix ] + inttostr( nb ) );
			}
			catch( corps* c ){
				existepas = false;
			}
		}while( !existepas );
		cerr << " -> Toutefois, votre corps aura un nom par defaut ("
			 << noms[ choix ] + inttostr( nb ) << ")." << endl;
		sonnom = noms[ choix ] + inttostr( nb );
	}
	try{
		for( set< corps* >::iterator i( getpicasso()->begin() ); i != getpicasso()->end(); ++i ){
			if( ( *i )->getn() == sonnom ){
				message = "Il existe deja un corps se nommant " + sonnom + ".";
				throw erreurs( false, "parseur.cc", "corps* tralala", message );
				break;
			}
		}
	}
	catch( erreurs& er ){
		erreur( er, false );
	}
	dingdingdong->setn( sonnom );
	try{
		dingdingdong->setp( newvecteur3d( betweentags( "position", s ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> La position de *" << dingdingdong->getn() << "* est donc initialisee aux coordonnees nulles." << endl;
	}
	dingdingdong->cadeauxpos( dingdingdong->getp() );
	try{
		dingdingdong->setv( newvecteur3d( betweentags( "vitesse", s ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> La vitesse de *" << dingdingdong->getn() << "* est donc nulle." << endl;
	}
	dingdingdong->cadeauxvit( dingdingdong->getv() );
	try{
		dingdingdong->seta( newvecteur3d( betweentags( "acceleration", s ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> L'acceleration de *" << dingdingdong->getn() << "* est donc nulle." << endl;
	}
	dingdingdong->cadeauxacc( dingdingdong->geta() );
	try{
		dingdingdong->setm( strtodbl( betweentags( "masse", s ) ) );
	}
	catch( erreurs& er ){
		erreur( er, true );
	}
	try{
		dingdingdong->setc( newcouleur4d( betweentags( "couleur", s ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> La couleur de *" << dingdingdong->getn() << "* sera donc blanche opaque." << endl;
	}
	str.replace( str.find( s ), s.size(), "" );
	return dingdingdong;
}

void parseur::newcamera( const string& str )
{
	picasso->setleviathan( newvecteur3d( betweentags( "oeil", str ) ),
						   newvecteur3d( betweentags( "visee", str ) ),
						   newvecteur3d( betweentags( "verticale", str ) ) );
	picasso->setleviathanjuju();
	picasso->setleviathanlaser();
	picasso->setleviathanex();
	picasso->setleviathanver();
}

// attribue le pas de temps a l'univers
void parseur::setpdt( const string& str )
{
	picasso->setpas( strtodbl( str ) );
}

// attribue le temps a l'univers
void parseur::settmp( const string& str )
{
	picasso->settemps( strtodbl( str ) );
}

// cree un vecteur3d
vecteur3d parseur::newvecteur3d( const string& source )
{
	string src( robbery( source ) );
	vecteur3d v;
	try{
		v.setx( strtodbl( src.substr( 0, findnblank( 1, src ) ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> La valeur sera donc nulle." << endl;
		v.setx( 0.0 );
	}
	try{
		v.sety( strtodbl( src.substr( findnblank( 1, src ),
									  findnblank( 2, src ) -
									  findnblank( 1, src ) ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> La valeur sera donc nulle." << endl;
	}
	try{
		v.setz( strtodbl( src.substr( findnblank( 2, src ),
									  src.size() - findnblank( 2, src ) ) ) );
	}
	catch( erreurs& er ){
		erreur( er, false );
		cerr << " -> La valeur sera donc nulle." << endl;
	}
	return v;
}

// cree une couleur4d
couleur4d parseur::newcouleur4d( const string& source )
{
	string src( robbery( source ) );
	couleur4d c( strtodbl( src.substr( 0, findnblank( 1, src ) ) ),
				 strtodbl( src.substr( findnblank( 1, src ),
									   findnblank( 2, src ) -
									   findnblank( 1, src ) ) ),
				 strtodbl( src.substr( findnblank( 2, src ),
									   findnblank( 3, src ) -
									   findnblank( 2, src ) ) ),
				 strtodbl( src.substr( findnblank( 3, src ),
									   src.size() - findnblank( 3, src ) ) ) );
	return c;
}

// cherche une balise donnee dans la chaine de caractere donnee (entre 2 positions si donnees)
int parseur::findatag( const string& tg, const string& stri,
					   const int& debut, const int& fin ) const throw( erreurs )
{
	int pos( 0 );
	if( tg == "" && stri != "" ){
		throw erreurs( false, "parseur.cc", "int findatag", "Balise vide..." );
	}else if( tg != "" && stri == "" ){
		throw erreurs( false, "parseur.cc", "int findatag", "String vide..." );
	}else if( tg == "" && stri == "" ){
		throw erreurs( false, "parseur.cc", "int findatag", "Balise et string vides..." );
	}else{
		int lafin( 0 );
		if( fin == 0 ){
			lafin = stri.size() - 1;
		}else{
			lafin = fin;
		}
		string tag( "<" + tg );
		string str( stri.substr( debut, lafin + tag.size() - debut ) );
		if( str.find( tag ) == string::npos ){
			string message( "La balise " + tag + " n'est pas dans la chaine de caracteres donnee." );
			throw erreurs( true, "parseur.cc", "int findatag", message );
		}else{
			pos = ( str.find( tag ) + debut );
		}
	}
	return pos;
}

// retourne une chaine de caractere de la balise ouvrante donnee a sa balise fermante
string parseur::tagtotag( const string& tg, const string& str ) throw( erreurs )
{
	if( tg == "" || str == "" ){
		throw erreurs( false, "parseur.cc", "string tagtotag", "Chaine de caractere vide." );
	}else{
		int debut( findatag( tg, str ) );
		int ecart( findatag( "/" + tg, str ) + tg.size() + 3 - debut ); // +3 pour </ et >
		return ( str.substr( debut, ecart ) );
	}
}

// retourne une chaine de caractere donnee entre une balise ouvrante donnee et sa balise fermante
string parseur::betweentags( const string& tg, const string& str ) throw( erreurs )
{
	if( tg == "" || str == "" ){
		throw erreurs( false, "parseur.cc", "string betweentags", "Chaine de caractere vide." );
	}else{
		int debut( findatag( tg, str ) + tg.size() + 2 );// +2 pour < et >
		int ecart( findatag( "/" + tg, str ) - debut );
		return ( str.substr( debut, ecart ) );
	}
}

// efface tous les commentaires presents
void parseur::erasecomments( string& str ) throw( erreurs )
{
	while( str.find( "<!--" ) != string::npos ){
		int debut( str.find( "<!--" ) );
		if( str.find( "-->" ) == string::npos ){
			throw erreurs( false, "parseur.cc", "void erasecomments",
						   "Vous avez ouvert un commentaire sans le fermer." );
		}else{
			int fin( debut + str.substr( debut ).find( "-->" ) + 3 );
			int ecart( fin - debut );
			str.replace( debut, ecart, "" );
		}
	}
}

// gere les erreurs
void parseur::erreur( erreurs& er, const bool& b )
{
	pushloc( er.getloc() );
	if( b ){
		setrun( er.getbool() );
		cerr << "# ERREUR: dans la fonction *" << er.getloc() << "* du fichier -"
			 << er.getfichier() << "- :" << endl << " * ";
	}
	cerr << er.getmsg() << endl;
}

// get/set de la liste des erreurs
void parseur::pushloc( const string& l ) { collection.insert( l ); }
set< string >parseur::getcollection() const { return collection; }

// verifie l'ordre des balises
void parseur::check() const throw( erreurs )
{
	stack< string >verif;
	string toverif( getcontent() );
	toverif = robbery( toverif );
	bool halt( true );
	while( toverif.size() > 0 && halt ){
		string tag( getnxtag( toverif ) );
		char tg( tag[0] );
		switch( tg ){
			case '/':
				tag.replace( 0, 1, "" );
				if( verif.top() != tag ){
					throw erreurs( false, "parseur.cc", "void check",
								   "Desordre dans les balises XML." );
					halt = false;
				}else if( verif.empty() ){
					throw erreurs( false, "parseur.cc", "void check",
								   "Trop de balises fremees." );
					halt = false;
				}else if( verif.top() == tag && !verif.empty() ){
					verif.pop();
				}
				tag = "/" + tag;
				break;
			default:
				verif.push( tag );
				break;
		}
		toverif.replace( 0, findatag( tag, toverif ) + tag.size() + 2 , "" );
		toverif = robbery( toverif );
	}
}


bool parseur::value( const string& str )
{
	// time simu name
	return true;
}






// retourne (si possible) le dessinable cree
dessinable* parseur::extraire() throw( erreurs )
{
	if( getrun() ){
		return getpicasso();
	}else{
		string message( "" );
		if( getcollection().size() == 1 ){
			message = "Il y a des problemes dans la fonction *" + *( getcollection().begin() ) + "*.";
		}else{
			message = "Il y a des problemes dans les fonctions suivantes :";
			for( set< string >::iterator i( getcollection().begin() ); i != getcollection().end(); ++i ){
				message += " - *" + *i + "*";
			}
		}
		erreurs er( false, "parseur.cc", "dessinable* extraire", message );
		throw er;
	}
}
