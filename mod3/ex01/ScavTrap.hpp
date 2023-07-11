#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap : public ClapTrap
{
	private:
		int HP;
		int EP;
		int AD;
		string	Name;

	public:
		// Constructors / Destructor
		ScavTrap(string _name);
		ScavTrap(const ClapTrap &other);
		ScavTrap &operator= (const ClapTrap &other);
		~ScavTrap();

		// Others

};

#endif // SCAVTRAP