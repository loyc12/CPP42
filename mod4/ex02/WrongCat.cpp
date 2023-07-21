#include "WrongCat.hpp"

// Constructors / Destructor

WrongCat::WrongCat()
{
	this->type = "cat";
	std::cout << "[ default constructor called (WRONGCAT) ] ";
}
WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "[ copy constructor called (WRONGCAT) ] ";
}
WrongCat &WrongCat::operator= (const WrongCat &other)
{
	this->type = other.type;
	std::cout << "[ operator constructor called (WRONGCAT) ] ";
	return *this;
}
WrongCat::~WrongCat()
{
	std::cout << "[ destructor called (WRONGCAT) ] ";
}

// Others

void	WrongCat::makeSound(void) const
{
	std::cout << "> meeeeeoowwwwwwwwwwwwwww ~" << std::endl;
}