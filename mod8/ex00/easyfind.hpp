#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define XCPT public: const char *what() const throw()

// basic libs
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

# include <algorithm> // superfluous, as find is already in the std namespace

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

<<<<<<< HEAD
class BadContainer : public std::exception
{
	public:
		virtual const char *what() const throw() { return "Input error : not a valid integer container"; }
};
class UnhandledContainer : public std::exception
{
	public:
		virtual const char *what() const throw() { return "Container error : not a handled containers"; }
};
=======
class UnhandledContainer : public std::exception { XCPT { return "Container error : not a valid containers"; }};
>>>>>>> tmp

# include "easyfind.tpp"

#endif // EASYFIND_HPP