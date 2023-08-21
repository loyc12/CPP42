#include "AForm.hpp"

// Constructors - Destructor

AForm::AForm()
{
	std::cout << "Called default constructor (FORM) ";

	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
	this->name = "UNINITIALIZED";
}
AForm::AForm(const std::string _name, const int _signGrade, const int _execGrade)
{
	std::cout << "Called parameterized constructor (FORM) ";

	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
	this->setSignGrade(_signGrade);
	this->setExecGrade(_execGrade);
	this->name = _name;

	std::cout << "Constructed form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;
}
AForm::AForm(const AForm &other)
{
	std::cout << "Called copy constructor (FORM) ";

	this->isSigned = false;
	this->signGrade = 150;
	this->execGrade = 150;
	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->name = other.getName();

	std::cout << "Copied form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;
}

AForm &AForm::operator= (const AForm &other)
{
	std::cout << "Called assignment operator (FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->name = other.getName();

	std::cout << "Copied form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " )" << std::endl;

	return *this;
}

AForm::~AForm()
{
	std::cout << "Destroying form : " << this->name << " ( grade " << this->signGrade << "/" << this->execGrade << " ) ";
}

// Setters - Getters

void	AForm::setSignGrade(const int value)
{
	if (value < 1)
		throw GradeTooHigh();
	else if (value > 150)
		throw GradeTooLow();
	else
		this->signGrade = value;
}
void	AForm::setExecGrade(const int value)
{
	if (value < 1)
		throw GradeTooHigh();
	else if (value > 150)
		throw GradeTooLow();
	else
		this->execGrade = value;
}
void	AForm::setName(const std::string _name)
{
	this->name = _name;
}
int	AForm::getSignGrade(void) const
{
	return (this->signGrade);
}
int	AForm::getExecGrade(void) const
{
	return (this->execGrade);
}
const std::string	AForm::getName(void) const
{
	return (this->name);
}
bool	AForm::canBeExec(void) const
{
	return (this->isSigned);
}

// Others

void	AForm::beSigned(Bureaucrat const &b)
{
	if (this->getSignGrade() < b.getGrade())
		throw GradeTooLow();
	else
		this->isSigned = true;
}
void	AForm::beExecuted(Bureaucrat const &b) const
{
	if (!this->isSigned)
		throw FormUnsigned();
	else if (this->getExecGrade() < b.getGrade())
		throw GradeTooLow();
	else
		return; //	TODO
}

std::ostream &operator<< (std::ostream &out, const AForm &rhs)
{
	out << rhs.getName() << " ( sign/exec form of grade " << rhs.getSignGrade()<< "/" << rhs.getExecGrade() << " )";
	return (out);
}