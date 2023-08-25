#include "Shrub.hpp"

// Constructors - Destructor

Shrub::Shrub()
{
//	std::cout << ": Called default constructor (SHRUB) ";
}
Shrub::Shrub(ShrubberyCreationForm *_scf, int _h_pos, int _v_pos)
{
//	std::cout << ": Called parameterized constructor (SHRUB) ";

	this->scf = _scf;
	this->horizontal_p = _h_pos;
	this->vertical_p = _v_pos;

//	std::cout << ": Constructed " << this->name << " ( bureaucrat grade " << this->grade << " )" << std::endl; //	DEBUG
}
Shrub::Shrub(const Shrub &other)
{
//	std::cout << ": Called copy constructor (SHRUB) ";

	this->horizontal_p = other.horizontal_p;
	this->scf = other.scf;

//	std::cout << ": Copy-constructed " << this->name << " ( bureaucrat grade " << this->grade << " )" << std::endl; //	DEBUG
}
Shrub &Shrub::operator= (const Shrub &other)
{
//	std::cout << ": Called assignment operator (SHRUB) ";

	this->horizontal_p = other.horizontal_p;
	this->scf = other.scf;

//	std::cout << ": Copied " << this->name << " ( bureaucrat grade " << this->grade << " )" << std::endl; //	DEBUG

	return *this;
}
Shrub::~Shrub()
{
//	std::cout << ": Called Destructor (SHRUB) ";
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
	this->trunk_h = 2 + (rand() % 16);
	this->trunk_w = 1 + (trunk_h / 5);

	if (!(rand() % 6))
		this->type = 1;
	else if (!(rand() % 6))
		this->type = -1;
	else
		this->type = 0;

//	this->type = 1; //				DEBUG

	int i;
	int	leftOffset = ((this->trunk_w + 0) / 2);
	int	rightOffset = ((this->trunk_w + 1) / 2);
	int	branchLeftH = this->getHPos() - leftOffset - 1;
	int	branchrightH = this->getHPos() + rightOffset + 1;

	if (this->type == 1)
	{
		this->growBush(this->getHPos(), this->getVPos(), this->trunk_w);
		return ;
	}
	if (this->type == -1)
		this->trunk_h = (this->trunk_h / 2) + (rand() % this->trunk_w);

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
				this->scf->setChar(this->getHPos() + j, this->getVPos() - i, '~');
		}
		else
		{
			this->scf->setChar(this->getHPos() - leftOffset, this->getVPos() - i, '|');
			this->scf->setChar(this->getHPos() + rightOffset, this->getVPos() - i, '|');
			for (int j = -(leftOffset - 1); j <= rightOffset - 1; j++)
				this->scf->setChar(this->getHPos() + j, this->getVPos() - i, this->scf->getBarkChar());
		}
		if (i > 1 && (i < this->trunk_h - 2 || this->type == -1))
		{
			if (!(rand() % 8) && this->scf->getChar(branchLeftH, branchV + 1) != '\\')
				this->branchLeft(branchLeftH, branchV, 1 + (rand() % this->trunk_w));

			if (!(rand() % 8) && this->scf->getChar(branchrightH, branchV + 1) != '/')
				this->branchRight(branchrightH, branchV, 1 + (rand() % this->trunk_w));
		}
	}
	for (int j = -(leftOffset + 1); j <= (rightOffset + 1); j++)
		this->growRoot(this->getHPos() + j, this->getVPos() + 1, 1 + (this->trunk_h / 4) + (rand() % 8));

	if (this->type != -1)
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
				{
					if (this->scf->getChar(h_pos + x, v_pos - y + 1) != ' '
						|| this->scf->getChar(h_pos + x + 1, v_pos - y) != ' '
						|| this->scf->getChar(h_pos + x - 1, v_pos - y) != ' ')
					{
						this->scf->setChar(h_pos + x, v_pos - y, BUSH_CHAR);
					}
				}
				else
					this->scf->setChar(h_pos + x, v_pos - y, this->scf->getLeafChar());
			}
		}
	}
}
void	Shrub::growRoot(int h_pos, int v_pos, int size)
{
	int x = 0;

	for (int y = 0; y < size; y++)
	{
//		if (this->scf->getChar(h_pos + x, v_pos + y) == 'GROUND_CHAR') //	old
		if  (rand() % 3)
			this->scf->setChar(h_pos + x, v_pos + y, ROOT_CHAR);
		else
			this->scf->setChar(h_pos + x, v_pos + y, GROUND_CHAR);

		x += (rand() % 5) - 2;
	}
}

void	Shrub::branchLeft(int h_pos, int v_pos, int size)
{
	int i;

	for (i = 0; i <= size; i++)
	{
		this->scf->setChar(h_pos - i, v_pos - i, '\\');
		if (i > 0 && size > 2)
			this->scf->setChar(h_pos - i + 1, v_pos - i, '\\');
	}
	if (this->type != -1)
		this->growBush(h_pos - i, v_pos - i, 1 + (size / 2));
}
void	Shrub::branchRight(int h_pos, int v_pos, int size)
{
	int i;

	for (i = 0; i <= size; i++)
	{
		this->scf->setChar(h_pos + i, v_pos - i, '/');
		if (i > 0 && size > 2)
			this->scf->setChar(h_pos + i - 1, v_pos - i, '/');
	}
	if (this->type != -1)
		this->growBush(h_pos + i, v_pos - i, 1 + (size / 2));
}