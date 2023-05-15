#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string name_, Weapon &weapon_);
		~HumanA();

		void attack() const;
};

#endif //HUMANA_HPP