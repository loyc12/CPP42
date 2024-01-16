#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
	std::cout << " : Called ScalConv default constructor";

	this->_sv.c = 0;
	this->_sv.i = 0;
	this->_sv.f = 0.0f;
	this->_sv.d = 0.0;

	this->_ss.c = "";
	this->_ss.i = "";
	this->_ss.f = "";
	this->_ss.d = "";
}

ScalarConverter::ScalarConverter( std::string const &str )
{
	std::cout << " : Called ScalConv param constructor";
	this->convertVal( str );
}

ScalarConverter::ScalarConverter( ScalarConverter const & other )
{
	std::cout << " : Called ScalConv copy constructor";
	this->_sv = other._sv;
	this->_ss = other._ss;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const & other )
{
	std::cout << " : Called ScalConv assign constructor";

	this->_sv = other._sv;
	this->_ss = other._ss;

	return *this;
}

ScalarConverter::~ScalarConverter()
{ std::cout << " : Called ScalConv destructor"; }

void ScalarConverter::convertVal( std::string const & str )
{
	if ( isChar( str ))
		this->convChar();
	else if ( isInt( str ))
		this->convInt();
	else if ( isFloat( str ))
		this->convFloat();
	else if ( isDouble( str ))
		this->convDouble();
	else
		std::cout << " : Invalid input";
}
void ScalarConverter::convChar() const
{

}
void ScalarConverter::convInt() const
{

}
void ScalarConverter::convFloat() const
{

}
void ScalarConverter::convDouble() const
{

}

void ScalarConverter::getScalarStrings() const
{

}

std::ostream &operator<< ( std::ostream &out, const ScalarConverter &rhs )
{
	out << rhs.print();
	return out;
}