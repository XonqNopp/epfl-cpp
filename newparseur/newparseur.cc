#include "newparseur.h"

// Le constructeur par defaut
newparseur::newparseur()
	:picasso(), run( true ), dessiner( true )
{
	settags();
	kirk();
	gotcha();
}

// Le constructeur de copie
newparseur::newparseur( const newparseur& n )
	:picasso( n.getpicasso() ), run( n.getrun() ), dessiner( n.getdessiner() )
{
	settags();
	kirk();
	gotcha();
}

// L'operateur de copie
newparseur& newparseur::operator=( const newparseur& n )
{
	cerr << "This function is not allowed !" << endl;
}

// Le constructeur avec argc et argv
newparseur::newparseur( const int& a, char* b[] )
	:picasso(), file( "universtest.xml" ), run( true ), dessiner( true )
{
	if( a > 1 && *( b[ a - 1 ] ) != '-' ) { file = b[ a - 1 ]; }
}

// Le destructeur
newparseur::~newparseur()
{
	delete picasso;
}

// les get/set pour le booleen qui pautorise l'execution du programme
void newparseur::setrun( const bool& b ) { run = b; }
bool newparseur::getrun() const { return run; }

// les get/set pour le booleen qui verifie qu'on ne cree pas 2 dessinables
void newparseur::setdessiner( const bool& b ) { dessiner = b; }
bool newparseur::getdessiner() const { return dessiner; }

// les get/set pour les balises
void newparseur::settags()
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

newparseur::tagtype newparseur::gettags( const string& s ) { return tags[ s ]; }

// les get/set pour le type de corps
void newparseur::kirk()
{
	spock[ "aga" ] = alleluia;// idem que le couple aga noo dans tags
	spock[ "etoile" ] = eto;
	spock[ "planete" ] = pla;
	spock[ "satellite" ] = sat;
}

startrek newparseur::enterprise( const string& s ) { return spock[ s ]; }

// les get/set pour le pointeur sur un dessinable
void newparseur::setpicasso( dessinable* d ) { picasso = d; }
dessinable* newparseur::getpicasso() const { return picasso; }

// les get/set pour le nom du fichier a extraire
void newparseur::setfile( const string& n ) { file = n; }
string newparseur::getfile() const { return file; }

// gere les erreurs
void newparseur::erreur( erreurs& er, const bool& b )
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
void newparseur::pushloc( const string& l ) { collection.insert( l ); }
set< string >newparseur::getcollection() const { return collection; }

// retourne (si possible) le dessinable cree
dessinable* newparseur::extraire() throw( erreurs )
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

/**************************************************************************/

void newparseur::gotcha() throw( erreurs )
{
	flux.open( getfile().c_str() );
	if( flux.fail() ) {
		string message( "Le fichier *" + getfile() + "* ne peut pas etre ouvert." );
		throw erreurs( false, "newparseur.cc", "void gotcha", message );
	} else {
		while( !flux.eof() ) {
			readfile();
		}
	}
	//catch( errreurs& er ) {
		//erreur( er, false );// Is it right???
	//}
	flux.close();
	// C'est ici que ca se termine :-)
}

void newparseur::readfile() throw( erreurs )
{
	string dodu( "" );
	flux >> dodu;
	if( dodu.substr( 0, 1 ) == "<" ) {
		if( dodu.substr( 1, 1 ) == "/" ) {
			dodu = dodu.substr( 1, dodu.find( ">" ) - 1 );
			checknremove( dodu );
		} else if( dodu.substr( 0, 4 ) == "<!--" ) {
			string comment( "" );
			while( static_cast< int >( comment.find( "-->" ) ) == -1 ) {
				flux >> comment;
			}
		} else {
			dodu = dodu.substr( 2, dodu.find( ">" ) - 2 );
			addtostack( dodu );
			findcase( dodu );
		}
	} else {
		string msg( "Instructions hors balises non autorisees !" );
		throw erreurs( true, "newparseur.cc", "void readfile", msg );
	}
}

void newparseur::addtostack( const string& bal )
{
	checkstack.push( bal );
}

string newparseur::gettopstack() const
{
	return checkstack.top();
}

void newparseur::checknremove( const string& bal ) throw( erreurs )
{
	if( checkstack.top() != bal || checkstack.size() == 0 ) {
		string message( "Desordre dans les balises!" );
		throw erreurs( false, "newparseur.cc", "void checknremove", message );
	}
	checkstack.pop();
}

void newparseur::findcase( const string& bal ) throw( erreurs )
{
	bool coke( false );
	switch( gettags( bal ) ) {
		case univ:
			setpicasso( new univers() );
			picasso -> settemps( 365 );
			picasso -> setpas( 1 );
			break;
		case cor:
			corpse();
			break;
		case cam:
			coke = lsd();
			break;
		case pdt:
			picasso -> settemps( next< double >() );
			break;
		case tem:
			picasso -> setpas( next< double >() );
			break;
		//case argnom:// ???
		//case argsim:// ???
		//case argcentre:// ???
		default:
			string message( "La balise " + bal + " n'est pas aurotisee..." );
			throw erreurs( true, "newparseur.cc", "void findcase", message );
			break;
	}
	if( !coke ) {
		picasso -> setleviathanvis( getpicasso() -> cdm() );
		picasso -> setleviathanex();
		picasso -> setleviathanver();
	}
}

