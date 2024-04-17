#include "Foo.hpp"

// Debuggers
void Foo::debug( bool debug ) { this->_debug = debug; }
bool Foo::debug( void ) const { return ( this->_debug ); }

// Constructors - Destructor
Foo::Foo()
{
	this->_debug = false;

	if_DBG std::cout << "[ Called def. constr. for a FOO instance ]\n";

	this->name = "UNINITIALIZED";
}
Foo::Foo( const std::string _name )
{
	this->_debug = false;

	if_DBG std::cout << "[ Called param. constr. for a FOO instance ]\n";

	this->name = _name;
}
Foo::Foo( const Foo &other )
{
	if_DBG std::cout << "[ Called copy constr. for a FOO instance ]\n";

	this->name = other.getName();
	this->_debug = other.debug();
}
Foo::~Foo() { if_DBG std::cout << "[ Destroying a FOO instance ]\n"; }

// Operators
Foo &Foo::operator= ( const Foo &other )
{
	if_DBG std::cout << "[ Called assign. op. for a FOO instance ]\n";

	this->name = other.getName();
	this->_debug = other.debug();

	return *this;
}

// Checkers
void	Foo::checkName( const std::string _name ) const { if ( _name.empty() ) throw BadName(); }

// Setters
void	Foo::setName( const std::string _name ) { checkName( _name );  this->name = _name; }
void	Foo::clearName( void ) { this->name = "UNINITIALIZED"; }

// Getters
const std::string	Foo::getName( void ) const { return ( this->name ); }

// Writers
void	Foo::writeName( std::ostream &out ) const { out << this->getName(); }
void	Foo::printName( void ) const { std::cout << this->getName(); }

std::ostream &operator<< (std::ostream &out, const Foo &rhs)
{
	out << rhs.getName();
	return ( out );
}