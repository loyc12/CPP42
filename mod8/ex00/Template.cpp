#include "Template.hpp"


// Constructors - Destructor

Template::Template()
{
	std::cout << "[ Called def. constr. for a TEMPLATE instance ]\n";
	this->name = "UNINITIALIZED";
}
Template::Template( std::string _name )
{
	std::cout << "[ Called param. constr. for a TEMPLATE instance ]\n";
	this->name = _name;
}
Template::Template( const Template &other )
{
	std::cout << "[ Called copy constr. for a TEMPLATE instance ]\n";
	this->name = other.getName();
}
Template::~Template() { std::cout << "[ Destroying a TEMPLATE instance ]\n"; }

// Operators

Template &Template::operator= ( const Template &other )
{
	std::cout << "[ Called assign. op. for a TEMPLATE instance ]\n";
	this->name = other.getName();

	return *this;
}

// Checkers

void	Template::checkName( const std::string _name ) const
{
	if ( _name.empty() )
		throw BadName();
}


// Setters - Getters

void	Template::setName( const std::string _name )
{
	checkName( _name );
	this->name = _name;
}
const std::string	Template::getName( void ) const
{
	return ( this->name );
}


// Others

void	Template::printName( void )
{
	std::cout << this->getName();
}

std::ostream &operator<< (std::ostream &out, const Template &rhs)
{
	out << rhs.getName();
	return ( out );
}