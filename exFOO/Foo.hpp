#ifndef FOO_HPP
# define FOO_HPP

# define XCPT public: const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

# define C_STR const std::string
# define TTT template< typename T >
# define if_DBG if ( this->_debug )

// CLASS FOO ( implemented in .cpp file )
class Foo
{
	private:
		// Attributes
		std::string	name;
		bool		_debug;

	protected:
		// Checkers
		void checkName( C_STR _name ) const;

		// Nested Classes
		class BadName : public std::exception { XCPT { return "Foo error : invalid name, idiot!"; } };

	public:
		// Debuggers
		void	debug( bool _debug );
		bool	debug( void ) const;

		// Constructors - Destructor
		Foo();
		Foo( C_STR _name );
		Foo( const Foo &other );
		~Foo();

		// Operators
		Foo &operator= ( const Foo &other );

		// Setters
		void	setName( C_STR _name );
		void	clearName( void );

		// Getters
		C_STR	getName( void ) const;

		// Writers
		void	writeName( std::ostream &out ) const;
		void	printName( void ) const;

};

std::ostream &operator<< ( std::ostream &out, const Foo &rhs );


// TEMPLATE CLASS FOO_T ( implemented in .tpp file )
template< class T >
class Foo_T
{
	private:
		// Attributes
		T		value;
		bool	_debug;

	protected:
		// Checkers
		void	checkValue( const T _value ) const;

		// Nested Classes
		class BadValue : public std::exception { XCPT { return "Foo_T error : invalid value, dumbass!"; } };

	public:
		// Debuggers
		void	debug( bool _debug );
		bool	debug( void ) const;

		// Constructors - Destructor
		Foo_T();
		Foo_T( const T _value );
		Foo_T( const Foo_T< T > &other );
		~Foo_T();

		// Operators
		Foo_T<T> &operator= ( const Foo_T< T > &other );

		// Setters
		void	setValue( const T _value );
		void	clearvalue( void );

		// Getters
		const T	getValue( void ) const;

		// Writers
		void	writeValue( std::ostream &out ) const;
		void	printValue( void ) const;

};
TTT std::ostream &operator<< ( std::ostream &out, const Foo_T< T > &rhs );

# include "Foo.tpp"

#endif // FOO_HPP