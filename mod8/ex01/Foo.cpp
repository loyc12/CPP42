#include "Foo.hpp"


// Constructors - Destructor

Foo::Foo()
{
	std::cout << "[ Called def. constr. for a FOO instance ]\n";
	this->lenght = 0;
}
Foo::Foo( int N )
{
	std::cout << "[ Called param. constr. for a FOO instance ]\n";
	this->lenght = N;
	this->checkLenght();
}
Foo::Foo( const Foo &other )
{
	std::cout << "[ Called copy constr. for a FOO instance ]\n";
	this->lenght = other.size();
	this->checkLenght();
}
Foo::~Foo() { std::cout << "[ Destroying a FOO instance ]\n"; }

// Operators

Foo &Foo::operator= ( const Foo &other )
{
	std::cout << "[ Called assign. op. for a FOO instance ]\n";
	this->lenght = other.size();
	this->checkLenght();

	return *this;
}

// Checkers

void	Foo::checkLenght() const
{
	if ( this->lenght < 0 )
		throw BadLenght();
}


// Setters - Getters

void	Foo::setSize( int N )
{
	this->lenght = N;
	this->checkLenght();
}
int	Foo::size( void ) const
{
	return ( this->lenght );
}


// Others

void	Foo::addNumber( int N )
{

}

void	Foo::shortestSpan( void )
{

}

void	Foo::longestSpan( void )
{

}

void	Foo::printLenght( void )
{
	std::cout << this->size();
}

std::ostream &operator<< (std::ostream &out, const Foo &rhs)
{
	out << rhs.size();
	return ( out );
}