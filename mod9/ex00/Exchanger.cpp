#include <iostream>
#include "Exchanger.hpp"

// Constructors - Destructor

Exchanger::Exchanger()
{
	//std::cout << "[ Called def. constr. for a EXCHANGER instance ]\n";
	this->_db = new RMAP;
}
Exchanger::Exchanger( std::string &path )
{
	//std::cout << "[ Called param. constr. for a EXCHANGER instance ]\n";
}
Exchanger::Exchanger( const Exchanger &other )
{
	//std::cout << "[ Called copy constr. for a EXCHANGER instance ]\n";
	this->_db->clear();
	delete this->_db;
	this->_db = other.copyDB();
}
Exchanger::~Exchanger()
{
	//std::cout << "[ Destroying a EXCHANGER instance ]\n";
	this->_db->clear();
	delete this->_db;
}

// Operators

Exchanger &Exchanger::operator= ( const Exchanger &other )
{
	//std::cout << "[ Called assign. op. for a EXCHANGER instance ]\n";
	this->_db->clear();
	delete this->_db;
	this->_db = other.copyDB();

	return *this;
}

// Checkers

void	Exchanger::checkFormat( const std::string &str ) const
{
	if ( false )
		throw BadFormat();
}
void	Exchanger::checkDate( const std::string &str ) const
{
	if ( false )
		throw BadDate();
}
void	Exchanger::checkValue( double val ) const
{
	if ( val < 0 || val > 1000)
		throw BadValue();
}


// Setters - Getters

void	Exchanger::setDB( std::string &path )
{
	// TODO
}

RMAP	*Exchanger::getDB( void ) const { return ( this->_db ); }
RMAP	*Exchanger::copyDB( void ) const
{
	RMAP *copy = new RMAP;
	*copy = *this->_db;
	return ( copy );
}


// Exchanges
void	Exchanger::exchange( double btc, double date )
{
	// TODO
}

// Others

bool	Exchanger::debug( void ) const { return ( this->_debug ); }
void	Exchanger::debug( bool b ) { this->_debug = b; }
void	Exchanger::printDB( void ) const { std::cout << "database : " << this->_db << std::endl; }

std::ostream &operator<< (std::ostream &out, const Exchanger &rhs)
{
	out << rhs.getDB();
	return ( out );
}