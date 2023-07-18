#include "Dog.hpp"

// Constructors / Destructor

Dog::Dog()
{
	this->type = "dog";
	this->brain = new Brain();

	std::cout << "[ default constructor called (DOG) ] ";
}
Dog::Dog(const Dog &other)
{
	this->type = other.type;
	this->brain = other->brain;

	std::cout << "[ copy constructor called (DOG) ] ";
}
Dog &Dog::operator= (const Dog &other)
{
	this->type = other.type;
	this->brain = other->brain;

	std::cout << "[ operator constructor called (DOG) ] ";
	return *this;
}
Dog::~Dog()
{
	delete this->brain;
	std::cout << "[ destructor called (DOG) ] ";
}

// Others

void	Dog::makeSound(void)
{
	std::cout << "> WOOF !" << std::endl;
}