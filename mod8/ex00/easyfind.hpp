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

# define NOT_CONTAINER 0
# define SEQ_CONTAINER 1
# define ADAPT_CONTAINER 2
# define ASSOC_CONTAINER 3


template <typename T> void easyfind( T _container, int _value );

// Explicitly defining the types of containers that are valid
int	getConType( std::vector<int>& c )			{ (void)c; return SEQ_CONTAINER; }
int	getConType( std::list<int>& c )				{ (void)c; return SEQ_CONTAINER; }
int	getConType( std::deque<int>& c )			{ (void)c; return SEQ_CONTAINER; }

int	getConType( std::set<int>& c )				{ (void)c; return SEQ_CONTAINER; }
int	getConType( std::multiset<int>& c )			{ (void)c; return SEQ_CONTAINER; }
template < typename T >
int	getConType( std::map<T, int>& c )			{ (void)c; return SEQ_CONTAINER; }
template < typename T >
int	getConType( std::multimap<T, int>& c )		{ (void)c; return SEQ_CONTAINER; }

int	getConType( std::stack<int>& c )			{ (void)c; return ADAPT_CONTAINER; }
int	getConType( std::queue<int>& c )			{ (void)c; return ASSOC_CONTAINER; }
int	getConType( std::priority_queue<int>& c )	{ (void)c; return ADAPT_CONTAINER; }

template < typename T > // Default case ( meaning all other types are invalid )
int	getConType( T& c ) { (void)c; return NOT_CONTAINER; }

class BadContainer : public std::exception
{
	public:
		virtual const char *what() const throw() { return "Input error : not a valid integer container"; }
};
class UnhandledContainer : public std::exception
{
	public:
		virtual const char *what() const throw() { return "Container error : not one of the handled containers"; }
};

# include "easyfind.tpp"

#endif // EASYFIND_HPP