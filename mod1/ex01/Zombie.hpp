#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void setName(std::string name);
		std::string getName() const;
		void announce() const;
};

Zombie *zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP