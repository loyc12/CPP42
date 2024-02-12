#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <deque>
# include <queue>
# include <stack>

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

# include "easyfind.tpp"

#endif // EASYFIND_HPP