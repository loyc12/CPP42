#include "easyfind.hpp"

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
}