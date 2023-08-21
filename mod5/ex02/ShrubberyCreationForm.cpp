#include "ShrubberyCreationForm.hpp"

// Constructors - Destructor

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Called default constructor (S.C.FORM) ";

	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setName("Srubbery Creation");
	this->target = "UNINITIALIZED";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)
{
	std::cout << "Called parameterized constructor (S.C.FORM) ";

	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setName("Srubbery Creation");
	this->target = _target;

	std::cout << "Constructed srubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "Called copy constructor (S.C.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	std::cout << "Copied srubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
	std::cout << "Called assignment operator (S.C.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	std::cout << "Copied srubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destroying srubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " ) ";
}

// Others

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}
void	ShrubberyCreationForm::beExecuted(Bureaucrat const &b) const
{
	if (!this->canBeExec())
		throw FormUnsigned();
	else if (this->getExecGrade() < b.getGrade())
		throw GradeTooLow();
	else if (rand() % 2)
		std::cout << this->target << " has been shrubbed" << std::endl;
	else
		std::cout << this->target << "'s shrubbing has failed" << std::endl;
}

// Shrubbing

void	ShrubberyCreationForm::testShrub(void)
{
	this->initArea();
	this->drawArea();
}

char	ShrubberyCreationForm::getGrassChar(void)
{
	int value = rand() % 5;
	if (value == 0)
		return ('.');
	else if (value == 1)
		return (',');
	else if (value == 2)
		return ('i');
	else if (value == 3)
		return ('j');
	else if (value == 4)
		return ('l');
	else if (value == 5)
		return ('|');
	else if (value == 6)
		return ('/');
	else if (value == 7)
		return ('\\');
	return (' ');
}

void	ShrubberyCreationForm::initArea(void)
{
	this->area_w = AREA_WIDTH;
	this->area_h = AREA_HEIGHT;
	this->soil_h = (int)(SOIL_RATIO * AREA_HEIGHT);

	char	c;

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		if (y == 0 || y == AREA_HEIGHT - 1)
			c = '-';
		else if (y < AREA_HEIGHT - this->soil_h)
			c = ' ';
		else
			c = '#';

		for (int x = 0; x < AREA_WIDTH; x++)
		{
			if (x == 0 || x == AREA_WIDTH - 1)
				this->area[y][x] = '|';
			else if (y == AREA_HEIGHT - this->soil_h)
				this->area[y][x] = this->getGrassChar();
			else
				this->area[y][x] = c;
		}
	}
}
void	ShrubberyCreationForm::drawArea(void)
{
	std::cout << std::endl;

	for (int y = 0; y < AREA_HEIGHT; ++y)
	{
		for (int x = 0; x < AREA_WIDTH; ++x)
		{
			std::cout << this->area[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}