#ifndef CALCULATOR_HPP
# define CALCULATOR_HPP

# define XCPT public: const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>


// CLASS ( implemented in .cpp file )
class Calculator
{
	private:
		// Attributes
		long _value;
		bool _debug;

	protected:

	// Nested Classes
		class BadArgument :	public std::exception { XCPT { return "\nFormat Error : Invalid Agument Lenght ( != 1 )\n"; } };
		class BadSymbol :	public std::exception { XCPT { return "\nFormat Error : Invalid Symbol\n"; } };
		class BadDigit :	public std::exception { XCPT { return "\nFormat Error : Invalid Digit\n"; } };
		class BadOperator :	public std::exception { XCPT { return "\nFormat Error : Invalid Operator\n"; } };
		class DivByZero :	public std::exception { XCPT { return "\nMath Error : Division by Zero\n"; } };

		// Calculations ( from ints )
		void setValue( int n );

		void add( int n );
		void sub( int n );
		void mul( int n );
		void div( int n );
		void mod( int n );

	public:
		// Constructors - Destructor
		Calculator();
		Calculator( int n );
		Calculator( char c );
		Calculator( const Calculator &other );
		~Calculator();

		// Operators
		Calculator &operator= ( const Calculator &other );

		// Checkers
		void checkArg( const std::string &str ) const;
		void checkSymbol( char c ) const;
		void checkNum( char c ) const;
		void checkOper( char c ) const;

		// Setters - Getters
		void setValue( char c );
		int	 getValue( void ) const;

		// Calculations ( from chars )
		void add( char c );
		void sub( char c );
		void mul( char c );
		void div( char c );
		void mod( char c );

		void calculate( char sym, char num );

		// Others
		bool debug( void ) const;
		void debug( bool b );
		void printValue( void ) const;
};

std::ostream &operator<< (std::ostream &out, const Calculator &rhs);

#endif // CALCULATOR_HPP