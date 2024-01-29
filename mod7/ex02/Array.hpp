#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

template <class T>
class Array
{
	private:
		// Attributes
		T	*_bank;
		int	_size;

	protected:
		// Checkers
		int	checkIndex( int i ) const;

		// Nested Classes
		class InvalidIndex : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "array error : index must be within bounds"; }
		};

	public:
		// Constructors - Destructor
		Array();
		Array( unsigned int n );
		Array( const Array<T> &other );
		~Array();

		// Operator Overloads
		Array<T> &operator= ( const Array<T> &other );
		T &operator[] ( int i );

		// Getters
		int	size( void ) const;
		T	value( int i ) const;
};

template < typename T >
std::ostream &operator<< ( std::ostream &out, const Array<T> &rhs );

# include "Array.tpp"

#endif // ARRAY_HPP