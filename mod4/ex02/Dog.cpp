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
	this->brain = new Brain(*other.brain);
	this->type = other.type;

	std::cout << "[ copy constructor called (DOG) ] ";
}
Dog &Dog::operator= (const Dog &other)
{
	if (this != &other)
	{
		*this->brain = *other.brain;
		this->type = other.type;
		std::cout << "[ operator constructor called (DOG) ] ";
	}
	else
		std::cout << "[ operator constructor cannot be called on itself (DOG) ] ";

	return *this;
}
Dog::~Dog()
{
	delete this->brain;

	std::cout << "[ destructor called (DOG) ] ";
}

// Others

void	Dog::makeSound(void) const
{
	std::cout << "> WOOF !" << std::endl;
}
void	Dog::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}
std::string	Dog::getIdea(int index)
{
	return (this->brain->getIdea(index));
}