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
	this->checkLenght();
	this->numbers.clear();
}
Span::Span( const Span &other )
{
	std::cout << "[ Called copy constr. for a SPAN instance ]\n";
	this->maxLenght = other.size();
	this->checkLenght();
	this->numbers = other.getNumbers();
}
Span::~Span() { std::cout << "[ Destroying a SPAN instance ]\n"; }


// Operators

Span &Span::operator= ( const Span &other )
{
	std::cout << "[ Called assign. op. for a SPAN instance ]\n";
	this->maxLenght = other.size();
	this->checkLenght();
	this->numbers = other.getNumbers();

	return *this;
}


// Checkers

void	Span::checkSize() const
{
	if ( this->size() < 2 )
		throw InvalidSize();
}
void	Span::checkLenght() const
{
	if ( this->maxLenght < 1 )
		throw InvalidLenght();
	if ( this->size() > this->maxLenght )
		throw TooManyNumbers();
}


// Setters - Getters

void	Span::setMaxLenght( int N )
{
	this->maxLenght = N;
	this->checkLenght();
}
int		Span::getMaxLenght( void )	const { return ( this->maxLenght ); }
ivec	Span::getNumbers( void )	const { return ( this->numbers ); }
int		Span::size( void )			const { return ( ( int )this->numbers.size() ); }


// Others

void	Span::addNumber( int N )
{
	if ( this->size() >= this->maxLenght )
		throw TooManyNumbers();
	this->numbers.push_back( N );
}
void	Span::delNumber()
{
	if (this->size() < 1)
		throw TooFewNumbers();
	this->numbers.pop_back();
}

void	Span::addRange( int A, int B)
{
	if (A > B)
	{
		int tmp = A;
		A = B;
		B = tmp;
	}
	for (int i = A; i <= B; i++)
		this->addNumber(i);
}
void	Span::delNumbers( int N )
{
	if (N < 0)
		throw NegativeNumber();
	if (this->size() < N)
		throw TooFewNumbers();
	for (int i = 0; i < N; i++)
		this->delNumber();
}

// sorts the numbers,
// finds the difference between each number and the next,
// returns the smallest difference
int	Span::shortestSpan( void )
{
	this->checkSize();
	std::sort( this->numbers.begin(), this->numbers.end() );

    ivec diffs( this->size() );
    std::adjacent_difference( this->numbers.begin(), this->numbers.end(), diffs.begin() );

    return *std::min_element( diffs.begin() + 1, diffs.end() ); // the first element is always 0, so it is skipped
}

// sorts the numbers,
// returns the distance between the smallest and the largest number
int	Span::longestSpan( void )
{
	this->checkSize();
	std::sort( this->numbers.begin(), this->numbers.end() );

    return ( *std::max_element( numbers.begin(), numbers.end() ) - *std::min_element( numbers.begin(), numbers.end() ));
}

std::ostream &operator<< (std::ostream &out, const Span &rhs)
{
	out << rhs.size();
	return ( out );
}