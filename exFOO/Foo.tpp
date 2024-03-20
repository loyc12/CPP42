#include "Foo.hpp"


// Constructors - Destructor

template < typename T >
Foo_T<T>::Foo_T()
{
	std::cout << "[ Called def. constr. for a FOO_T instance ]\n";
	this->value = 0;
}
template < typename T >
Foo_T<T>::Foo_T( const T _value )
{
	std::cout << "[ Called param. constr. for a FOO_T instance ]\n";
	this->value = _value;
}
template < typename T >
Foo_T<T>::Foo_T( const Foo_T &other )
{
	std::cout << "[ Called copy constr. for a FOO_T instance ]\n";
	this->value = other.getValue();
}
template < typename T >
Foo_T<T>::~Foo_T() { std::cout << "[ Destroying a FOO_T instance ]\n"; }

// Operators

template < typename T >
Foo_T<T> &Foo_T<T>::operator= ( const Foo_T &other )
{
	std::cout << "[ Called assign. op. for a FOO_T instance ]\n";
	this->value = other.getValue();

	return *this;
}

// Checkers

template < typename T >
void	Foo_T<T>::checkValue( const T _value ) const
{
	if ( _value < 0 )
		throw BadValue();
}


// Setters - Getters

template < typename T >
void	Foo_T<T>::setValue( const T _value )
{
	checkValue( _value );
	this->value = _value;
}

template < typename T >
const T	Foo_T<T>::getValue( void ) const
{
	return ( this->value );
}


// Others

template < typename T >
void	Foo_T<T>::printValue( void ) const
{
	std::cout << this->getValue();
}

template < typename T >
std::ostream &operator<< (std::ostream &out, const Foo_T<T> &rhs)
{
	out << rhs.getValue();
	return ( out );
}