#include "ShrubberyCreationForm.hpp"

// Constructors - Destructor

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << ": Called default constructor (S.C.FORM) ";

	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setName("Shrubbery Creation");
	this->target = "UNINITIALIZED";

//	std::srand(std::time(NULL));
	this->initArea();
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)
{
	std::cout << ": Called parameterized constructor (S.C.FORM) ";

	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setName("Shrubbery Creation");
	this->target = _target;

//	std::srand(std::time(NULL));
	this->initArea();

//	std::cout << ": Constructed shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl; //	DEBUG
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << ": Called copy constructor (S.C.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

//	std::srand(std::time(NULL));
	this->initArea();

//	std::cout << ": Copy-constructed shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl; //	DEBUG
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &other)
{
	std::cout << ": Called assignment operator (S.C.FORM) ";

	this->setSignGrade(other.getSignGrade());
	this->setExecGrade(other.getExecGrade());
	this->setName(other.getName());
	this->target = other.getTarget();

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		for (int x = 0; x < AREA_WIDTH; x++)
		{
			this->area[y][x] = other.area[y][x];
		}
	}

//	std::cout << ": Copied shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " )" << std::endl; //	DEBUG

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << ": Destroying shrubbery creation form for " << this->target << " ( grade " << this->getSignGrade() << "/" << this->getExecGrade() << " ) ";
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
	this->writeArea();
	std::cout << this->target << " has been shrubbed" << std::endl << std::endl;
}

// Shrubbing

void	ShrubberyCreationForm::initArea(void)
{
	this->area_w = AREA_WIDTH;
	this->area_h = AREA_HEIGHT;
	this->soil_h = AREA_HEIGHT - (int)(SOIL_RATIO * AREA_HEIGHT);

	char	c;

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		if (y == 0 || y == AREA_HEIGHT - 1)
			c = HORIZONTAL_LINE;
		else if (y < this->soil_h)
			c = SKY_CHAR;
		else
			c = GROUND_CHAR;

		for (int x = 0; x < AREA_WIDTH; x++)
		{
			if (x == 0 || x == AREA_WIDTH - 1)
			{
				if (y == 0 || y == AREA_HEIGHT - 1)
					this->area[y][x] = CORNER_LINE;
				else
					this->area[y][x] = VERTICAL_LINE;
			}
			else if (y == this->soil_h)
				this->area[y][x] = this->getGrassChar();
			else
				this->area[y][x] = c;
		}
	}

	this->addShrubs(2 + (rand() % 16) + (rand() % 16) + (rand() % 8));
}
void	ShrubberyCreationForm::addShrubs(int count)
{
	for (int i = 0; i < count; i++)
	{
		int h_pos = (rand() % (AREA_WIDTH - 4)) + 2;

		Shrub s(this, h_pos, this->soil_h);

//		std::cout << std::endl << s << std::endl; //	DEBUG

		s.growShrub();
	}
}
void	ShrubberyCreationForm::drawArea(void) const //		PRINTS IN TERMINAL
{
	std::cout << std::endl;

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		for (int x = 0; x < AREA_WIDTH; x++)
		{
			char c = this->area[y][x];
			if (c == HORIZONTAL_LINE || c == VERTICAL_LINE || c == CORNER_LINE)
				std::cout << DCYAN;
			else if (c == GROUND_CHAR || c == ROOT_CHAR)
				std::cout << DYELLOW;
			else if (c == '|' || c == '\\' || c == '/' || c == ',' || c == '\'' || c == '~') // || c == 'o' || c == '.')
				std::cout << DRED;
			else if (c != ' ') //	GREEN BY DEFAULT
				std::cout << DGREEN;
			std::cout << c;
		}
		std::cout << std::endl;
	}

	std::cout << GREEN; //	REVERTS TEXT TO BOLD GREEN
	std::cout << std::endl;
}
void	ShrubberyCreationForm::writeArea(void) const //		PRINTS IN FILE
{
	std::ofstream output;

 	output.open(this->target + "_Shrubbery", std::ios::out | std::ios::trunc);
	if (!output.is_open())
		throw FileError();

	for (int y = 0; y < AREA_HEIGHT; y++)
	{
		for (int x = 0; x < AREA_WIDTH; x++)
		{
  			output << this->area[y][x];
		}
		output << std::endl;
	}
  	output.close();

	this->drawArea(); //			COMMENT ME TO STOP TERMINAL PRINTING
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
	int value = rand() % 8;

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
char	ShrubberyCreationForm::getLeafChar(void) const
{
	int value = rand() % 8;

	if (value == 0)
		return ('o');
	else if (value == 1)
		return ('0');
	else if (value == 2)
		return ('*');
	else if (value == 3)
		return ('e');
	return ('@');
}
