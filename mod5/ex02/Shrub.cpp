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
	this->trunk_h = 2 + (rand() % 21);
	this->trunk_w = 1 + (trunk_h / 5);

	int i;
	int	leftOffset = ((this->trunk_w + 0) / 2);
	int	rightOffset = ((this->trunk_w + 1) / 2);
	int	branchLeftH = this->getHPos() - leftOffset - 1;
	int	branchrightH = this->getHPos() + rightOffset + 1;

	for (i = 0; i < this->trunk_h; i++)
	{
		int	branchV = this->getVPos() - i;

		if (this->trunk_w == 1)
			this->scf->setChar(this->getHPos() + 0, this->getVPos() - i, '|');
		else if (i == 0)
		{
			this->scf->setChar(branchLeftH, this->getVPos() - i, '/');
			this->scf->setChar(branchrightH, this->getVPos() - i, '\\');
			for (int j = -leftOffset; j <= rightOffset; j++)
				this->scf->setChar(this->getHPos() + j, this->getVPos() - i, this->scf->getBarkChar());
		}
		else
		{
			this->scf->setChar(this->getHPos() - leftOffset, this->getVPos() - i, '|');
			this->scf->setChar(this->getHPos() + rightOffset, this->getVPos() - i, '|');
			for (int j = -(leftOffset - 1); j <= rightOffset - 1; j++)
				this->scf->setChar(this->getHPos() + j, this->getVPos() - i, this->scf->getBarkChar());
		}
		if (i != 0 && i < this->trunk_h - 2)
		{
			if (!(rand() % 8) && this->scf->getChar(branchLeftH, branchV + 1) != '\\')
				this->branchLeft(branchLeftH, branchV, 1 + (rand() % this->trunk_w));

			if (!(rand() % 8) && this->scf->getChar(branchrightH, branchV + 1) != '/')
				this->branchRight(branchrightH, branchV, 1 + (rand() % this->trunk_w));
		}
	}

	this->growBush(this->getHPos(), this->getVPos() - this->trunk_h, this->trunk_w * 2);
}
void	Shrub::growBush(int h_pos, int v_pos, int size)
{
	for (int y = 0; y < size * 2; y++)
	{
		int	leftOffset = ((this->trunk_w + 0) / 2) + size + (rand() % 3);
		int	rightOffset = ((this->trunk_w + 1) / 2) + size + (rand() % 3);

		for (int x = -(leftOffset - y); x <= (rightOffset - y); x++)
		{
//			if (this->scf->getChar(h_pos + x, v_pos - y) == ' ') //		DEBUG
			{
				if (x == -(leftOffset - y) || x == (rightOffset - y))
					this->scf->setChar(h_pos + x, v_pos - y, 'o');
				else
					this->scf->setChar(h_pos + x, v_pos - y, '@');
			}
		}
	}
}
void	Shrub::branchLeft(int h_pos, int v_pos, int size)
{
	int i;
	for (i = 0; i <= size; i++)
	{
		this->scf->setChar(h_pos - i, v_pos - i, '\\');
	}

	this->growBush(h_pos - i, v_pos - i, 1 + (i / 3));
}
void	Shrub::branchRight(int h_pos, int v_pos, int size)
{
	int i;
	for (i = 0; i <= size; i++)
	{
		this->scf->setChar(h_pos + i, v_pos - i, '/');
	}

	this->growBush(h_pos + i, v_pos - i, 1 + (i / 4));
}