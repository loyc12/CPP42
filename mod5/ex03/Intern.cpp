#include "Intern.hpp"

// Constructors - Destructor

Intern::Intern()
{
	std::cout << ": Called default constructor (INTERN) ";

	std::srand(std::time(NULL));
	this->number = rand() % 10000;
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

int	Intern::getNumber(void) const
{
	return (this->number);
}

int	Intern::findFormID(std::string form) const
{
	std::string forms[3] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
	};

	int i = 0;
	while (i < 3 && form.compare(forms[i]))
		i++;

	return (i);
}

AForm	*Intern::makeForm(std::string _formName, std::string _targetName) const
{
	AForm	*form;

	switch (this->findFormID(_formName))
	{
		case 0:
			form = new ShrubberyCreationForm(_targetName);
			break;
		case 1:
			form = new PresidentialPardonForm(_targetName);
			break;
		case 2:
			form = new RobotomyRequestForm(_targetName);
			break;
		default:
			throw InvalidFormName();
	}
	std::cout << std::endl << std::endl << *this << " successfuly created the " << _formName << " form targeting " << _targetName << std::endl;

	return (form);
}

std::ostream &operator<< (std::ostream &out, const Intern &rhs)
{
	out << "Intern #" << rhs.getNumber();
	return (out);
}