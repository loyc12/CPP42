#include "Fixed.hpp"

// Constructors / Destructor
Fixed::Fixed()
{
	this->setRawBits(0);
	std::cout << "[ default constructor called ] ";
}
Fixed::Fixed(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	std::cout << "[ copy constructor called ] ";
}
Fixed::~Fixed()
{
	std::cout << "[ destructor called ] ";
}

// Operators
Fixed &Fixed::operator= (const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	std::cout << "[ operator constructor called ] ";
	return *this;
}

// Getters / Setters
int Fixed::getRawBits() const
{
	return this->_raw_value;
}
void Fixed::setRawBits(int raw_value)
{
	this->_raw_value = raw_value;
}

