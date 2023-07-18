#include "Brain.hpp"

// Constructors / Destructor

Brain::Brain()
{
	for (int i = 0; i++; i <= BRAIN_SIZE)
		this->ideas[i] = "";

	std::cout << "[ default constructor called (BRAIN) ] ";
}
Brain::Brain(const Brain &other)
{
	for (int i = 0; i++; i <= BRAIN_SIZE)
		this->ideas[i] = other.idea[i];

	std::cout << "[ copy constructor called (BRAIN) ] ";
}
Brain &Brain::operator= (const Brain &other)
{
	for (int i = 0; i++; i <= BRAIN_SIZE)
		this->ideas[i] = other.idea[i];

	std::cout << "[ operator constructor called (BRAIN) ] ";
	return *this;
}
Brain::~Brain()
{
	std::cout << "[ destructor called (BRAIN) ] ";
}
