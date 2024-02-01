#include "easyfind.hpp"

template < typename T >
int findTypeSEQ( T _container, int _value )
{
	typename T::iterator	it = std::find( _container.begin(), _container.end(), _value );
	if ( it != _container.end() )
	{
		int index = std::distance( _container.begin(), it );
		std::cout << "Found " << _value << " in container at index " << index << std::endl;
		return ( index );
	}
	std::cout << "Could not find " << _value << " in container" << std::endl;
	return -1; // Value not found
}

template < typename T >
int findADAPT( T _container, int _value )
{
	(void)_container;
	(void)_value;

	// use top() and pop() to iterate through the container
	throw UnhandledContainer();
}

template < typename T >
int findASSOC( T _container, int _value )
{
	(void)_container;
	(void)_value;

	// use front() and pop() to iterate through the container
	throw UnhandledContainer();
}

template < typename T >
int	easyfind( T _container, int _value )
{
	switch ( getConType( _container ))
	{
		case 1 : // Sequential containers
			return findTypeSEQ( _container, _value );
		case 2 : // Adaptor containers
			return findADAPT( _container, _value );
		case 3 : // Associative containers
			return findASSOC( _container, _value );
		default:
			throw BadContainer();
	}
}
