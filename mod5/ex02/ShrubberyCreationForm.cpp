#include "ShrubberyCreationForm.hpp"

// Constructors - Destructor

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Called default constructor (S.C.FORM) ";

	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setName("Shrubbery Creation");
	this->target = "UNINITIALIZED";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)
{
	std::cout << "Called parameterized constructor (S.C.FORM) ";

	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setName("Shrubbery Creation");
	this->target = _target;

	std::cout << "Constructed shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "Called copy constructor (S.C.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	std::cout << "Copied shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
	std::cout << "Called assignment operator (S.C.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	std::cout << "Copied shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl;

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destroying shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " ) ";
}

// Others

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}
void	ShrubberyCreationForm::beExecuted(Bureaucrat const &b) const
{
	std::srand(std::time(NULL));

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
	std::srand(std::time(NULL));

	this->initArea();

	for (int i = 0; i < 16; i++)
		this->addShrub();

	this->drawArea();
}
void	ShrubberyCreationForm::addShrub()
{
	int h_pos = (rand() % AREA_WIDTH - 4) + 2;

	Shrub s(this, h_pos, this->soil_h);

	std::cout << std::endl << s << std::endl;

	s.growShrub();

	// call shrub methods to put stuff on area
}

char	ShrubberyCreationForm::getGrassChar(void) const
{
	int value = rand() % 8;

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
		return ('!');
	else if (value == 6)
		return ('?');
	else if (value == 7)
		return ('*');
	return (' ');
}
char	ShrubberyCreationForm::getBarkChar(void) const
{
	int value = rand() % 16;

	if (value == 0)
		return ('.');
	else if (value == 1)
		return (',');
	else if (value == 2)
		return ('\'');
	else if (value == 3)
		return ('o');
	return ('~');
}

void	ShrubberyCreationForm::initArea(void)
{
	this->area_w = AREA_WIDTH;
	this->area_h = AREA_HEIGHT;
	this->soil_h = AREA_HEIGHT - (int)(SOIL_RATIO * AREA_HEIGHT);

	char	c;

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		if (y == 0 || y == AREA_HEIGHT - 1)
			c = '-';
		else if (y < this->soil_h)
			c = ' ';
		else
			c = '#';

		for (int x = 0; x < AREA_WIDTH; x++)
		{
			if (x == 0 || x == AREA_WIDTH - 1)
				this->area[y][x] = '|';
			else if (y == this->soil_h)
				this->area[y][x] = this->getGrassChar();
			else
				this->area[y][x] = c;
		}
	}
}
void	ShrubberyCreationForm::drawArea(void)
{
	std::cout << std::endl;

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		for (int x = 0; x < AREA_WIDTH; x++)
		{
			std::cout << this->area[y][x];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}
void	ShrubberyCreationForm::setChar(int x, int y, char c)
{
	if (0 < x && x < AREA_WIDTH - 1 && 0 < y && y < AREA_HEIGHT - 1 )
		this->area[y][x] = c;
}
char	ShrubberyCreationForm::getChar(int x, int y) const
{
	if (0 < x && x < AREA_WIDTH - 1 && 0 < y && y < AREA_HEIGHT - 1 )
		return (this->area[y][x]);
	return ('\0');
}