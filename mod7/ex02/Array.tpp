#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// Checkers
template < typename T >
int	Array<T>::checkIndex( int i ) const
{
	if ( i < -this->size || i >= this->size )
		throw InvalidIndex();

	else if ( i < 0 ) // allows reading the array backwards via negative indexes
		return this->size + i;

	else
		return i;
};

// Constructors - Destructor
template < typename T >
Array<T>::Array()
{
	std::cout << "[ Called def. const. for an ARRAY instance ]\n";

	this->size = T();
	this->bank = new T[ this->size ];

};
template < typename T >
Array<T>::Array( unsigned int n )
{
	std::cout << "[ Called param. con. for an ARRAY instance ]\n";

	this->size = n;
	this->bank = new T[ this->size ];

	for ( int i = 0; i < this->size; i++ )
		this->bank[ i ] = T();
};
template < typename T >
Array<T>::Array( const Array<T> &other )
{
	std::cout << "[ Called copy const. for an ARRAY instance ]\n";

	this->size = other.getSize();
	this->bank = new T[ this->size ];

	for ( int i = 0; i < this->size; i++ )
		this->bank[ i ] = other.getValue( i );
};
template < typename T >
Array<T>::~Array()
{
	std::cout << "[ Destroying an ARRAY instance ]\n";

	delete [] this->bank;
};

// Operator Overloads
template < typename T >
Array<T> &Array<T>::operator= ( const Array<T> &other )
{
	std::cout << "[ Used assign. oper. on an ARRAY instance ]\n";

	delete [] this->bank;

	this->size = other.getSize();
	this->bank = new T[ this->size ];

	for ( int i = 0; i < this->size; i++ )
		this->bank[ i ] = other.getValue( i );

	return *this;
};
template < typename T >
T &Array<T>::operator[] ( int i ) { return this->bank[ this->checkIndex( i )]; };

// Getters
template < typename T >
int	Array<T>::getSize( void ) const { return this->size; };
template < typename T >
T	Array<T>::getValue( int i ) const { return this->bank[ this->checkIndex( i )]; };

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

#endif // ARRAY_TPP