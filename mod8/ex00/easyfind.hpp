#ifndef EASYFIND_HPP
# define EASYFIND_HPP

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

// containers
# include <vector>
# include <list>
# include <deque>

/*

// CPP11 containers
# include <array>
# include <forward_list>

// associative containers
# include <map>
# include <set>
# include <multimap>
# include <multiset>

// adapter containers
# include <stack>
# include <queue>
# include <priority_queue>

*/

class UnhandledContainer : public std::exception
{
	public:
		virtual const char *what() const throw() { return "Container error : not a valid containers"; }
};

# include "easyfind.tpp"

#endif // EASYFIND_HPP