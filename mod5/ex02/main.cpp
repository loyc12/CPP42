#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "1 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Gravy", 1);
		std::cout << std::endl;

		Form f("Artillery only", 2, 1);
		std::cout << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl << " > " << f << std::endl << std::endl;
	}
	std::cout << std::endl << "2 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Timmy", 2);
		std::cout << std::endl;

		Form f("Megacampaign", 2, 1);
		std::cout << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl << " > " << f << std::endl << std::endl;
	}
	std::cout << std::endl << "3 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Baby", 3);
		std::cout << std::endl;

		Form f("Ck3 A to Z", 2, 1);
		std::cout << std::endl;

		try
		{
			b.signForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl << " > " << f << std::endl << std::endl;
	}
	std::cout << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		try
		{
			Form f("All achievements", 1234, 1);
			std::cout << std::endl << " > " << f << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

	}
	std::cout << std::endl << "5 O================================================================O" << std::endl << std::endl;
	{
		Form f1("A", 2, 1);
		std::cout << std::endl;

		try
		{
			Form f2("Z", 4, 3);
			f2 = f1;
			std::cout << std::endl << " > " << f2 << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "6 O================================================================O" << std::endl << std::endl;
	{
		Form f1("Tank only", 2, 1);
		std::cout << std::endl;

		try
		{
			Form f2(f1);
			std::cout << std::endl << " > " << f2 << std::endl << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "E O================================================================O" << std::endl << std::endl;
}