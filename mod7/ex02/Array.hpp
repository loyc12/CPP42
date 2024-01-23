#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <sstream>
# include <string>

class Array
{
	private:
		// Attributes
		int		*arr;
		int		size;

	protected:
		int	getIndex( int i ) const;

		// Nested Classes
		class InvalidSize : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "array error : size cannot be negative"; }
		};
		class InvalidIndex : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "array error : index must be within bounds"; }
		};

	public:
		// Constructors - Destructor
		Array();
		Array( const int s );
		Array( const Array &other );
		~Array();

		// Operator Overloads
		Array &operator= ( const Array &other );
		int &operator[] ( int i );

		// Setters - Getters
		void	setSize( int s );
		void	setValue( int i, int v );

		int		getSize( void ) const;
		int		getValue( int i ) const;


};

std::ostream &operator<< (std::ostream &out, const Array &rhs);

#endif // ARRAY_HPP