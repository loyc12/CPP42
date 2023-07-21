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
		void makeSound(void) const;
		void addIdea(std::string idea);
		std::string getIdea(int index);
};

#endif //DOG