#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	//std::cout << " : Called ScalConv default constructor";

	this->_scalar.c = "";
	this->_scalar.i = "";
	this->_scalar.f = "";
	this->_scalar.d = "";
}

ScalarConverter::ScalarConverter( std::string const &str )
{
	//std::cout << " : Called ScalConv param constructor";
	this->convert( str );
}

ScalarConverter::ScalarConverter( ScalarConverter const &other )
{
	//std::cout << " : Called ScalConv copy constructor";
	this->_scalar = other._scalar;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &other )
{
	//std::cout << " : Called ScalConv assign constructor";

	this->_scalar = other._scalar;

	return *this;
}

ScalarConverter::~ScalarConverter() { std::cout << " : Called ScalConv destructor"; }

void ScalarConverter::convert( std::string const &str )
{
	if		( isInt( str ))		{ this->convFromInt( str ); }
	else if	( isChar( str ))	{ this->convFromChar( str ); }
	else if	( isFloat( str ))	{ this->convFromFloat( str ); }
	else if	( isDouble( str ))	{ this->convFromDouble( str ); }
	else						{ this->badInput(); }
}
void ScalarConverter::convFromChar( std::string const &str )
{
	std::cout << "\n > found a Char" << std::endl;
	char c = str[ 0 ];

	this->_scalar.c = getChar( c );
	this->_scalar.i = getInt( c );
	this->_scalar.f = getFloat( c );
	this->_scalar.d = getDouble( c );
}
void ScalarConverter::convFromInt( std::string const &str )
{
	std::cout << "\n > found an Int" << std::endl;
	int i = std::stoi( str );

	this->_scalar.c = getChar( i );
	this->_scalar.i = getInt( i );
	this->_scalar.f = getFloat( i );
	this->_scalar.d = getDouble( i );
}
void ScalarConverter::convFromFloat( std::string const &str )
{
	std::cout << "\n > found a Float" << std::endl;
	float f = std::stof( str );

	this->_scalar.c = getChar( f );
	this->_scalar.i = getInt( f );
	this->_scalar.f = getFloat( f );
	this->_scalar.d = getDouble( f );
}
void ScalarConverter::convFromDouble( std::string const &str )
{
	std::cout << "\n > found a Double" << std::endl;
	double d = std::stod( str );

	this->_scalar.c = getChar( d );
	this->_scalar.i = getInt( d );
	this->_scalar.f = getFloat( d );
	this->_scalar.d = getDouble( d );
}
void ScalarConverter::badInput()
{
	std::cout << "\n > Bad input" << std::endl;

	this->_scalar.c = "n/a";
	this->_scalar.i = "n/a";
	this->_scalar.f = "n/a";
	this->_scalar.d = "n/a";
}

std::string ScalarConverter::getString() const
{
	std::string str = "\n";

	str += "char   : " + this->_scalar.c + "\n";
	str += "int    : " + this->_scalar.i + "\n";
	str += "float  : " + this->_scalar.f + "\n";
	str += "double : " + this->_scalar.d + "\n";

	return str;
}

std::ostream &operator<< ( std::ostream &out, const ScalarConverter &rhs )
{
	out << rhs.getString();
	return out;
}