#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>

# include "Weapon.hpp"

class	Human_A
{
	private:
		Weapon weapon;
		std::string	name;

	public:
		Human_A();
		Human_A(std::string name, Weapon weapon);
		~Human_A();

		void attack();
};

#endif //HUMAN_A_HPP