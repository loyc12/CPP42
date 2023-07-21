#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructors / Destructor
		Dog();
		Dog(const Dog &other);
		Dog &operator= (const Dog &other);
		~Dog();

		// Others
		void makeSound(void) const;
};

#endif //DOG