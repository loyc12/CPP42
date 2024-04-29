#ifndef DEFLIBS_HPP
# define DEFLIBS_HPP

# define DEBUG_MODE	false

// Basic Libraries
# include <exception>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

// Definitions
# define elif	else if
# define byte	unsigned char

# define TTT	template< typename T >

# define DEBUG( x )	if ( DEBUG_MODE ) { x; }
# define XCPT( x )	public std::exception { public: virtual const char *what() const throw() { return x; }}

# define STR	std::string

#endif // DEFLIBS_HPP
