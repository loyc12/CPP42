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

Template &Template::operator= ( const Template &other )
{
	std::cout << "[ Called assign. op. for a TEMPLATE instance ]\n";
	this->name = other.getName();

	return *this;
}



// Setters - Getters

void	Template::setName( std::string _name )
{
	if (_name.empty())
		throw BadName();
	else
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
	return (out);
}