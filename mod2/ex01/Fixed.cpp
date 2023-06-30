#include "Fixed.hpp"

// Constructors / Destructor
Fixed::Fixed()
{
	this->setRawBits(0);
}
Fixed::Fixed(const int value)
{
	this->setRawBits(value * this->_frac_bit);
}
Fixed::Fixed(const float value)
{
	this->setRawBits((int)(value * this->_frac_bit));
}
Fixed::Fixed(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
}
Fixed::~Fixed()
{
}

// Operators
Fixed &Fixed::operator= (const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	return *this;
}
// "friend" keyword allows us to create/override non-member functions
// function cannot be member of Fixed cause it needs to be a member of ostream
// this is because the ostream instance if the first argument of the "<<" operator
std::ostream &operator<< (std::ostream &out, const Fixed &fpn)
{
	out << fpn.toFloat();
	return (out);
}


// Others
int Fixed::getRawBits() const
{
	return this->_raw_value;
}
void Fixed::setRawBits(int raw_value)
{
	this->_raw_value = raw_value;
}
int Fixed::toInt() const
{
	return ((int)this->getRawBits() / this->_frac_bit);
}
float Fixed::toFloat() const
{
	return ((float)this->getRawBits() / this->_frac_bit);
}

