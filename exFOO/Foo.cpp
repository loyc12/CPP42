#include "Foo.hpp"


// Constructors - Destructor

Foo::Foo()
{
	std::cout << "[ Called def. constr. for a FOO instance ]\n";
	this->name = "UNINITIALIZED";
}
Foo::Foo( std::string _name )
{
	std::cout << "[ Called param. constr. for a FOO instance ]\n";
	this->name = _name;
}
Foo::Foo( const Foo &other )
{
	std::cout << "[ Called copy constr. for a FOO instance ]\n";
	this->name = other.getName();
}
Foo::~Foo() { std::cout << "[ Destroying a FOO instance ]\n"; }

// Operators

Foo &Foo::operator= ( const Foo &other )
{
	std::cout << "[ Called assign. op. for a FOO instance ]\n";
	this->name = other.getName();

	return *this;
}

// Checkers

void	Foo::checkName( const std::string _name ) const
{
	if ( _name.empty() )
		throw BadName();
}


// Setters - Getters

void	Foo::setName( const std::string _name )
{
	checkName( _name );
	this->name = _name;
}
const std::string	Foo::getName( void ) const
{
	return ( this->name );
}


// Others

void	Foo::printName( void )
{
	std::cout << this->getName();
}

std::ostream &operator<< (std::ostream &out, const Foo &rhs)
{
	out << rhs.getName();
	return ( out );
}