#ifndef FOO_HPP
# define FOO_HPP

# define XCPT_RTRN public: virtual const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>


// CLASS ( implemented in .cpp file )
class Foo
{
	private:
		// Attributes
		std::string	name;

	protected:
		// Checkers
		void checkName( const std::string _name ) const;

		// Nested Classes
		class BadName : public std::exception { XCPT_RTRN { return "Foo error : invalid name, idiot!"; } };

	public:
		// Constructors - Destructor
		Foo();
		Foo( const std::string _name );
		Foo( const Foo &other );
		~Foo();

		// Operators
		Foo &operator= ( const Foo &other );

		// Setters - Getters
		void				setName( const std::string _name );
		const std::string	getName( void ) const;

		// Others
		void	printName( void );

};

std::ostream &operator<< (std::ostream &out, const Foo &rhs);


// CLASS FOO ( implemented in .tpp file )
template <class T>
class Foo_T
{
	private:
		// Attributes
		T	value;

	protected:
		// Checkers
		void	checkValue( const T _value ) const;

		// Nested Classes
		class BadValue : public std::exception { XCPT_RTRN { return "Foo_T error : invalid value, dumbass!"; } };

	public:
		// Constructors - Destructor
		Foo_T();
		Foo_T( const T _value );
		Foo_T( const Foo_T<T> &other );
		~Foo_T();

		// Operators
		Foo_T<T> &operator= ( const Foo_T<T> &other );

		// Setters - Getters
		void	setValue( const T _value );
		const T	getValue( void ) const;

		// Others
		void	printValue( void );

};
template < typename T >
std::ostream &operator<< (std::ostream &out, const Foo_T<T> &rhs);

# include "Foo.tpp"

#endif // FOO_HPP