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
		virtual void makeSound(void) const = 0; //		= 0 makes the class abstract (cannot be instantiated)
		std::string	getType(void) const;
};

#endif //ANIMAL