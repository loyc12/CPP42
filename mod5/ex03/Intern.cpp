#include "Intern.hpp"

// Constructors - Destructor

Intern::Intern()
{
	std::cout << ": Called default constructor (INTERN) ";

	std::srand(std::time(NULL));
	this->number = rand() % 1048576;
}
Intern::Intern(const Intern &other)
{
	std::cout << ": Called copy constructor (INTERN) ";

	this->number = other.number;

//	std::cout << ": Copy-constructed " << this->name << " ( bureaucrat grade " << this->grade << " )" << std::endl; //	DEBUG
}
Intern &Intern::operator= (const Intern &other)
{
	std::cout << ": Called assignment operator (INTERN) ";

	this->number = other.number;

//	std::cout << ": Copied intern #" <<  << " " << std::endl; //	DEBUG

	return *this;
}
Intern::~Intern()
{
	std::cout << ": Called Destructor (INTERN) ";
}

// Others

AForm	*Intern::makeForm(std::string _formName, std::string _targetName) const
{
	return (NULL); //	DO FORM MAKING HERE (add nested error class);
}

std::ostream &operator<< (std::ostream &out, const Intern &rhs)
{
	out << "intern #" << rhs.number;
	return (out);
}