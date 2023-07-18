#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		// Constructors / Destructor
		Cat();
		Cat(const Cat &other);
		Cat &operator= (const Cat &other);
		~Cat();

		// Others
		void makeSound(void);
};

#endif //CAT