#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Constructors / Destructor
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap &other);
		FragTrap &operator= (const FragTrap &other);
		~FragTrap();

		// Others
		void attack(const std::string& target);

		void hiFiveGuys();
};

#endif // FRAGTRAP