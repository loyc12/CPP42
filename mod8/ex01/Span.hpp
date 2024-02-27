#ifndef SPAN_HPP
# define SPAN_HPP

# define XCPT	public: const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

// other libs
# include <vector>
# include <numeric>
# include <algorithm>

# define ivec	std::vector< int >


class Span
{
	private:
		// Attributes
		int		maxLenght;
		ivec	numbers;

	protected:
		// Checkers
		void checkSize() const;
		void checkLenght() const;

		// Nested Classes
		class InvalidSize :		public std::exception {	XCPT { return "Span error : cannot get span with less than 2 numbers"; } };
		class InvalidLenght :	public std::exception { XCPT { return "Span error : lenght cannot be smaller than 1"; } };
		class TooManyNumbers :	public std::exception { XCPT { return "Span error : cannot hold more than [ lenght ] numbers"; } };
		class TooFewNumbers :	public std::exception { XCPT { return "Span error : cannot hold less than 0 numbers"; } };
		class NegativeNumber :	public std::exception { XCPT { return "Span error : cannot remove a negative amount"; } };


	public:
		// Constructors - Destructor
		Span();
		Span( int N );
		Span( const Span &other );
		~Span();

		// Operators
		Span &operator= ( const Span &other );

		// Setters - Getters
		void	setMaxLenght( int N );
		int		getMaxLenght( void ) const;
		ivec 	getNumbers( void ) const;
		int		size( void ) const;

		// Others
		void	addNumber( int N );
		void	delNumber();

		void 	addRange( int A, int B);
		void	delNumbers( int N );

		int		shortestSpan( void );
		int		longestSpan( void );
};

std::ostream &operator<< (std::ostream &out, const Span &rhs);

#endif // SPAN_HPP