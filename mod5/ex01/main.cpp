#include "Bureaucrat.hpp"


int	main(void)
{
	std::cout << "1 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Gravy", 2);
		std::cout << std::endl;

		b.promote();

		try
		{
			b.promote();
		}
		catch (const char *msg)
		{
			std::cerr << "Error : " << msg << std::endl;
		}
		std::cout << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "2 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Timmy", 149);
		std::cout << std::endl;

		b.demote();

		try
		{
			b.demote();
		}
		catch (const char *msg)
		{
			std::cerr << "Error : " << msg << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "3 O================================================================O" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat b("Timmy", 1234);
		}
		catch (const char *msg)
		{
			std::cerr << "Error : " << msg << std::endl;
		}
	}
	std::cout << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b1("Gravy", 1);
		std::cout << std::endl;

		try
		{
			b1.promote();
		}
		catch (const char *msg)
		{
			std::cerr << "Error : " << msg << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Bureaucrat b2(b1);
			b1.demote();
			b2 = b1;
			b1.demote();
		}
		catch (const char *msg)
		{
			std::cerr << "Error : " << msg << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "5 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Timmy", 2);
		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
		{
			try
			{
				b.promote();
			}
			catch (const char *msg)
			{
				std::cerr << "Error : " << msg << std::endl;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "E O================================================================O" << std::endl << std::endl;
}