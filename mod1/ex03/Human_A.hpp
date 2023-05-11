#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>

# include "Weapon.hpp"

class	Human_A
{
	private:
		std::string name;
		Weapon &weapon;

	public:
		Human_A(std::string name_, Weapon &weapon_);
		~Human_A();

		void attack() const;
};

#endif //HUMAN_A_HPP