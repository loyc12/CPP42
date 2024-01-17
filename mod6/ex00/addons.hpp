#ifndef ADDONS_HPP
# define ADDONS_HPP
# include <iostream>

// 0======== char stuff =========0

bool isPrintable( char c );
bool isDigit( char c );
bool isChar( std::string const &str );

std::string getChar( char c );
std::string getChar( int i );
std::string getChar( float f );
std::string getChar( double d );

// 0======== int stuff =========0

bool isInt( std::string const &str );

std::string getInt( char c );
std::string getInt( int i );
std::string getInt( float f );
std::string getInt( double d );

// 0======== float stuff =========0

bool isFloat( std::string const &str );

std::string getFloat( char c );
std::string getFloat( int i );
std::string getFloat( float f );
std::string getFloat( double d );

// 0======== double stuff =========0

bool isDouble( std::string const &str );

std::string getDouble( char c );
std::string getDouble( int i );
std::string getDouble( float f );
std::string getDouble( double d );

#endif // ADDONS_HPP