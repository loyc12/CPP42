#include "PmergeMe.hpp"


// Constructors - Destructor

PmergeMe::PmergeMe()
{
	std::cout << "[ Called def. constr. for a PMERGEME instance ]\n";
	this->name = "UNINITIALIZED";
}
PmergeMe::PmergeMe( const std::string _name )
{
	std::cout << "[ Called param. constr. for a PMERGEME instance ]\n";
	this->name = _name;
}
PmergeMe::PmergeMe( const PmergeMe &other )
{
	std::cout << "[ Called copy constr. for a PMERGEME instance ]\n";
	this->name = other.getName();
}
PmergeMe::~PmergeMe() { std::cout << "[ Destroying a PMERGEME instance ]\n"; }

// Operators

PmergeMe &PmergeMe::operator= ( const PmergeMe &other )
{
	std::cout << "[ Called assign. op. for a PMERGEME instance ]\n";
	this->name = other.getName();

	return *this;
}

// Checkers

void	PmergeMe::checkName( const std::string _name ) const
{
	if ( _name.empty() )
		throw BadName();
}


// Setters - Getters

void	PmergeMe::setName( const std::string _name )
{
	checkName( _name );
	this->name = _name;
}
const std::string	PmergeMe::getName( void ) const
{
	return ( this->name );
}


// Others

void	PmergeMe::printName( void ) const
{
	std::cout << this->getName();
}

std::ostream &operator<< (std::ostream &out, const PmergeMe &rhs)
{
	out << rhs.getName();
	return ( out );
}