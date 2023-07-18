#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		// Constructors / Destructor
		Animal();
		Animal(const Animal &other);
		Animal &operator= (const Animal &other);
		virtual ~Animal() = 0;

		// Others
		virtual void makeSound(void) = 0;
};

#endif //ANIMAL