#include "PresidentialPardonForm.hpp"

// Constructors - Destructor

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << ": Called default constructor (P.P.FORM) ";

	this->setSignGrade(25);
	this->setExecGrade(5);
	this->setName("Presidential Pardon");
	this->target = "UNINITIALIZED";
}
PresidentialPardonForm::PresidentialPardonForm(const std::string _target)
{
	std::cout << ": Called parameterized constructor (P.P.FORM) ";

	this->setSignGrade(25);
	this->setExecGrade(5);
	this->setName("Presidential Pardon");
	this->target = _target;

//	std::cout << ": Constructed presidential pardon form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl; //	DEBUG
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << ": Called copy constructor (P.P.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

//	std::cout << ": Copy-constructed  presidential pardon form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl; //	DEBUG
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &other)
{
	std::cout << ": Called assignment operator (P.P.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

//	std::cout << ": Copied presidential pardon form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl; //	DEBUG

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << ": Destroying presidential pardon form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " ) ";
}

// Others

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}
void	PresidentialPardonForm::beExecuted(Bureaucrat const &b) const
{
	if (!this->canBeExec())
		throw FormUnsigned();
	else if (this->getExecGrade() < b.getGrade())
		throw GradeTooLow();
	else
		std::cout << b.getName() << " has pardonned " << this->target << " (*sigh*)" << std::endl << std::endl;
}