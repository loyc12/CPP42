#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define BRAIN_SIZE 100

class Brain
{
	protected:
		std::string	ideas[BRAIN_SIZE];
		int	ideaCount;

	public:
		// Constructors / Destructor
		Brain();
		Brain(const Brain &other);
		Brain &operator= (const Brain &other);
		~Brain();

		// Others
		void addIdea(std::string idea);
		std::string	getIdea(int index);
};

#endif //BRAIN