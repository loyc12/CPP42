#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string	Name;
		int HP;
		int EP;
		int AD;

		bool canAct(void);

	public:
		// Constructors / Destructor
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator= (const ClapTrap &other);
		~ClapTrap();

		// Others
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		bool showStats(void);
};

#endif // CLAPTRAP