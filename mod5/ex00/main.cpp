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
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		b.demote();

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
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		b.promote();

		std::cout << std::endl;
	}
	std::cout << std::endl << "3 O================================================================O" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat b("Timmy", 1234);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		try
		{
			Bureaucrat b("Timmy", 0);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "5 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b1("Gravy", 1);
		std::cout << std::endl;

		try
		{
			b1.promote();
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;

		try
		{
			Bureaucrat b2(b1);
			b1.demote();
			b2 = b1;
			b1.demote();
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "6 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Timmy", 3);
		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
		{
			try
			{
				b.promote();
			}
			catch (std::exception &e)
			{
				std::cerr << "Error : " << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "7 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Timmy", 148);
		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
		{
			try
			{
				b.demote();
			}
			catch (std::exception &e)
			{
				std::cerr << "Error : " << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "E O================================================================O" << std::endl << std::endl;
}