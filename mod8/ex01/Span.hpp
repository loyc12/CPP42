#ifndef SPAN_HPP
# define SPAN_HPP

# define XCPT_RTRN public: virtual const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

# include <vector>


class Span
{
	private:
		// Attributes
		int					maxLenght;
		std::vector<int>	numbers;

	protected:
		// Checkers
		void checkSize() const;
		void checkLenght() const;

		// Nested Classes
		class InvalidSize : public std::exception { XCPT_RTRN { return "Span error : cannot get span with less than 2 numbers"; } };
		class InvalidLenght : public std::exception { XCPT_RTRN { return "Span error : lenght cannot be smaller than 1"; } };
		class TooManyNumbers : public std::exception { XCPT_RTRN { return "Span error : cannot add more than [ lenght ] numbers"; } };

	public:
		// Constructors - Destructor
		Span();
		Span( int N );
		Span( const Span &other );
		~Span();

		// Operators
		Span &operator= ( const Span &other );

		// Setters - Getters
		void				setMaxLenght( int N );
		int					getMaxLenght( void ) const;
		int					size( void ) const;
		std::vector<int>	getNumbers( void ) const;

		// Others
		void	addNumber( int N );
		void	shortestSpan( void );
		void	longestSpan( void );
};

std::ostream &operator<< (std::ostream &out, const Span &rhs);

#endif // SPAN_HPP