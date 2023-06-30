#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	this->setRawBits(0);
}
Fixed::Fixed(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
}

// Operators
Fixed &Fixed::operator= (const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	return *this;
}

// Destructor
Fixed::~Fixed()
{
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

