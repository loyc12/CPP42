#include "Span.hpp"


// Constructors - Destructor

Span::Span()
{
	std::cout << "[ Called def. constr. for a SPAN instance ]\n";
	this->maxLenght = 0;
	this->numbers.clear();
}
Span::Span( int N )
{
	std::cout << "[ Called param. constr. for a SPAN instance ]\n";
	this->maxLenght = N;
	this->numbers.clear();
	this->checkLenght();
}
Span::Span( const Span &other )
{
	std::cout << "[ Called copy constr. for a SPAN instance ]\n";
	this->maxLenght = other.size();
	this->numbers= other.getNumbers();
	this->checkLenght();
}
Span::~Span() { std::cout << "[ Destroying a SPAN instance ]\n"; }


// Operators

Span &Span::operator= ( const Span &other )
{
	std::cout << "[ Called assign. op. for a SPAN instance ]\n";
	this->maxLenght = other.size();
	this->numbers = other.getNumbers();
	this->checkLenght();

	return *this;
}


// Checkers

void	Span::checkSize() const
{
	if ( this->numbers.size() < 2 )
		throw InvalidSize();
}
void	Span::checkLenght() const
{
	if ( this->maxLenght < 1 )
		throw InvalidLenght();
	if ( this->numbers.size() > this->maxLenght )
		throw TooManyNumbers();
}


// Setters - Getters

void	Span::setMaxLenght( int N )
{
	this->maxLenght = N;
	this->checkLenght();
}
int	Span::getMaxLenght( void )	const { return ( this->maxLenght ); }
int	Span::size( void )			const { return ( this->numbers.size() ); }
std::vector<int>	Span::getNumbers( void )	const { return ( this->numbers ); }


// Others

void	Span::addNumber( int N )
{
	this->numbers.push_back( N );
	this->checkLenght();
}

void	Span::shortestSpan( void )
{

}

void	Span::longestSpan( void )
{

}

std::ostream &operator<< (std::ostream &out, const Span &rhs)
{
	out << rhs.size();
	return ( out );
}