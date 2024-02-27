#include <iostream>
#include "Calculator.hpp"

// Constructors - Destructor

Calculator::Calculator()
{
	std::cout << "[ Called def. constr. for a CALCULATOR instance ]\n";
	this->_value = 0;
}
Calculator::Calculator( int n )
{
	std::cout << "[ Called param. constr. for a CALCULATOR instance ]\n";
	this->_value = n;
}
Calculator::Calculator( const Calculator &other )
{
	std::cout << "[ Called copy constr. for a CALCULATOR instance ]\n";
	this->_value = other.getValue();
}
Calculator::~Calculator() { std::cout << "[ Destroying a CALCULATOR instance ]\n"; }

// Operators

Calculator &Calculator::operator= ( const Calculator &other )
{
	std::cout << "[ Called assign. op. for a CALCULATOR instance ]\n";
	this->_value = other.getValue();

	return *this;
}

// Checkers

void	Calculator::checkSymbol( char c ) const
{
	if (( c < '0' || c > '9' ) && c != '+' && c != '-' && c != '*' && c != '/' && c != '%')
	{
		std::cerr << std::endl << " > " << c << " < "  << std::endl;
		throw BadSymbol();
	}
}


// Setters - Getters

void	Calculator::setValue( int n ) { this->_value = n; }
void	Calculator::setValue( char c ) { this->_value = c - '0'; }
int		Calculator::getValue( void ) const { return ( this->_value ); }


// Calculations

void	Calculator::add( int n ) { this->_value += n; }
void	Calculator::sub( int n ) { this->_value -= n; }
void	Calculator::mul( int n ) { this->_value *= n; }
void	Calculator::div( int n )
{
	if ( n == 0 )
	throw DivByZero();
	this->_value /= n;
}
void	Calculator::mod( int n )
{
	if ( n == 0 )
		throw DivByZero();
	this->_value %= n;
}

void	Calculator::calculate( char sym, char num )
{
	this->checkSymbol( sym );
	this->checkSymbol( num );

	int n = num - '0';

	switch ( sym )
	{
		case '+': this->add( n ); break;
		case '-': this->sub( n ); break;
		case '*': this->mul( n ); break;
		case '/': this->div( n ); break;
		case '%': this->mod( n ); break;
	}
}


// Others

void	Calculator::printValue( void )
{
	std::cout << this->getValue() << std::endl;
}

std::ostream &operator<< (std::ostream &out, const Calculator &rhs)
{
	out << rhs.getValue();
	return ( out );
}