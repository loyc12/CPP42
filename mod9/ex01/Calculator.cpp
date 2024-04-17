#include <iostream>
#include "Calculator.hpp"

// Debuggers

bool	Calculator::debug( void ) const { return ( this->_debug ); }
void	Calculator::debug( bool b ) { this->_debug = b; }

// Constructors - Destructor

Calculator::Calculator()
{
	//std::cout << "[ Called def. constr. for a CALCULATOR instance ]\n";
	this->_bank.clear();
}
Calculator::Calculator( const Calculator &other )
{
	//std::cout << "[ Called copy constr. for a CALCULATOR instance ]\n";
	this->_bank = other.getBank();
}
Calculator::~Calculator() {} //std::cout << "[ Destroying a CALCULATOR instance ]\n"; }

// Operators

Calculator &Calculator::operator= ( const Calculator &other )
{
	//std::cout << "[ Called assign. op. for a CALCULATOR instance ]\n";
	this->_bank = other.getBank();

	return *this;
}

// Checkers
void	Calculator::checkArg( const std::string &str ) const
{
	if ( str.empty() || str.length() > 1 )
		throw BadArgument();
}

// Calculators

void	Calculator::push( const std::string &str )
{
	this->checkArg( str );
	this->push( str[ 0 ] );
}
void	Calculator::push( char c )
{
	if ( c >= '0' && c <= '9' ) this->_bank.push_back( c - '0' );
	else switch ( c )
	{
		case '+': this->add(); break;
		case '-': this->sub(); break;
		case '*': this->mul(); break;
		case '/': this->div(); break;
		case '%': this->mod(); break;
		default: throw BadSymbol();
	}
}

void	Calculator::add()
{
	int val_2 = this->popOut();
	int val_1 = this->popOut();

	if_DBG std::cout << val_1 << " added with " << val_2 << std::endl;

	this->_bank.push_back( val_1 + val_2 );
}
void	Calculator::sub()
{
	int val_2 = this->popOut();
	int val_1 = this->popOut();

	if_DBG std::cout << val_1 << " subtracted by " << val_2 << std::endl;

	this->_bank.push_back( val_1 - val_2 );
}
void	Calculator::mul()
{
	int val_2 = this->popOut();
	int val_1 = this->popOut();

	if_DBG std::cout << val_1 << " multiplied by " << val_2 << std::endl;

	this->_bank.push_back( val_1 * val_2 );
}
void	Calculator::div()
{
	int val_2 = this->popOut();
	int val_1 = this->popOut();

	if_DBG std::cout << val_1 << " divided by " << val_2 << std::endl;

	if ( val_2 == 0 ) throw DivByZero();

	this->_bank.push_back( val_1 / val_2 );
}
void	Calculator::mod()
{
	int val_2 = this->popOut();
	int val_1 = this->popOut();

	if_DBG std::cout << val_1 << " modulo " << val_2 << std::endl;

	if ( val_2 == 0 ) throw DivByZero();

	this->_bank.push_back( val_1 % val_2 );
}

int		Calculator::popOut( void )
{
	if ( this->_bank.empty() ) throw EmptyBank();

	int tmp = this->_bank.back();
	this->_bank.pop_back();

	return ( tmp );
}

// Setter - Getter

void	Calculator::setBank( const DEQUE &bank ) { this->_bank = bank; }
DEQUE	Calculator::getBank( void ) const { return ( this->_bank ); }
void	Calculator::clearBank( void ) { this->_bank.clear(); }

// Writers

void Calculator::writeBank( std::ostream &out ) const
{
	DEQUE::const_iterator it = this->_bank.begin();
	DEQUE::const_iterator ite = this->_bank.end();

	while ( it != ite )
	{
		out << *it;
		++it;
	}
}

void	Calculator::printBank( void ) const
{
	std::cout << "Equals : ";
	this->writeBank( std::cout );
	std::cout << std::endl;
}

int		Calculator::getResult( void )
{
	if ( this->_bank.size() != 1 ) throw BadResult();

	return ( this->_bank.front() );
}

std::ostream &operator<< (std::ostream &out, const Calculator &rhs)
{
	rhs.writeBank( out );
	return ( out );
}