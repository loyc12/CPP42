#include "Template.hpp"


// Constructors - Destructor

template < typename T >
Template_T<T>::Template_T()
{
	std::cout << "[ Called def. constr. for a TEMPLATE_T instance ]\n";
	this->value = 0;
}
template < typename T >
Template_T<T>::Template_T( T _value )
{
	std::cout << "[ Called param. constr. for a TEMPLATE_T instance ]\n";
	this->value = _value;
}
template < typename T >
Template_T<T>::Template_T( const Template_T &other )
{
	std::cout << "[ Called copy constr. for a TEMPLATE_T instance ]\n";
	this->value = other.getValue();
}
template < typename T >
Template_T<T>::~Template_T() { std::cout << "[ Destroying a TEMPLATE_T instance ]\n"; }

// Operators

template < typename T >
Template_T<T> &Template_T<T>::operator= ( const Template_T &other )
{
	std::cout << "[ Called assign. op. for a TEMPLATE_T instance ]\n";
	this->value = other.getValue();

	return *this;
}

// Checkers

template < typename T >
void	Template_T<T>::checkValue( const T _value ) const
{
	if ( _value < 0 )
		throw BadValue();
}


// Setters - Getters

template < typename T >
void	Template_T<T>::setValue( const T _value )
{
	checkValue( _value );
	this->value = _value;
}

template < typename T >
const T	Template_T<T>::getValue( void ) const
{
	return ( this->value );
}


// Others

template < typename T >
void	Template_T<T>::printValue( void )
{
	std::cout << this->getValue();
}

template < typename T >
std::ostream &operator<< (std::ostream &out, const Template_T<T> &rhs)
{
	out << rhs.getValue();
	return ( out );
}