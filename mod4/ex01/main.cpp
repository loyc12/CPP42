#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int	main(void)
{
	std::cout << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		WrongAnimal beingFromTheDeepBellow;

		std::cout << std::endl << std::endl;

		beingFromTheDeepBellow.makeSound();

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		WrongCat mittens;

		std::cout << std::endl << std::endl;

		mittens.makeSound();

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Animal beingFromTheDeepBellow;

		std::cout << std::endl << std::endl;

		beingFromTheDeepBellow.makeSound();

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Cat princess;

		std::cout << std::endl << std::endl;

		princess.makeSound();

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Dog peanut;

		std::cout << std::endl << std::endl;

		peanut.makeSound();

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Dog peanut;

		std::cout << std::endl;
		{
			Dog butter;

			butter.addIdea("I wanna be friends with everyone");

			std::cout << std::endl << std::endl << "> butter : '" << butter.getIdea(0) << "'" << std::endl << std::endl;

			peanut = butter;

			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl << "> peanut : '" << peanut.getIdea(0) << "'" << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Cat blanche;

		std::cout << std::endl;
		{
			Cat neige;

			neige.addIdea("I wanna throw this off the table");

			std::cout << std::endl << std::endl << "> neige : '" << neige.getIdea(0) << "'" << std::endl << std::endl;

			blanche = neige;

			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl << "> blanche : '" << blanche.getIdea(0) << "'" << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "O================================================================O";
	{
		std::cout << std::endl << std::endl;

		const Animal* j = new Dog();
		std::cout << std::endl;
		const Animal* i = new Cat();
		std::cout << std::endl << std::endl;
		delete j;//should not create a leak
		std::cout << std::endl;
		delete i;
	}
	std::cout << std::endl << std::endl << "O================================================================O" << std::endl << std::endl;
}