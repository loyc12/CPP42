#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	//tests zombieHorde()

	int N = 5;

	std::cout << " - Testing zombieHorde() :" << std::endl;

	Zombie *horde = zombieHorde(N, "Quinn Quintuple");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde;

	std::cout << std::endl;
}