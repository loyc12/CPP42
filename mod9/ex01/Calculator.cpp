#include <iostream>
#include "Calculator.hpp"

// Constructors - Destructor

Calculator::Calculator()
{
	//std::cout << "[ Called def. constr. for a CALCULATOR instance ]\n";
	this->_value = 0;
}
Calculator::Calculator( int n )
{
	//std::cout << "[ Called param. constr. for a CALCULATOR instance ]\n";
	this->_value = n;
}
Calculator::Calculator( char c )
{
	//std::cout << "[ Called param. constr. for a CALCULATOR instance ]\n";
	this->checkNum( c );
	this->_value = c - '0';
}
Calculator::Calculator( const Calculator &other )
{
	//std::cout << "[ Called copy constr. for a CALCULATOR instance ]\n";
	this->_value = other.getValue();
}
Calculator::~Calculator() {} //std::cout << "[ Destroying a CALCULATOR instance ]\n"; }

// Operators

Calculator &Calculator::operator= ( const Calculator &other )
{
	//std::cout << "[ Called assign. op. for a CALCULATOR instance ]\n";
	this->_value = other.getValue();

	return *this;
}

// Checkers
void	Calculator::checkArg( const std::string &str ) const
{
	if ( str.empty() || str.length() > 1 )
		throw BadArgument();
	this->checkSymbol( str[ 0 ] );
}

void	Calculator::checkSymbol( char c ) const
{
	if (( c < '0' || c > '9' ) && c != '+' && c != '-' && c != '*' && c != '/' && c != '%' )
		throw BadSymbol();
}
void	Calculator::checkNum( char c ) const
{
	if ( c < '0' || c > '9' )
		throw BadDigit();
}
void	Calculator::checkOper( char c ) const
{
	if ( c != '+' && c != '-' && c != '*' && c != '/' && c != '%' )
		throw BadOperator();
}


// Setters - Getters

void	Calculator::setValue( int n )
{
	this->_value = n;
	if ( this->_debug )
		std::cout << " > " << n << " < \n" << std::endl;
}
void	Calculator::setValue( char c )
{
	this->checkNum( c );
	this->setValue( ( int )c - '0' );
}
int		Calculator::getValue( void ) const { return ( this->_value ); }


// Calculations

void	Calculator::add( int n )
{
	this->_value += n;
	if ( this->_debug )
		std::cout << "Adding " << n << std::endl;
}
void	Calculator::sub( int n )
{
	this->_value -= n;
	if ( this->_debug )
		std::cout << "Subtracting " << n << std::endl;
}
void	Calculator::mul( int n )
{
	this->_value *= n;
	if ( this->_debug )
		std::cout << "Multiplying by " << n << std::endl;
}
void	Calculator::div( int n )
{
	if ( n == 0 )
		throw DivByZero();
	this->_value /= n;
	if ( this->_debug )
		std::cout << "Dividing by " << n << std::endl;
}
void	Calculator::mod( int n )
{
	if ( n == 0 )
		throw DivByZero();
	this->_value %= n;
	if ( this->_debug )
		std::cout << "Modulo " << n << std::endl;
}

void	Calculator::add( char c ) { this->add( ( int )c - '0' ); }
void	Calculator::sub( char c ) { this->sub( ( int )c - '0' ); }
void	Calculator::mul( char c ) { this->mul( ( int )c - '0' ); }
void	Calculator::div( char c ) { this->div( ( int )c - '0' ); }
void	Calculator::mod( char c ) { this->mod( ( int )c - '0' ); }

void	Calculator::calculate( char num, char oper )
{
	this->checkNum( num );
	this->checkOper( oper );

	int n = num - '0';

	switch ( oper )
	{
		case '+': this->add( n ); break;
		case '-': this->sub( n ); break;
		case '*': this->mul( n ); break;
		case '/': this->div( n ); break;
		case '%': this->mod( n ); break;
	}
	if ( this->_debug )
		std::cout << " > " << this->_value << " < \n" << std::endl;
}


// Others

bool	Calculator::debug( void ) const { return ( this->_debug ); }
void	Calculator::debug( bool b ) { this->_debug = b; }

void	Calculator::printValue( void ) const
{
	std::cout << "Equals : " << this->_value << std::endl;
}

std::ostream &operator<< (std::ostream &out, const Calculator &rhs)
{
	out << rhs.getValue();
	return ( out );
}