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
		T	*bank;
		int	size;

	protected:
		// Checkers
		int	checkIndex( int i ) const
		{
			if ( i < -this->size || i >= this->size )
				throw InvalidIndex();

			else if ( i < 0 ) // allows reading the array backwards via negative indexes
				return this->size + i;

			else
				return i;
		};

		// Nested Classes
		class InvalidIndex : public std::exception
		{
			public:
				virtual const char *what() const throw() { return "array error : index must be within bounds"; }
		};

	public:
		// Constructors - Destructor
		Array()
		{
			std::cout << "[ Called def. const. for an ARRAY instance ]\n";

			this->size = T();
			this->bank = new T[ this->size ];

		};
		Array( unsigned int n )
		{
			std::cout << "[ Called param. con. for an ARRAY instance ]\n";

			this->size = n;
			this->bank = new T[ this->size ];

			for ( int i = 0; i < this->size; i++ )
				this->bank[ i ] = T();
		};
		Array( const Array<T> &other )
		{
			std::cout << "[ Called copy const. for an ARRAY instance ]\n";

			this->size = other.getSize();
			this->bank = new T[ this->size ];

			for ( int i = 0; i < this->size; i++ )
				this->bank[ i ] = other.getValue( i );
		};
		~Array()
		{
			std::cout << "[ Destroying an ARRAY instance ]\n";

			delete [] this->bank;
		};

		// Operator Overloads
		Array<T> &operator= ( const Array<T> &other )
		{
			std::cout << "[ Used assign. oper. on an ARRAY instance ]\n";

			delete [] this->bank;

			this->size = other.getSize();
			this->bank = new T[ this->size ];

			for ( int i = 0; i < this->size; i++ )
				this->bank[ i ] = other.getValue( i );

			return *this;
		};
		T &operator[] ( int i ) { return this->bank[ this->checkIndex( i )]; };

		// Getters
		int		getSize( void ) const { return this->size; };
		T		getValue( int i ) const { return this->bank[ this->checkIndex( i )]; };
};

template < typename T >
std::ostream &operator<< ( std::ostream &out, const Array<T> &rhs )
{
	out << std::fixed << std::setprecision( 2 );
	out << "size : " << rhs.getSize() << " | [ ";
	for ( int i = 0; i < rhs.getSize(); i++ )
		out << rhs.getValue( i ) << " ";
	out << "]";
	return (out);
}

#endif // ARRAY_HPP