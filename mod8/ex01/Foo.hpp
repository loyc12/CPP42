#ifndef FOO_HPP
# define FOO_HPP

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>


class Foo
{
	private:
		// Attributes
		int lenght;

	protected:
		// Checkers
		void checkLenght() const;

		// Nested Classes
		class BadLenght : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "Foo error : invalid name, idiot!"; }
		};

	public:
		// Constructors - Destructor
		Foo();
		Foo( int N );
		Foo( const Foo &other );
		~Foo();

		// Operators
		Foo &operator= ( const Foo &other );

		// Setters - Getters
		void	setSize( int N );
		int		size( void ) const;

		// Others
		void	addNumber( int N );
		void	shortestSpan( void );
		void	longestSpan( void );
		void	printLenght( void );
};

std::ostream &operator<< (std::ostream &out, const Foo &rhs);

#endif // FOO_HPP