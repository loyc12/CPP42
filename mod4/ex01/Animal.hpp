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
		virtual ~Animal();

		// Others
		virtual void makeSound(void) const;
		std::string	getType(void) const;
};

#endif //ANIMAL