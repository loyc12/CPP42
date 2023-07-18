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
	std::cout << std::endl << std::endl << "O================================================================O" << std::endl << std::endl;
}