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

Fixed Fixed::operator+ (const Fixed &other)
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + other.getRawBits());
	return (tmp);
}
Fixed Fixed::operator- (const Fixed &other)
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - other.getRawBits());
	return (tmp);
}
Fixed Fixed::operator* (const Fixed &other)
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() * other.getRawBits()) / this->_frac_bit);
	return (tmp);
}
Fixed Fixed::operator/ (const Fixed &other)
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() * this->_frac_bit) / other.getRawBits());
	return (tmp);
}
Fixed &Fixed::operator+= (const Fixed &other)
{
	this->setRawBits(this->getRawBits() + other.getRawBits());
	return (*this);
}
Fixed &Fixed::operator-= (const Fixed &other)
{
	this->setRawBits(this->getRawBits() - other.getRawBits());
	return (*this);
}
Fixed &Fixed::operator*= (const Fixed &other)
{
	this->setRawBits((this->getRawBits() * other.getRawBits()) / this->_frac_bit);
	return (*this);
}
Fixed &Fixed::operator/= (const Fixed &other)
{
	this->setRawBits((this->getRawBits() * this->_frac_bit) / other.getRawBits());
	return (*this);
}


bool Fixed::operator!= (const Fixed &other)
{
	return (this->getRawBits() != other.getRawBits());
}
bool Fixed::operator> (const Fixed &other)
{
	return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator>= (const Fixed &other)
{
	return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator== (const Fixed &other)
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator<= (const Fixed &other)
{
	return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator< (const Fixed &other)
{
	return (this->getRawBits() < other.getRawBits());
}


// prefix operation (++i)
Fixed &Fixed::operator++ ()
{
	++(this->_raw_value);
	return (*this);
}
// prefix operation (--i)
Fixed &Fixed::operator-- ()
{
	--(this->_raw_value);
	return (*this);
}
// dummy int passed as param to specifies postfix operation (i++)
// returns a copy rather than a ref cause else error
Fixed Fixed::operator++ (int)
{
	Fixed tmp = *this;
	++(this->_raw_value);
	return (tmp);
}
// dummy int passed as param to specifies postfix operation (i--)
// returns a copy rather than a ref cause else error
Fixed Fixed::operator-- (int)
{
	Fixed tmp = *this;
	--(this->_raw_value);
	return (tmp);
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

