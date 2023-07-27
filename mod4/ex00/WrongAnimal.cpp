#include "WrongAnimal.hpp"

// Constructors / Destructor

WrongAnimal::WrongAnimal()
{
	this->type = "unknown";
	std::cout << "[ default constructor called (WRONGANIMAL) ] ";
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "[ copy constructor called (WRONGANIMAL) ] ";
}
WrongAnimal &WrongAnimal::operator= (const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "[ operator constructor called (WRONGANIMAL) ] ";
	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "[ destructor called (WRONGANIMAL) ] ";
}

// Others

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* sounds beyond the mere scope of human comprehension, damning the pityful soul of whomever is unfortunate enough to heard them *" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}