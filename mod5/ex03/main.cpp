#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <unistd.h>

int	main(void)
{
	Bureaucrat b("Overseer", 1);

	std::cout << std::endl << std::endl << "1 O================================================================O" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		form = i.makeForm("shrubbery creation", "Forest");
		std::cout << std::endl;

		b.signForm(*form);
		std::cout << std::endl;

		b.executeForm(*form);
		std::cout << std::endl;

		std::cout << " > " << i << std::endl << " > " << *form << std::endl << std::endl;

		delete form;
	}
	sleep(1);
	std::cout << std::endl << std::endl << "2 O================================================================O" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		form = i.makeForm("presidential pardon", "Zap");
		std::cout << std::endl;

		b.signForm(*form);
		std::cout << std::endl;

		b.executeForm(*form);
		std::cout << std::endl;

		std::cout << " > " << i << std::endl << " > " << *form << std::endl << std::endl;

		delete form;
	}
	sleep(1);
	std::cout << std::endl << std::endl << "3 O================================================================O" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		form = i.makeForm("robotomy request", "Bender");
		std::cout << std::endl;

		b.signForm(*form);
		std::cout << std::endl;

		b.executeForm(*form);
		std::cout << std::endl;

		std::cout << " > " << i << std::endl << " > " << *form << std::endl << std::endl;

		delete form;
	}
	sleep(1);
	std::cout << std::endl << std::endl << "4 O================================================================O" << std::endl << std::endl;
	{
		Intern	i;
		std::cout << std::endl;

		AForm	*form;
		std::cout << std::endl;

		try
		{
			form = i.makeForm("dance sentence", "Spider");
			std::cout << std::endl;

			b.signForm(*form);
			std::cout << std::endl;

			b.executeForm(*form);
			std::cout << std::endl;

			delete form;
		}
		catch (std::exception &e)
		{
			std::cerr << "Error : " << e.what() << std::endl;
		}

		std::cout << " > " << i << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << "E O================================================================O" << std::endl << std::endl;
}