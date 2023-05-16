#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	//tests zombieHorde()

	int N = 5;

	std::cout << "[ zombieHorde() ]" << std::endl << std::endl;

	Zombie *horde = zombieHorde(N, "Quinn Quintuple");

	std::cout << std::endl;

	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << std::endl;

	delete[] horde;

	std::cout << std::endl;
}