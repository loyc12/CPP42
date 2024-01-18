#include "Template.hpp"

void runTests( void )
{
	std::cout << "\nO================================ TEST 1 ================================O\n"  << std::endl;
	{
		Template	*test = new Template();

		test->setName("test 1");

		std::cout << "\n" << *test << "\n" << std::endl;

		delete test;
	}
	std::cout << "\nO================================ TEST 2 ================================O\n"  << std::endl;
	{
		Template	*test = new Template("test 2");

		std::cout << "\n" << *test << "\n" << std::endl;

		delete test;
	}
	std::cout << "\nO================================= END ==================================O\n\n" << std::endl;
}


int	main( void )
{
	runTests();
}