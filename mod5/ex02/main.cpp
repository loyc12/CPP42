#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "1 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 1);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl;

		b.signForm(f);
		std::cout << std::endl;

		b.executeForm(f);

		std::cout << std::endl << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "2 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 6);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl;

		b.signForm(f);
		std::cout << std::endl;

		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << std::endl << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "3 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 26);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << std::endl << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 1);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl;

		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << std::endl << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "E O================================================================O" << std::endl << std::endl;
}

/*

char[43][85], last ones column is \n, las row is \0

flood-fill constructor (wave function collapse)

.........................
.........................
.........................
.........................
.........................
.........@@@@@...........
.......@@@@@@@@@@........
......@@@@@@@@@@@@.......
......@@@@@@@@@@@@@......
......@@@@@@@@@@@@.......
.........\||.//@@........
.........|~|//...........
.........|~~/............
.........|~~|............
.........|~~|............
......../~~~~\...........


*/