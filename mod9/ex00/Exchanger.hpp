#ifndef EXCHANGER_HPP
# define EXCHANGER_HPP

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
// rename the classes

class Exchanger
{
	private:
		// Attributes
		RMAP *_db;
		bool _debug;

	protected:

	// Nested Classes
		class BadFormat : public std::exception { XCPT { return "Format Error : DB line entry does not follow the format 'YYYY-MM-DD:VALUE'\n"; }};
		class BadDate	: public std::exception { XCPT { return "Format Error : Specified date does not exist\n"; }};
		class BadValue	: public std::exception { XCPT { return "Format Error : Value must be between 0 and 1000\n"; }};

		class BadFile	: public std::exception { XCPT { return "File Error : Could not open file\n"; }};
		class BadRate	: public std::exception { XCPT { return "Rate Error : Date is outside the DB's date range\n"; }};

	public:
		// Constructors - Destructor
		Exchanger();
		Exchanger( bool debug );
		Exchanger( std::string &pathDB );
		Exchanger( const Exchanger &other );
		~Exchanger();

		// Operators
		Exchanger &operator= ( const Exchanger &other );

		// Checkers
		void	checkFormat( const std::string &str ) const;
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
};

std::ostream &operator<< (std::ostream &out, const Exchanger &rhs);

#endif // EXCHANGER_HPP