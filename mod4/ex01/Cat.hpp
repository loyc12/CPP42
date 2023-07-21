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
		void makeSound(void) const;
		void addIdea(std::string idea);
		std::string getIdea(int index);
};

#endif //CAT