#include "Animal.hpp"

// Constructors / Destructor

Animal::Animal()
{
	this->type = "unknown";
	std::cout << "[ default constructor called (ANIMAL) ] ";
}
Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "[ copy constructor called (ANIMAL) ] ";
}
Animal &Animal::operator= (const Animal &other)
{
	this->type = other.type;
	std::cout << "[ operator constructor called (ANIMAL) ] ";
	return *this;
}
Animal::~Animal()
{
	std::cout << "[ destructor called (ANIMAL) ] ";
}

// Others

void	Animal::makeSound(void) const
{
	std::cout << "* sounds beyond the mere scope of human comprehension, damning the pityful soul of whomever is unfortunate enough to heard them *" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}