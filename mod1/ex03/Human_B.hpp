#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>

# include "Weapon.hpp"

class	Human_B
{
	private:
		Weapon weapon;
		std::string	name;

	public:
		Human_B();
		Human_B(std::string name);
		~Human_B();

		void setWeapon(Weapon weapon);
		void attack();
};

#endif //HUMAN_B_HPP