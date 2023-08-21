#ifndef SHRUB_HPP
# define SHRUB_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"

class ShruberryCreationForm;

class Shrub
{
	private:
		ShruberryCreationForm f;
		int	horizontal_p;
		int	trunk_h;
		int	trunk_w;
		int	root_s;
		int	bush_s;

	protected:
		// Constructors
		Shrub();

	public:
		// Constructors - Destructor
		Shrub(const int pos);
		Shrub(const Shrub &other);
		Shrub &operator= (const Shrub &other);
		~Shrub();

		// Setters - Getters

		// Others
};

std::ostream &operator<< (std::ostream &out, const Shrub &rhs);

#endif //SHRUB