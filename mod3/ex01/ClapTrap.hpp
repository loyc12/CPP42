#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		int HP;
		int EP;
		int AD;

	public:
		// Constructors / Destructor
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator= (const ClapTrap &other);
		~ClapTrap();

		// Others
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		bool canAct(void);
		bool showStats(void);
};

#endif // CLAPTRAP