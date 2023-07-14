#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructors / Destructor
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator= (const ScavTrap &other);
		~ScavTrap();

		// Others
		void attack(const std::string& target);

		void guardGate();
};

#endif // SCAVTRAP