#include "Foo.hpp"

// Debbugers
TTT void Foo_T< T >::debug( bool debug ) { this->_debug = debug; }
TTT bool Foo_T< T >::debug( void ) const { return ( this->_debug ); }

// Constructors - Destructor
TTT Foo_T< T >::Foo_T()
{
	this->_debug = false;

	if_DBG std::cout << "[ Called def. constr. for a FOO_T instance ]\n";

	this->value = 0;
}
TTT Foo_T< T >::Foo_T( const T _value )
{
	this->_debug = false;

	if_DBG std::cout << "[ Called param. constr. for a FOO_T instance ]\n";

	this->value = _value;
}
TTT Foo_T< T >::Foo_T( const Foo_T &other )
{
	this->_debug = false;

	if_DBG std::cout << "[ Called copy constr. for a FOO_T instance ]\n";

	this->value = other.getValue();
}
TTT Foo_T< T >::~Foo_T() { std::cout << "[ Destroying a FOO_T instance ]\n"; }

// Operators
TTT Foo_T< T > &Foo_T< T >::operator= ( const Foo_T &other )
{
	this->_debug = false;

	if_DBG std::cout << "[ Called assign. op. for a FOO_T instance ]\n";

	this->value = other.getValue();

	return *this;
}

// Checkers
TTT void	Foo_T< T >::checkValue( const T _value ) const { if ( _value < 0 ) throw BadValue(); }

// Setters - Getters
TTT void	Foo_T< T >::setValue( const T _value ) { checkValue( _value ); this->value = _value; }
TTT const T	Foo_T< T >::getValue( void ) const { return ( this->value ); }

// Writers
TTT void	Foo_T<T>::writeValue( std::ostream &out ) const { out << this->getValue(); }
TTT void	Foo_T<T>::printValue( void ) const { std::cout << this->getValue(); }

TTT std::ostream &operator<< ( std::ostream &out, const Foo_T<T> &rhs )
{
	out << rhs.getValue();
	return ( out );
}