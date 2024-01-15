#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate( void )
{
	srand(time(NULL));
	int i = rand() % 3;

	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify( Base *p )
{
	if (dynamic_cast< A* >( p ))
		std::cout << "A" << std::endl;
	else if (dynamic_cast< B* >( p ))
		std::cout << "B" << std::endl;
	else if (dynamic_cast< C* >( p) )
		std::cout << "C" << std::endl;
}

void identify ( Base &p )
{
	try
	{
		A &a = dynamic_cast< A& >( p );
		std::cout << "A" << std::endl;
		(void) a;
	}
	catch ( std::exception &e ) {}

	try
	{
		B &b = dynamic_cast< B& >( p );
		std::cout << "B" << std::endl;
		(void) b;
	}
	catch ( std::exception &e ) {}

	try
	{
		C &c = dynamic_cast< C& >( p );
		std::cout << "C" << std::endl;
		(void) c;
	}
	catch ( std::exception &e ) {}

}



int	main(void)
{
	std::cout << "\n1 O================================================================O\n"  << std::endl;
	{
		Base *base = generate();

		std::cout << "Identify from pointer : ";
		identify(base);

		std::cout << "Identify from reference : ";
		identify(*base);

		delete base;

	}
	std::cout << "\nE O================================================================O\n" << std::endl;
}