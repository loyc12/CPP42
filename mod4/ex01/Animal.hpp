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
		virtual ~Animal(); //						VIRTUAL keywords forces destructin to use child's destructor

		// Others
		void makeSound(void);
};

#endif //ANIMAL