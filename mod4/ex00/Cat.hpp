#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructors / Destructor
		Cat();
		Cat(const Cat &other);
		Cat &operator= (const Cat &other);
		~Cat();

		// Others
		void makeSound(void) const;
};

#endif //CAT