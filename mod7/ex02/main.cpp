#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10
/*
int intTester()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */
void intTester()
{
    Array numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	std::cout << "\nArray : " << numbers << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 256;
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << "Array : " << numbers << std::endl << std::endl;

    //SCOPE
    {
        Array tmp = numbers;
        Array test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "\ndidn't save the same value!!" << std::endl;
            return;
        }
    }

    try {
		std::cout << "\nTrying to access index MIN_VAL - 1" << std::endl;
        int value = numbers[-MAX_VAL - 1];
		std::cout << "Value : " << value << std::endl;
		numbers[-MAX_VAL - 1] = value;
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    try {
		std::cout << "\nTrying to access index MIN_VAL" << std::endl;
        int value = numbers[-MAX_VAL];
		std::cout << "Value : " << value << std::endl;
		numbers[-MAX_VAL] = value;
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	try {
		std::cout << "\nTrying to access index -1" << std::endl;
        int value = numbers[-1];
		std::cout << "Value : " << value << std::endl;
		numbers[-1] = value;
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    try {
		std::cout << "\nTrying to access index 0" << std::endl;
        int value = numbers[0];
		std::cout << "Value : " << value << std::endl;
		numbers[0] = value;
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    try {
		std::cout << "\nTrying to access index MAX_VAL - 1" << std::endl;
        int value = numbers[MAX_VAL - 1];
		std::cout << "Value : " << value << std::endl;
		numbers[MAX_VAL - 1] = value;
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

    try {
		std::cout << "\nTrying to access index MAX_VAL" << std::endl;
        int value = numbers[MAX_VAL];
		std::cout << "Value : " << value << std::endl;
		numbers[MAX_VAL] = value;
    } catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

	std::cout << "\nTrying to reassign values forwards" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) { numbers[i] = rand() % 256; }
	std::cout << "Array : " << numbers << std::endl;


	std::cout << "\nTrying to reassign values backwards" << std::endl;
    for (int i = 0; i > -MAX_VAL; --i) { numbers[i] = rand() % 256; }
	std::cout << "Array : " << numbers << std::endl;

    delete [] mirror;

	std::cout << std::endl;
}

void runTests( void )
{
	std::cout << "\nO================================ TEST 1 ================================O\n"  << std::endl;
	{

	}
	std::cout << "\nO================================ TEST 2 ================================O\n"  << std::endl;
	{

	}
	std::cout << "\nO================================= END ==================================O\n\n" << std::endl;
}

int	main( void )
{
	//runTests();
	intTester();
	//TemplateTester();
}