void newparseur::corpse() throw( erreurs )
{
	corps* dingdingdong;
	bool finished( false );
	string dodo( "" );
	while( !finished ) {
		flux >> dodo;
		if( dodo.substr( 0, 1 ) == "<" ) {
			if( dodo.substr( 1, 1 ) == "/" ) {
				dodo = dodo.substr( 1, dodo.find( ">" ) - 1 );
				if( dodo == "corps" ) {
					finished = true;
				}
				checknremove( dodo );
			} else if( dodo.substr( 0, 4 ) == "<!--" ) {
				string comment( "" );
				while( static_cast< int >( comment.find( "-->" ) ) == -1 ) {
					flux >> comment;
				}
			} else {
				dodo = dodo.substr( 2, dodo.find( ">" ) - 2 );
				addtostack( dodo );
				findcorpse( dodo, dingdingdong );
			}
		} else {
			string msg( "Instructions hors balises non autorisees !" );
			throw erreurs( true, "newparseur.cc", "void corpse", msg );
		}
	}
	picasso -> ajoutcorps( dingdingdong );
}

void newparseur::findcorpse( const string& bal, corps* tralala ) throw( erreurs )
{
	string pre( "" ), m( "" );
	vecteur3d pos, vit, acc;
	couleur4d c;
	switch( gettags( bal ) ) {
		case typ:
			typo( tralala );
			break;
		case nm:
			flux >> pre;
			tralala -> setn( pre );
			break;
		case posi:
			pos = extractvec();
			tralala -> setp( pos );
			break;
		case vite:
			vit = extractvec();
			tralala -> setv( vit );
			break;
		case accel:
			acc = extractvec();
			tralala -> seta( acc );
			break;
		case mass:
			flux >> m;
			tralala -> setm( fromstr< double >( m ) );// setmass??
			break;
		case coule:
			c = extractcoul();
			tralala -> setc( c );
			break;
		default:
			string message( "La balise " + bal + " n'est pas aurotisee..." );
			throw erreurs( true, "newparseur.cc", "void findcase", message );
			break;
	}
}

void newparseur::typo( corps* gunter ) throw( erreurs )
{
	string serpette( "planete" );
	flux >> serpette;
	switch( enterprise( serpette ) ) {
		case eto:
			gunter = new etoile();
			break;
		case pla:
			gunter = new planete();
			break;
		case sat:
			gunter = new satellite();
			break;
		default:
			string message( "Le type " + serpette + " n'est pas autorise." );
			throw erreurs( true, "parseur.cc", "corps* tralala", message );
			break;
	}
}

bool newparseur::lsd() throw( erreurs )
{
	string papou( "" );
	bool finished( false ), oeil( false ), visee( false ), verticale( false );
	vecteur3d o, vi, ve;
	while( !finished ) {
		flux >> papou;
		if( papou.substr( 0, 1 ) == "<" ) {
			if( papou.substr( 1, 1 ) == "/" ) {
				papou = papou.substr( 1, papou.find( ">" ) - 1 );
				if( papou == "camera" ) {
					finished = true;
				}
				checknremove( papou );
			} else if( papou.substr( 0, 4 ) == "<!--" ) {
				string comment( "" );
				while( static_cast< int >( comment.find( ">" ) ) == -1 ) {
					flux >> comment;
				}
			} else {
				papou = papou.substr( 2, papou.find( ">" ) - 2 );
				addtostack( papou );
				switch( gettags( papou ) ) {
					case oei:
						oeil = true;
						o = extractvec();
						break;
					case vis:
						visee = true;
						vi = extractvec();
						break;
					case vertic:
						verticale = true;
						ve = extractvec();
						break;
					default:
						string message( "La balise " + papou + " n'est pas aurotisee..." );
						throw erreurs( true, "newparseur.cc", "bool lsd", message );
						break;
				}
			}
		} else {
			string msg( "Instructions hors balises non autorisees !" );
			throw erreurs( true, "newparseur.cc", "void corpse", msg );
		}
	}
	bool isit( oeil && visee && verticale );
	if( isit ) {
		picasso -> setleviathan( o, vi, ve );
		picasso -> setleviathanjuju();
		picasso -> setleviathanlaser();
		picasso -> setleviathanex();
		picasso -> setleviathanver();
	}
	return isit;
}

vecteur3d newparseur::extractvec()
{
	string first( "" ), second( "" ), third( "" );
	flux >> first;
	flux >> second;
	flux >> third;
	vecteur3d vec( fromstr< double >( first ), fromstr< double >( second ), fromstr< double >( third ) );
	return vec;
}

couleur4d newparseur::extractcoul()
{
	string one( "" ), two( "" ), three( "" ), four( "" );
	flux >> one;
	flux >> two;
	flux >> three;
	flux >> four;
	couleur4d c( fromstr< double >( one ), fromstr< double >( two ), fromstr< double >( three ), fromstr< double >( four ) );
	return c;
}


template< class CL >
CL newparseur::fromstr( const string& i )
{
	CL ext;
	std::istringstream icecream( i );
	icecream >> ext;
	return ext;
}

template< class CL >
string newparseur::tostr( const CL& i )
{
	ostringstream os;
	os << i;
	return os.str();
}

template< class CL >
CL newparseur::next()
{
	string text( "" );
	flux >> text;
	return fromstr< CL >( text );
}

