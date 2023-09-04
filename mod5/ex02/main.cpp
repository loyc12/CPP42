#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int	main(void)
{
	std::cout << "1 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 1);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl << std::endl;

		b.signForm(f);
		std::cout << std::endl;

		b.executeForm(f);

		std::cout << std::endl << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "2 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 1);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl << std::endl;

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
		Bureaucrat b("Zap", 6);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl << std::endl;

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
	std::cout << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Zap", 26);
		std::cout << std::endl;

		PresidentialPardonForm f("Himself");
		std::cout << std::endl << std::endl;

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
	std::cout << std::endl << std::endl;
	std::cout << std::endl << "5 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Mom", 1);
		std::cout << std::endl;

		RobotomyRequestForm f("Bender");
		std::cout << std::endl << std::endl;

		b.signForm(f);
		std::cout << std::endl;

		b.executeForm(f);

		std::cout << std::endl << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "6 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Mom", 1);
		std::cout << std::endl;

		RobotomyRequestForm f("Delivery Express' ship");
		std::cout << std::endl << std::endl;

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
	std::cout << std::endl << "7 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Mom", 46);
		std::cout << std::endl;

		RobotomyRequestForm f("Robot Devil");
		std::cout << std::endl << std::endl;

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
	std::cout << std::endl << "8 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Mom", 73);
		std::cout << std::endl;

		RobotomyRequestForm f("Santa Claus");
		std::cout << std::endl << std::endl;

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
	std::cout << std::endl << std::endl;
	std::cout << std::endl << "9 O================================================================O" << std::endl << std::endl;
	{
		std::srand(std::time(NULL));

		Bureaucrat b("Gardener", 1);
		std::cout << std::endl;

		ShrubberyCreationForm f("Forest");
		std::cout << std::endl << std::endl;

		b.signForm(f);
		std::cout << std::endl;

		b.executeForm(f);

//		f.drawArea(); //		in writeArea() already

		std::cout << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	sleep(1);
	std::cout << std::endl << "10 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Gardener", 1);
		std::cout << std::endl;

		ShrubberyCreationForm f("Bog");
		std::cout << std::endl << std::endl;

		try
		{
			b.executeForm(f);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		f.drawArea();

		std::cout << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	sleep(1);
	std::cout << std::endl << "11 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Gardener", 138);
		std::cout << std::endl;

		ShrubberyCreationForm f("Park");
		std::cout << std::endl << std::endl;

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

		f.drawArea();

		std::cout << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	sleep(1);
	std::cout << std::endl << "12 O================================================================O" << std::endl << std::endl;
	{
		Bureaucrat b("Gardener", 146);
		std::cout << std::endl;

		ShrubberyCreationForm f("Garden");
		std::cout << std::endl << std::endl;

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

		f.drawArea();

		std::cout << " > " << f << std::endl << " > " << b << std::endl << std::endl;
	}
	std::cout << std::endl << "E O================================================================O" << std::endl << std::endl;
}