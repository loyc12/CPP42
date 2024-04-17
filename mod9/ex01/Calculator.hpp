#ifndef CALCULATOR_HPP
# define CALCULATOR_HPP

# define XCPT public: const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

# include <deque>
# define DEQUE std::deque< int >

# define elif else if
# define if_DBG if ( this->_debug )

// Enumerators
enum e_opr
{
	ADD = -1,
	SUB = -2,
	MUL = -3,
	DIV = -4,
	MOD = -5
};

class Calculator
{
	private:
		// Attributes
		DEQUE	_bank;
		bool	_debug;

	protected:
		// Nested Classes
		class BadArgument :	public std::exception { XCPT { return "\nFormat Error : Invalid Agument Lenght ( != 1 )\n"; } };
		class BadSymbol :	public std::exception { XCPT { return "\nFormat Error : Invalid Symbol\n"; } };
		class DivByZero :	public std::exception { XCPT { return "\nRuntime Error : Division by Zero\n"; } };
		class BadResult :	public std::exception { XCPT { return "\nRuntime Error : Missing Operators\n"; } };
		class EmptyBank :	public std::exception { XCPT { return "\nRuntime Error : Missing Values\n"; } };

		// Calculators
		int		popOut( void );
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();

	public:
		// Debuggers
		bool	debug( void ) const;
		void	debug( bool b );

		// Constructors - Destructor
		Calculator();
		Calculator( const Calculator &other );
		~Calculator();

		// Operators
		Calculator &operator= ( const Calculator &other );

		// Checkers
		void	checkArg( const std::string &str ) const;

		// Setters - Getters
		void	setBank( const DEQUE &bank );
		DEQUE	getBank( void ) const;
		void	clearBank( void );
		int 	getResult( void );

		// Writers
		void	writeBank( std::ostream &out ) const;
		void	printBank( void ) const;

		// Calculators
		void	push( const std::string &str );
		void	push( char c );
};

std::ostream &operator<< ( std::ostream &out, const Calculator &rhs );

#endif // CALCULATOR_HPP