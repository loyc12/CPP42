#ifndef SHRUB_HPP
# define SHRUB_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"

class ShrubberyCreationForm;

class Shrub
{
	private:
		ShrubberyCreationForm *scf;
		int	horizontal_p;
		int vertical_p;
		int	trunk_h;
//		int	trunk_w;
//		int	root_s;
//		int	bush_s;

	protected:
		// Constructors
		Shrub();

	public:
		// Constructors - Destructor
		Shrub(ShrubberyCreationForm *_scf, int _h_pos, int _v_pos);
		Shrub(const Shrub &other);
		Shrub &operator= (const Shrub &other);
		~Shrub();

		// Others
		int	getHPos(void) const;
		int	getVPos(void) const;

		// Shrubbing
		void	growShrub(void);
};

std::ostream &operator<< (std::ostream &out, const Shrub &rhs);

#endif //SHRUB