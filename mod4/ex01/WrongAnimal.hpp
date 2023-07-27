#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		// Constructors / Destructor
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator= (const WrongAnimal &other);
		~WrongAnimal();

		// Others
		void makeSound(void) const;
		std::string	getType(void) const;
};

#endif //WRONGANIMAL