#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

# include <vector>
# include <list>
# include <deque>
# include <forward_list>


template <typename T> int easyfind( T _container, int _value );
template <typename T> void test( int size, int value);

class UnhandledContainer : public std::exception
{
	public:
		virtual const char *what() const throw() { return "Container error : not a valid containers"; }
};

# include "easyfind.tpp"

#endif // EASYFIND_HPP