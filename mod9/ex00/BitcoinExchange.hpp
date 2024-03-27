#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define XCPT public: const char *what() const throw()
# define RMAP std::map<std::string, double>

// basic libs
# include <exception>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <sstream>
# include <string>
# include <map>

// TODO
// check for format error more thoroughly
// add predefined error messages instead of on-the-fly ones
// fix this shit

class BitcoinExchange
{
	private:
		// Attributes
		RMAP *_db;
		bool _debug;

	protected:

	// Nested Classes
		class BadFormDB : public std::exception { XCPT { return "Format Error : Database entry does not follow the format 'YYYY-MM-DD,VALUE'"; }};
		class BadFormIn : public std::exception { XCPT { return "Format Error : Input entry does not follow the format 'YYYY-MM-DD | VALUE'"; }};
		class BadDate	: public std::exception { XCPT { return "Format Error : Specified date does not exist"; }};
		class BadValue	: public std::exception { XCPT { return "Format Error : Value must be greater than 0"; }};
		class MaxValue	: public std::exception { XCPT { return "Format Error : Input value must be bellow 1000"; }};

		class BadFile	: public std::exception { XCPT { return "File Error : Could not open file"; }};
		class BadRate	: public std::exception { XCPT { return "Rate Error : Date is outside the DB's date range"; }};

	public:
		// Constructors - Destructor
		BitcoinExchange();
		BitcoinExchange( bool debug );
		BitcoinExchange( std::string &pathDB );
		BitcoinExchange( const BitcoinExchange &other );
		~BitcoinExchange();

		// Operators
		BitcoinExchange &operator= ( const BitcoinExchange &other );

		// Checkers
		void	checkFormatDB( const std::string &str ) const;
		void	checkFormatInput( const std::string &str ) const;
		void	checkDate( const std::string &str ) const;
		void	checkValue( double val, bool checkMax ) const;

		// Setters - Getters
		void	setDB( std::string &pathDB );
		RMAP	*getDB( void ) const;
		RMAP	*copyDB( void ) const;

		double	getRate( std::string date ) const;
		void	exchange( std::string &path ) const;

		// Others
		bool	debug( void ) const;
		void	debug( bool b );
		void	printDB( void ) const;
		void 	printConvFailure( const std::exception &e, const std::string &line) const;
};

std::ostream &operator<< (std::ostream &out, const BitcoinExchange &rhs);

#endif // BITCOINEXCHANGE_HPP