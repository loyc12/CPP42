#include <iostream>
#include "BitcoinExchange.hpp"

// Helpers
static bool isDateBigger( std::string d1, std::string d2 )
{	// WARNING : assumes a valid date in the format "YYYY-MM-DD"

	// take the year from the string (0001-9999)
	int year1 = stoi( d1.substr( 0, 4 ));
	int year2 = stoi( d2.substr( 0, 4 ));

	// multiply the year by 100 ( to make space for the month )
	year1 *= 100;
	year2 *= 100;

	// take the month from the string (1-12)
	year1 += stoi( d1.substr( 5, 2 ));
	year2 += stoi( d2.substr( 5, 2 ));

	// multiply the month by 100 (to make space for the day)
	year1 *= 100;
	year2 *= 100;

	// take the day from the string (1-31)
	year1 += stoi( d1.substr( 8, 2 ));
	year2 += stoi( d2.substr( 8, 2 ));

	return ( year1 > year2 );
}

// Constructors - Destructor

BitcoinExchange::BitcoinExchange()
{
	//std::cout << "[ Called def. constr. for a BITCOINEXCHANGE instance ]\n";
	this->_db = new RMAP;
}
BitcoinExchange::BitcoinExchange( bool debug )
{
	//std::cout << "[ Called param. constr. for a BITCOINEXCHANGE instance ]\n";
	this->_db = new RMAP;
	this->_debug = debug;
}
BitcoinExchange::BitcoinExchange( std::string &path )
{
	this->_db = new RMAP;
	this->setDB( path );
	//std::cout << "[ Called param. constr. for a BITCOINEXCHANGE instance ]\n";
}
BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
{
	//std::cout << "[ Called copy constr. for a BITCOINEXCHANGE instance ]\n";
	this->_db->clear();
	delete this->_db;
	this->_db = other.copyDB();
}
BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "[ Destroying a BITCOINEXCHANGE instance ]\n";
	this->_db->clear();
	delete this->_db;
}

// Operators

BitcoinExchange &BitcoinExchange::operator= ( const BitcoinExchange &other )
{
	//std::cout << "[ Called assign. op. for a BITCOINEXCHANGE instance ]\n";
	this->_db->clear();
	delete this->_db;
	this->_db = other.copyDB();

	return *this;
}

// Checkers

// Checks if the string is in the format "YYYY-MM-DD:VALUE"
void	BitcoinExchange::checkFormatDB( const std::string &str) const
{

	if ( str.length() <= 11 || str[ 10 ] != ',' )
		throw BadFormDB();

	this->checkDate( str.substr( 0, 10 ));
	this->checkValue( std::stod( str.substr( 11 )), false );
}
void	BitcoinExchange::checkFormatInput( const std::string &str ) const
{

	if ( str.length() <= 13 || str[ 10 ] != ' ' || str[ 11 ] != '|' || str[ 12 ] != ' ' )
		throw BadFormIn();

	this->checkDate( str.substr( 0, 10 ));
	this->checkValue( std::stod( str.substr( 13 )), true );
}
void	BitcoinExchange::checkDate( const std::string &str ) const
{
	// check if the date is in the format "YYYY-MM-DD"
	if ( str.length() != 10 )
		throw BadDate();
	if ( str[4] != '-' || str[7] != '-' )
		throw BadDate();
	if ( str[0] < '0' || str[0] > '9' || str[1] < '0' || str[1] > '9' || str[2] < '0' || str[2] > '9' || str[3] < '0' || str[3] > '9' )
		throw BadDate();
	if ( str[5] < '0' || str[5] > '1' || str[6] < '0' || str[6] > '9' || ( str[5] == '1' && str[6] > '2' ))
		throw BadDate();
	if ( str[8] < '0' || str[8] > '3' || str[9] < '0' || str[9] > '9' || ( str[8] == '3' && str[9] > '1' ))
		throw BadDate();
}
void	BitcoinExchange::checkValue( double val, bool checkMax ) const
{
	// check if the value is between 0 and 1000
	if ( val < 0 )
		throw BadValue();
	if ( checkMax && val > 1000 )
		throw MaxValue();
}


