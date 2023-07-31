#include "Cat.hpp"

// Constructors / Destructor

Cat::Cat()
{
	this->type = "cat";
	this->brain = new Brain();

	std::cout << "[ default constructor called (CAT) ] ";
}
Cat::Cat(const Cat &other)
{
	this->brain = new Brain(*other.brain);
	this->type = other.type;

	std::cout << "[ copy constructor called (CAT) ] ";
}
Cat &Cat::operator= (const Cat &other)
{
	if (this != &other)
	{
		*this->brain = *other.brain;
		this->type = other.type;
		std::cout << "[ operator constructor called (CAT) ] ";
	}
	else
		std::cout << "[ operator constructor cannot be called on itself (CAT) ] ";
	return *this;
}
Cat::~Cat()
{
	delete this->brain;

	std::cout << "[ destructor called (CAT) ] ";
}

// Others

void	Cat::makeSound(void) const
{
	std::cout << "> meeeeeoowwwwwwwwwwwwwww ~" << std::endl;
}
void	Cat::addIdea(std::string idea)
{
	this->brain->addIdea(idea);
}
std::string	Cat::getIdea(int index)
{
	return (this->brain->getIdea(index));
}