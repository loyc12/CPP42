#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructors / Destructor
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator= (const WrongCat &other);
		~WrongCat();

		// Others
		void makeSound(void) const;
};

#endif //WRONGCAT