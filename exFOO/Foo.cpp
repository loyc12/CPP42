#include "Foo.hpp" // for class Foo

// Debuggers
void	Foo::debug( bool debug ) { this->_debug = debug; }
bool	Foo::debug( void ) const { return ( this->_debug ); }

// Destructor
Foo::~Foo() { DEBUG( std::cout << "[ Destroying a FOO instance ]\n" ); }

// Constructors
Foo::Foo()
{
	DEBUG( std::cout << "[ Called def. constr. for a FOO instance ]\n" );
	this->_name = "UNINITIALIZED";
	this->_ptrVal = NULL;
}
Foo::Foo( C_STR name )
{
	DEBUG( std::cout << "[ Called param. constr. for a FOO instance ]\n" );
	this->_name = name;
	this->_ptrVal = NULL;
}

// Reconstructors
Foo::Foo( const Foo &other )
{
	DEBUG( std::cout << "[ Called copy constr. for a FOO instance ]\n" );
	this->_name = other._name;
	this->_ptrVal = new int( *other._ptrVal );
}
Foo &Foo::operator= ( const Foo &other )
{
	DEBUG( std::cout << "[ Called assign. oper. for a FOO instance ]\n" );
	if ( this != &other )
	{
		this->_name = other._name;
		this->_ptrVal = new int( *other._ptrVal );
	}
	return ( *this );
}

// Clearers
void	Foo::clearName( void ) { this->_name = "UNINITIALIZED"; }
void	Foo::clearPtrVal( void ) { this->_ptrVal = NULL; }
void	Foo::clearPtr( void ) { delete this->_ptrVal; this->_ptrVal = NULL; }

// Setters
void	Foo::setName( C_STR name ) { this->_name = name; }
void	Foo::setPtrVal( int val ) { this->_ptrVal = new int( val ); }

// Getters
C_STR	Foo::getName( void ) const { return ( this->_name ); }
int		Foo::getPtrVal( void ) const { return ( *this->_ptrVal ); }

// Fetchers
C_STR	&Foo::fetchName( void ) { return ( this->_name ); }
int		&Foo::fetchPtrVal( void ) { return ( *this->_ptrVal ); }
int*	&Foo::fetchPtr( void ) { return ( this->_ptrVal ); }

// Checkers
bool	Foo::checkName() const { return ( this->_name != "UNINITIALIZED" ); }
bool	Foo::checkPtrVal() const { return ( this->_ptrVal != NULL ); }

// Writers
void	Foo::writeName( std::ostream &out ) const { out << this->_name; }
void	Foo::printName( void ) const { this->writeName( std::cout );}

std::ostream &operator<<( std::ostream &out, const Foo &rhs ) { rhs.writeName( out ); return ( out ); }