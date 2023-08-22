#include "Shrub.hpp"

// Constructors - Destructor

Shrub::Shrub()
{
	std::cout << "Called default constructor (SHRUB) ";
}
Shrub::Shrub(ShrubberyCreationForm *_scf, int _h_pos, int _v_pos)
{
	std::cout << "Called parameterized constructor (SHRUB) ";
	this->scf = _scf;
	this->horizontal_p = _h_pos;
	this->vertical_p = _v_pos;
}
Shrub::Shrub(const Shrub &other)
{
	std::cout << "Called copy constructor (SHRUB) ";
	this->horizontal_p = other.horizontal_p;
	this->scf = other.scf;
}
Shrub &Shrub::operator= (const Shrub &other)
{
	std::cout << "Called assignment operator (SHRUB) ";
	this->horizontal_p = other.horizontal_p;
	this->scf = other.scf;

	return *this;
}
Shrub::~Shrub()
{
	std::cout << "Called Destructor (SHRUB) ";
}

// Others

int	Shrub::getHPos(void) const
{
	return (this->horizontal_p);
}
int	Shrub::getVPos(void) const
{
	return (this->vertical_p);
}

std::ostream &operator<< (std::ostream &out, const Shrub &rhs)
{
	out << "shurb at pos ( " << rhs.getHPos() << ":" << rhs.getVPos() << " )";
	return (out);
}

// Shrubbers
void	Shrub::growShrub(void)
{
	this->scf->drawAt(this->getHPos() - 2, this->getVPos(), '/');
	this->scf->drawAt(this->getHPos() - 1, this->getVPos(), '~');
	this->scf->drawAt(this->getHPos() + 0, this->getVPos(), '~');
	this->scf->drawAt(this->getHPos() + 1, this->getVPos(), '~');
	this->scf->drawAt(this->getHPos() + 2, this->getVPos(), '\\');

	this->trunk_h = (rand() % 16) + 4;

	for (int i = 1; i < this->trunk_h; i++)
	{
		this->scf->drawAt(this->getHPos() - 1, this->getVPos() - i, '|');
		this->scf->drawAt(this->getHPos() + 0, this->getVPos() - i, '~');
		this->scf->drawAt(this->getHPos() + 1, this->getVPos() - i, '|');

		//spawn branches here
		if (!(rand() % 6))
			this->scf->drawAt(this->getHPos() - 2, this->getVPos() - i, '\\');
		if (!(rand() % 6))
			this->scf->drawAt(this->getHPos() + 2, this->getVPos() - i, '/');
	}
}