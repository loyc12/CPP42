#include "addons.hpp"

// 0======== char stuff =========0

bool isChar( std::string const &str )
{ return ( str.length() == 1 ); }

bool isPrintableChar( char c )
{ return ( c >= 32 && c <= 126 ); }

std::string getChar( std::string const &str )
{
	if ( !isPrintableChar( str[ 0 ]))
		return "char   : Non displayable";
	return "char   : '" + str + "'";

}

// 0======== int stuff =========0

bool isInt( std::string const &str )
{
	for ( size_t i = 0; i < str.length(); i++ )
	{
		if ( i == 0 && ( str[ i ] == '-' || str[ i ] == '+' ))
			continue ;
		if ( !isdigit( str[ i ] ))
			return false;
	}
	return true;
}

// 0======== float stuff =========0

bool isFloat( std::string const &str )
{

}

// 0======== double stuff =========0

bool isDouble( std::string const &str )
{

}