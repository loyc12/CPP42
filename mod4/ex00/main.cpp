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

		WrongAnimal *beingFromTheDeepBellow = new WrongAnimal();

		std::cout << std::endl << std::endl;

		beingFromTheDeepBellow->makeSound();

		std::cout << std::endl;

		delete beingFromTheDeepBellow;
	}
	std::cout << std::endl << std::endl << "2 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		WrongAnimal *mittens = new WrongCat();

		std::cout << std::endl << std::endl;

		mittens->makeSound();

		std::cout << std::endl;

		delete mittens;
	}
	std::cout << std::endl << std::endl << "3 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Animal *beingFromTheDeepBellow = new Animal();

		std::cout << std::endl << std::endl;

		beingFromTheDeepBellow->makeSound();

		std::cout << std::endl;

		delete beingFromTheDeepBellow;
	}
	std::cout << std::endl << std::endl << "4 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Animal *princess = new Cat();

		std::cout << std::endl << std::endl;

		princess->makeSound();

		std::cout << std::endl;

		delete princess;
	}
	std::cout << std::endl << std::endl << "5 O================================================================O";
	{
		std::cout << std::endl << std::endl;

		Animal *peanut = new Dog();

		std::cout << std::endl << std::endl;

		peanut->makeSound();

		std::cout << std::endl;

		delete peanut;
	}
	std::cout << std::endl << std::endl << "6 O================================================================O";
	{
		std::cout << std::endl << std::endl;
		const Animal* meta = new Animal(); //						ABSTRACT CLASS CAN'T BE INSTANTIATED

		std::cout << std::endl;
		const Animal* j = new Dog();

		std::cout << std::endl;
		const Animal* i = new Cat();

		std::cout << std::endl << std::endl;
		std::cout << meta->getType() << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl << std::endl;

		meta->makeSound();
		i->makeSound(); //		will output the cat sound!
		j->makeSound();

		std::cout << std::endl;
		delete meta;

		std::cout << std::endl;
		delete i;

		std::cout << std::endl;
		delete j;
	}
	std::cout << std::endl << std::endl << "7 O================================================================O" << std::endl << std::endl;
}