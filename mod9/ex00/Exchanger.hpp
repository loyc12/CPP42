#ifndef EXCHANGER_HPP
# define EXCHANGER_HPP

# define XCPT public: const char *what() const throw()
# define RMAP std::map<std::string, double>

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <map>


// CLASS ( implemented in .cpp file )
class Exchanger
{
	private:
		// Attributes
		RMAP *_db;
		bool _debug;

	protected:

	// Nested Classes
		class BadFormat : public std::exception { XCPT { return "\nFormat Error : Invalid DB entry : not YYYY-MM-DD | VALUE\n"; } };
		class BadDate	: public std::exception { XCPT { return "\nFormat Error : Invalid date : not YYYY-MM-DD\n"; } };
		class BadValue	: public std::exception { XCPT { return "\nFormat Error : Invalid Value : not between 0 and 1000\n"; } };

	public:
		// Constructors - Destructor
		Exchanger();
		Exchanger( std::string &pathDB );
		Exchanger( const Exchanger &other );
		~Exchanger();

		// Operators
		Exchanger &operator= ( const Exchanger &other );

		// Checkers
		void checkFormat( const std::string &str ) const;
		void checkDate( const std::string &str ) const;
		void checkValue( double val ) const;

		// Setters - Getters
		void setDB( std::string &pathDB );
		RMAP *getDB( void ) const;
		RMAP *copyDB( void ) const;

		void exchange( double btc, double date );

		// Others
		bool debug( void ) const;
		void debug( bool b );
		void printDB( void ) const;
};

std::ostream &operator<< (std::ostream &out, const Exchanger &rhs);

#endif // EXCHANGER_HPP