#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	std::cout << "1 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Cat blanche;

		std::cout << std::endl;
		{
			Cat neige;
			neige.addIdea("I wanna throw this off the table");

			std::cout << std::endl << std::endl << "> neige : '" << neige.getIdea(0) << "'" << std::endl << std::endl;

			blanche = neige; //						either this leaks
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl << "> blanche : '" << blanche.getIdea(0) << "'" << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "2 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Cat blanche;
		blanche.addIdea("I wanna throw this off the table");

		std::cout << std::endl;
		{
			Cat neige(blanche);
			std::cout << std::endl << std::endl << "> neige : '" << neige.getIdea(0) << "'" << std::endl << std::endl;

//			Cat caramel = blanche; //				or this segfaults
//			std::cout << "> caramel : '" << caramel.getIdea(0) << "'" << std::endl << std::endl;
		}
		std::cout << std::endl << std::endl << "> blanche : '" << blanche.getIdea(0) << "'" << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "3 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Dog peanut;

		std::cout << std::endl;
		{
			Dog butter;
			butter.addIdea("Is this a CROSSOVER episode !");

			std::cout << std::endl << std::endl << "> butter : '" << butter.getIdea(0) << "'" << std::endl << std::endl;

			peanut = butter; //						either this leaks
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl << "> peanut : '" << peanut.getIdea(0) << "'" << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "4 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Dog peanut;
		peanut.addIdea("Is this a CROSSOVER episode !");

		std::cout << std::endl;
		{
			Dog butter(peanut);
			std::cout << std::endl << std::endl << "> butter : '" << butter.getIdea(0) << "'" << std::endl << std::endl;

//			Dog bean = peanut;; //					or this segfaults
//			std::cout << "> bean : '" << bean.getIdea(0) << "'" << std::endl << std::endl;
		}
		std::cout << std::endl << std::endl << "> peanut : '" << peanut.getIdea(0) << "'" << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "5 O================================================================O";
	{
		std::cout << std::endl << std::endl;
		const Animal* sally = new Dog();

		std::cout << std::endl;
		const Animal* hop = new Cat();

		std::cout << std::endl << std::endl;
		delete sally; //	should not create a leak

		std::cout << std::endl;
		delete hop; //	should not create a leak
	}
	std::cout << std::endl << std::endl << "6 O================================================================O";
	{
		std::cout << std::endl;
		const Animal *Manymals[6];

		std::cout << std::endl;
		for (int i = 0; i < 6; i++)
		{
			if (i % 2)
				Manymals[i] = new Cat;
			else
				Manymals[i] = new Dog;
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < 6; i++)
		{
			delete Manymals[i];
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << "7 O================================================================O" << std::endl << std::endl;
}

/*

fix segfault due to uninitialized values when passing through wrong constructor for brain

*/