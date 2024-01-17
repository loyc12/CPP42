#include "addons.hpp"

// 0======== char stuff =========0

bool isPrintable( char c )
{ return ( c >= 32 && c <= 126 ); }

bool isDigit( char c )
{ return ( c >= '0' && c <= '9' ); }

bool isChar( std::string const &str )
{ return ( str.length() == 1 && !isDigit( str[ 0 ])); }

std::string getChar( char c )
{
	if ( isPrintable( c ))	{ return ( "'" + std::string( 1, c ) + "'" ); }
	else					{ return ( "unprintable" ); }
}
std::string getChar( int i )
{
	if ( i < 0 || i >= 128 ) 	{ return ( "impossible" ); }
	else if ( isPrintable( i ))	{ return ( "'" + std::string( 1, i ) + "'" ); }
	else						{ return ( "unprintable" ); }
}
std::string getChar( float f )
{
	if ( f == NAN || f == INFINITY || f == -INFINITY )	{ return ( "impossible" ); }
	else if ( f < 0.0f || f >= 128.0f )					{ return ( "impossible" ); }
	else if ( isPrintable( static_cast<char>( f ) ))	{ return ( "'" + std::string( 1, f ) + "'" ); }
	else												{ return ( "unprintable" ); }
}
std::string getChar( double d )
{
	if ( d == NAN || d == INFINITY || d == -INFINITY )	{ return ( "impossible" ); }
	else if ( d < 0.0 || d >= 128.0 )					{ return ( "impossible" ); }
	else if ( isPrintable( static_cast<char>( d )))		{ return ( "'" + std::string( 1, d ) + "'" ); }
	else												{ return ( "unprintable" ); }
}


// 0======== int stuff =========0

bool isInt( std::string const &str )
{
	try
	{
		std::stoi( str );
		return true;
	}
	catch ( std::exception &e ) { return false; }
}

std::string getInt( char c )
{ return ( std::to_string( static_cast<int>( c ))); }
std::string getInt( int i )
{ return ( std::to_string( i )); }
std::string getInt( float f )
{
	if ( f == NAN || f == INFINITY || f == -INFINITY )	{ return ( "impossible" ); }
	else												{ return ( std::to_string( static_cast<int>( f ))); }
}
std::string getInt( double d )
{
	if ( d == NAN || d == INFINITY || d == -INFINITY )	{ return ( "impossible" ); }
	else												{ return ( std::to_string( static_cast<int>( d ))); }
}

// 0======== float stuff =========0

bool isFloat( std::string const &str )
{
	try
	{
		std::stof( str );
		return true;
	}
	catch ( std::exception &e ) { return false; }

}

std::string getFloat( char c )
{ return ( std::to_string( static_cast<float>( c ))); }
std::string getFloat( int i )
{ return ( std::to_string( static_cast<float>( i ))); }
std::string getFloat( float f )
{ return ( std::to_string( f )); }
std::string getFloat( double d )
{ return ( std::to_string( static_cast<float>( d ))); }

// 0======== double stuff =========0

bool isDouble( std::string const &str )
{
	try
	{
		std::stod( str );
		return true;
	}
	catch ( std::exception &e ) { return false; }
}

std::string getDouble( char c )
{ return ( std::to_string( static_cast<double>( c ))); }
std::string getDouble( int i )
{ return ( std::to_string( static_cast<double>( i ))); }
std::string getDouble( float f )
{ return ( std::to_string( static_cast<double>( f ))); }
std::string getDouble( double d )
{ return ( std::to_string( d )); }