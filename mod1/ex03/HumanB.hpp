#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name_);
		~HumanB();

		void setWeapon(Weapon &weapon_);
		void attack() const;
};

#endif //HUMANB_HPP