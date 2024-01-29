#include "addons.hpp"

std::string makeString( char c )
{ return ( std::to_string( c )); }
std::string makeString( int i )
{ return ( std::to_string( i )); }

std::string makeString( float f )
{
	std::ostringstream ss;
	ss << std::fixed << std::setprecision( 1 ) << f << "f";
	return ( ss.str() );
}
std::string makeString( double d )
{
	std::ostringstream ss;
	ss << std::fixed << std::setprecision( 1 ) << d;
	return ( ss.str() );
}

// 0======== text stuff =========0

bool isText( std::string const &str ) // check if the value is either NAN, INFINITY, INF, -INFINITY or -INF
{
	if ( str == "NAN" || str == "NANF" || str == "INFINITY" || str == "INF" || str == "INFF" || str == "-INFINITY" || str == "-INF" || str == "-INFF")
		{ return true; }

	return false;
}


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
	for ( size_t i = 0; i < str.length(); i++ )
	{
		if ( i == 0 && ( str[ i ] == '-' || str[ i ] == '+' ))	{ continue; }
		if ( !isDigit( str[ i ] ))								{ return false; }
	}
	return true;
}

std::string getInt( char c )
{ return ( makeString( static_cast<int>( c ))); }
std::string getInt( int i )
{ return ( makeString( i )); }

std::string getInt( float f )
{
	if ( f == NAN || f == INFINITY || f == -INFINITY )	{ return ( "impossible" ); }
	else												{ return ( makeString( static_cast<int>( f ))); }
}
std::string getInt( double d )
{
	if ( d == NAN || d == INFINITY || d == -INFINITY )	{ return ( "impossible" ); }
	else												{ return ( makeString( static_cast<int>( d ))); }
}

// 0======== float stuff =========0

bool isFloat( std::string const &str )
{
	bool f = false;

	if ( str[ str.length() - 1 ] != 'f' )						{ return false; }
	else if ( str.length() < 2 )								{ return false; }

	for ( size_t i = 0; i < str.length() - 1; i++ )
	{
		if ( str[ i ] == '.' ) {
			if ( f )											{ return false; }
			f = true;											  continue; }
		if ( i == 0 && ( str[ i ] == '-' || str[ i ] == '+' ))	{ continue; }
		if ( !isDigit( str[ i ] ))								{ return false; }
	}

	try
	{
		std::stof( str );
		return true;
	}
	catch ( std::exception &e ) { return false; }
}

std::string getFloat( char c )
{ return ( makeString( static_cast<float>( c ))); }
std::string getFloat( int i )
{ return ( makeString( static_cast<float>( i ))); }
std::string getFloat( float f )
{ return ( makeString( static_cast<float>( f ))); }
std::string getFloat( double d )
{ return ( makeString( static_cast<float>( d ))); }

// 0======== double stuff =========0

bool isDouble( std::string const &str )
{
	bool f = false;

	if ( isText( str ))											{ return true; }
	if ( str.length() < 2 )										{ return false; }

	for ( size_t i = 0; i < str.length(); i++ )
	{
		if ( str[ i ] == '.' ) {
			if ( f )											{ return false; }
			f = true;											  continue; }
		if ( i == 0 && ( str[ i ] == '-' || str[ i ] == '+' ))	{ continue; }
		if ( !isDigit( str[ i ] ))								{ return false; }
	}

	try
	{
		std::stod( str );
		return true;
	}
	catch ( std::exception &e ) { return false; }
}

std::string getDouble( char c )
{ return ( makeString( static_cast<double>( c ))); }
std::string getDouble( int i )
{ return ( makeString( static_cast<double>( i ))); }
std::string getDouble( float f )
{ return ( makeString( static_cast<double>( f ))); }
std::string getDouble( double d )
{ return ( makeString( d )); }