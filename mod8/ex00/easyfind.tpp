#include <iostream>
#include "easyfind.hpp"

template < typename T >
bool easyfind( T container, int value )
{
	if ( container.size() == 0 )
	{
		std::cout << "Container is empty" << std::endl;
		return ( false );
	}

	typename T::iterator it = find( container.begin(), container.end(), value );

	if ( it == container.end() )
	{
		std::cout << "Couldn't find " << value << " in container" << std::endl;
		return ( false );
	}

	std::cout << "Found " << value << " in container" << std::endl;

	return ( true );
}

template <typename T>
void test( int size, int value )
{
	T c;
	for ( int i = 0; i < size; i++ )
		c.push_back( i + 1 );

	std::cout << "\n >>> Testing container of type " << typeid( T ).name() << " <<<" << std::endl;
	std::cout << "     | size :  " << size << std::endl;
	std::cout << "     | value : " << value << std::endl << std::endl;

	easyfind( c, value );
}