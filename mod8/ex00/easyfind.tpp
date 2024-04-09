#include <iostream>
#include "easyfind.hpp"

<<<<<<< HEAD
int	easyfind( std::vector<int> _container, int _value )
{
	std::vector<int>::iterator it;
	it = std::find( _container.begin(), _container.end(), _value );
	if ( it != _container.end() )
	{
		int index = std::distance( _container.begin(), it );
		std::cout << "  Found ( " << _value << " ) in container at index " << index << std::endl;
		return ( index );
	}
	std::cout << "  Could not find ( " << _value << " ) in container" << std::endl;

	return -1; // Value not found
}

int	easyfind( std::list<int> _container, int _value )
{
	std::list<int>::iterator it;
	it = std::find( _container.begin(), _container.end(), _value );
	if ( it != _container.end() )
	{
		int index = std::distance( _container.begin(), it );
		std::cout << "  Found ( " << _value << " ) in container at index " << index << std::endl;
		return ( index );
	}
	std::cout << "  Could not find ( " << _value << " ) in container" << std::endl;

	return -1; // Value not found
}

int	easyfind( std::deque<int> _container, int _value )
{
	std::deque<int>::iterator it;
	it = std::find( _container.begin(), _container.end(), _value );
	if ( it != _container.end() )
	{
		int index = std::distance( _container.begin(), it );
		std::cout << "  Found ( " << _value << " ) in container at index " << index << std::endl;
		return ( index );
	}
	std::cout << "  Could not find ( " << _value << " ) in container" << std::endl;

	return -1; // Value not found
}

int	easyfind( std::stack<int> _container, int _value )
{

	int i = 0;
    while ( !_container.empty() )
	{
		++i;
        if ( _container.top() == _value )
		{
			std::cout << "  Found ( " << _value << " ) in container after " << i << " attempt(s)" << std::endl;
            return true;
        }
        _container.pop();
    }
	std::cout << "  Could not find ( " << _value << " ) in container after " << i << " attempt(s)" << std::endl;

    return -1; // Value not found
}

int	easyfind( std::queue<int> _container, int _value )
{
	int i = 0;
	while ( !_container.empty() )
	{
		++i;
		if ( _container.front() == _value )
		{
			std::cout << "  Found ( " << _value << " ) in container after " << i << " attempt(s)" << std::endl;
			return true;
		}
		_container.pop();
	}
	std::cout << "  Could not find ( " << _value << " ) in container after " << i << " attempt(s)" << std::endl;

	return -1; // Value not found
}

int easyfind( std::priority_queue<int> _container, int _value )
{
	int i = 0;
	while ( !_container.empty() )
	{
		++i;
		if ( _container.top() == _value )
		{
			std::cout << "  Found ( " << _value << " ) in container after " << i << " attempt(s)" << std::endl;
			return true;
		}
		_container.pop();
	}
	std::cout << "  Could not find ( " << _value << " ) in container after " << i << " attempt(s)" << std::endl;

	return -1; // Value not found
=======
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
>>>>>>> tmp
}