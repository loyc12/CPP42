#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define BRAIN_SIZE 100

class Brain
{
	protected:
		std::string	ideas[BRAIN_SIZE];

	public:
		// Constructors / Destructor
		Brain();
		Brain(const Brain &other);
		Brain &operator= (const Brain &other);
		~Brain();

		// Others
		void makeSound(void);
};

#endif //BRAIN