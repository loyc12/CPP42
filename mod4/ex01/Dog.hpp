#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		// Constructors / Destructor
		Dog();
		Dog(const Dog &other);
		Dog &operator= (const Dog &other);
		~Dog();

		// Others
		void makeSound(void);
};

#endif //DOG