// Setters - Getters

void	BitcoinExchange::setDB( std::string &path)
{
	std::ifstream file;
	file.open( path );

	if ( this->_debug ) std::cout << "Loading DB file : " << path << std::endl;
	if ( !file.is_open() ) throw BadFile();

	std::string line;
	std::getline( file, line ); // skips the first line

	while ( std::getline( file, line ) && !line.empty() && line[0] != '\0' )
	{
		try
		{
			this->checkFormatDB( line );

			// Split the line into date and value
			std::string date = line.substr( 0, 10 );
			double value = std::stod( line.substr( 11 ) );

			this->_db->insert( std::pair<std::string, double>( date, value ));
		}
		catch ( std::exception &e ) { this->printConvFailure( e, line ); }
	}

	file.close();
	if ( this->_debug ) std::cout << path << " successfully loaded\n";

}
RMAP	*BitcoinExchange::getDB( void ) const { return ( this->_db ); }
RMAP	*BitcoinExchange::copyDB( void ) const
{
	RMAP *copy = new RMAP;
	*copy = *this->_db;
	return ( copy );
}


// Exchanges
double	BitcoinExchange::getRate( std::string date ) const
{
	this->checkDate( date );
	double rate = 0;

	RMAP::const_iterator it = this->_db->find( date );
	if ( it != this->_db->end() )
		rate = it->second;
	else
	{
		it = this->_db->begin();
		std::string closestDate = "0000-00-00";
		while ( it != this->_db->end() )
		{
			if ( isDateBigger( it->first, closestDate ) && isDateBigger( date, it->first ) )
				closestDate = it->first;
			it++;
		}
		if ( closestDate != "0000-00-00" )
		{
			if ( this->_debug ) std::cout << std::endl << "Rounding " << date << " to : " << closestDate;
			rate = this->_db->at( closestDate );
		}
		else throw BadRate();
	}

	return ( rate );
}
void BitcoinExchange::exchange( std::string &path ) const
{
	std::ifstream file;
	file.open( path );

	if ( this->_debug ) std::cout << "\nLoading input file : " << path << std::endl;
	if ( !file.is_open() )
		throw BadFile();

	std::string line;

	while ( std::getline( file, line ) && !line.empty() && line[0] != '\0' )
	{
		std::cout << std::fixed << std::setprecision( 2 );
		try
		{
			this->checkFormatInput( line );

			// Split the line into date and bitcoin_amount
			std::string date = line.substr( 0, 10 );
			double bitcoin_amount = std::stod( line.substr( 13 ) );
			this->checkValue( bitcoin_amount, true );

			// call exchange and multiply the result by the bitcoin_amount
			double usd_value = this->getRate( date );
			double converted_amount = bitcoin_amount * usd_value;

			// print the result
			std::cout << std::endl << "Value of " << bitcoin_amount << " Bitcoin on " << date << " : " << converted_amount;
		}
		catch ( std::exception &e ) { this->printConvFailure( e, line ); }
	}

	file.close();
}

// Others

bool	BitcoinExchange::debug( void ) const { return ( this->_debug ); }
void	BitcoinExchange::debug( bool b ) { this->_debug = b; }
void	BitcoinExchange::printDB( void ) const
{
	std::cout << "database : " << std::endl;
	for ( RMAP::const_iterator it = this->_db->begin(); it != this->_db->end(); it++ )
		std::cout << it->first << " : " << it->second << std::endl;
}
void	BitcoinExchange::printConvFailure( const std::exception &e, const std::string &line ) const
{
	std::cerr << std::endl;
	if ( this->_debug )
		std::cerr << "Failed to convert line ' " << line << " ' due to : ";
	std::cerr << e.what();
}

std::ostream &operator<< (std::ostream &out, const BitcoinExchange &rhs)
{
	out << rhs.getDB();
	return ( out );
}