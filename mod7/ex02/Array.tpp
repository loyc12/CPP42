#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// Checkers
template < typename T >
int	Array<T>::checkIndex( int i ) const
{
	if ( i < -this->_size || i >= this->_size )
		throw InvalidIndex();

	else if ( i < 0 ) // allows reading the array backwards via negative indexes
		return ( this->_size + i );

	else
		return i;
}

// Constructors - Destructor
template < typename T >
Array<T>::Array()
{
	std::cout << "[ Called def. const. for an ARRAY instance ]\n";

	this->_size = 0;
	this->_bank = new T[ this->_size ];

}
template < typename T >
Array<T>::Array( unsigned int n )
{
	std::cout << "[ Called param. con. for an ARRAY instance ]\n";

	this->_size = n;
	this->_bank = new T[ this->_size ];

	for ( int i = 0; i < this->_size; i++ )
		this->_bank[ i ] = T();
}
template < typename T >
Array<T>::Array( const Array<T> &other )
{
	std::cout << "[ Called copy const. for an ARRAY instance ]\n";

	this->_size = other.size();
	this->_bank = new T[ this->_size ];

	for ( int i = 0; i < this->_size; i++ )
		this->_bank[ i ] = other.value( i );
}
template < typename T >
Array<T>::~Array()
{
	std::cout << "[ Destroying an ARRAY instance ]\n";

	delete [] this->_bank;
}

// Operator Overloads
template < typename T >
Array<T> &Array<T>::operator= ( const Array<T> &other )
{
	std::cout << "[ Used assign. oper. on an ARRAY instance ]\n";

	delete [] this->_bank;

	this->_size = other.size();
	this->_bank = new T[ this->_size ];

	for ( int i = 0; i < this->_size; i++ )
		this->_bank[ i ] = other.value( i );

	return *this;
}
template < typename T >
T &Array<T>::operator[] ( int i ) { return this->_bank[ this->checkIndex( i )]; }

// Getters
template < typename T >
int	Array<T>::size( void ) const { return this->_size; }
template < typename T >
T	Array<T>::value( int i ) const { return this->_bank[ this->checkIndex( i )]; }

template < typename T >
std::ostream &operator<< ( std::ostream &out, const Array<T> &rhs )
{
	out << std::fixed << std::setprecision( 2 );
	out << "size : " << rhs.size() << " | [ ";
	for ( int i = 0; i < rhs.size(); i++ )
		out << rhs.value( i ) << " ";
	out << "]";
	return (out);
}

#endif // ARRAY_TPP