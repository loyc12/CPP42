#include "Dog.hpp"

// Constructors / Destructor

Dog::Dog()
{
	this->type = "dog";
	std::cout << "[ default constructor called (DOG) ] ";
}
Dog::Dog(const Dog &other)
{
	this->type = other.type;
	std::cout << "[ copy constructor called (DOG) ] ";
}
Dog &Dog::operator= (const Dog &other)
{
	this->type = other.type;
	std::cout << "[ operator constructor called (DOG) ] ";
	return *this;
}
Dog::~Dog()
{
	std::cout << "[ destructor called (DOG) ] ";
}

// Others

void	Dog::makeSound(void) const
{
	std::cout << "> WOOF !" << std::endl;
}