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

	protected:

	// Nested Classes
		class BadSymbol : public std::exception { XCPT { return "Symbol Error : Invalid Symbol\n"; } };
		class DivByZero : public std::exception { XCPT { return "Math Error : Division by Zero\n"; } };

	public:
		// Constructors - Destructor
		Calculator();
		Calculator( int n );
		Calculator( const Calculator &other );
		~Calculator();

		// Operators
		Calculator &operator= ( const Calculator &other );

		// Checkers
		void checkSymbol( char c ) const;

		// Setters - Getters
		void	setValue( int n );
		void	setValue( char c );
		int		getValue( void ) const;

		// Calculations
		void add( int n );
		void sub( int n );
		void mul( int n );
		void div( int n );
		void mod( int n );

		void calculate( char sym, char num );

		// Others
		void	printValue( void );
};

std::ostream &operator<< (std::ostream &out, const Calculator &rhs);

#endif // CALCULATOR_HPP