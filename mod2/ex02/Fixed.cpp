#include "Fixed.hpp"

// Constructors / Destructor
Fixed::Fixed()
{
	this->setRawBits(0);
	std::cout << "[ default constructor called ] ";
}
Fixed::Fixed(const int value)
{
	this->setRawBits(value * this->_frac_bit);
	std::cout << "[ int constructor called ] ";

}
Fixed::Fixed(const float value)
{
	this->setRawBits((int)(value * this->_frac_bit));
	std::cout << "[ float constructor called ] ";

}
Fixed::Fixed(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	std::cout << "[ copy constructor called ] ";
}
Fixed::~Fixed()
{
//	std::cout << "[ destructor called ] ";
}

// Operators
Fixed &Fixed::operator= (const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	std::cout << "[ operator constructor called ] ";
	return *this;
}
// function cannot be member of Fixed cause it needs to be a member of ostream
// this is because the ostream instance is the first argument of the "<<" operator
std::ostream &operator<< (std::ostream &out, const Fixed &fpn)
{
	out << fpn.toFloat();
	return (out);
}

Fixed Fixed::operator+ (const Fixed &other) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + other.getRawBits());
	return (tmp);
}
Fixed Fixed::operator- (const Fixed &other) const
{
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - other.getRawBits());
	return (tmp);
}
Fixed Fixed::operator* (const Fixed &other) const
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() * other.getRawBits()) / this->_frac_bit);
	return (tmp);
}
Fixed Fixed::operator/ (const Fixed &other) const
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


bool Fixed::operator!= (const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}
bool Fixed::operator> (const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator>= (const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator== (const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator<= (const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator< (const Fixed &other) const
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

// Min/Max
// static member functions have no 'this' to use
Fixed &Fixed::min(Fixed &fpn1, Fixed &fpn2)
{
	if (fpn1 > fpn2)
		return (fpn2);
	else
		return (fpn1);
}
Fixed &Fixed::max(Fixed &fpn1, Fixed &fpn2)
{
	if (fpn1 > fpn2)
		return (fpn1);
	else
		return (fpn2);
}
// function's return has to be const to be able to return a const var
const Fixed &Fixed::min(const Fixed &fpn1, const Fixed &fpn2)
{
	if (fpn1 > fpn2)
		return (fpn2);
	else
		return (fpn1);
}
// function's return has to be const to be able to return a const var
const Fixed &Fixed::max(const Fixed &fpn1, const Fixed &fpn2)
{
	if (fpn1 > fpn2)
		return (fpn1);
	else
		return (fpn2);
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
int Fixed::getFracBit() const
{
	return this->_frac_bit;
}
int Fixed::toInt() const
{
	return ((int)this->getRawBits() / this->_frac_bit);
}
float Fixed::toFloat() const
{
	return ((float)this->getRawBits() / this->_frac_bit);
}

