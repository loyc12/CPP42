#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>

# include "Weapon.hpp"

class	Human_B
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		Human_B(std::string name_);
		~Human_B();

		void setWeapon(Weapon *weapon_);
		void attack() const;
};

#endif //HUMAN_B_HPP