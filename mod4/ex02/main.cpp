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
	/*std::cout << std::endl << "7 O================================================================O" << std::endl << std::endl;
	{
		std::cout << std::endl << std::endl; //						ABSTRACT CLASS CAN'T BE INSTANTIATED

		Animal *beingFromTheDeepBellow = new Animal();

		std::cout << std::endl << std::endl;

		beingFromTheDeepBellow->makeSound();

		std::cout << std::endl;

		delete beingFromTheDeepBellow;
	}*/
	std::cout << std::endl << std::endl << "8 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Animal *princess = new Cat();

		std::cout << std::endl << std::endl;

		princess->makeSound();

		std::cout << std::endl;

		delete princess;
	}
	std::cout << std::endl << std::endl << "9 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Animal *peanut = new Dog();

		std::cout << std::endl << std::endl;

		peanut->makeSound();

		std::cout << std::endl;

		delete peanut;
	}
	std::cout << std::endl << "10 O================================================================O";
	{
	//	std::cout << std::endl << std::endl;
	//	const Animal* meta = new Animal(); //						ABSTRACT CLASS CAN'T BE INSTANTIATED

		std::cout << std::endl << std::endl;
		const Animal* j = new Dog();

		std::cout << std::endl;
		const Animal* i = new Cat();

		std::cout << std::endl << std::endl;
	//	std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl << std::endl;

	//	meta->makeSound();
		i->makeSound(); //		will output the cat sound!
		j->makeSound();

	//	std::cout << std::endl;
	//	delete meta;

		std::cout << std::endl;
		delete i;

		std::cout << std::endl;
		delete j;

		std::cout << std::endl;
	}
	std::cout << std::endl << "11 O================================================================O" << std::endl << std::endl;
}