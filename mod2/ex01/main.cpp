#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	a.setRawBits(42 * 8);
	std::cout << std::endl;

	Fixed b(42);
	std::cout << std::endl;

	Fixed c(42.5f);
	std::cout << std::endl;

	Fixed d;
	d = Fixed(42.25f);
	std::cout << std::endl;

	Fixed e(b);
	std::cout << std::endl;

	Fixed f;
	f = c;
	std::cout << std::endl << std::endl;

	std::cout << "int value of A : " << a.toInt() << std::endl;
	std::cout << "int value of B : " << b.toInt() << std::endl;
	std::cout << "int value of C : " << c.toInt() << std::endl;
	std::cout << "int value of D : " << d.toInt() << std::endl;
	std::cout << "int value of E : " << e.toInt() << std::endl;
	std::cout << "int value of F : " << f.toInt() << std::endl << std::endl;

	std::cout << "float value of A : " << a.toFloat() << std::endl;
	std::cout << "float value of B : " << b.toFloat() << std::endl;
	std::cout << "float value of C : " << c.toFloat() << std::endl;
	std::cout << "float value of D : " << d.toFloat() << std::endl;
	std::cout << "float value of E : " << e.toFloat() << std::endl;
	std::cout << "float value of F : " << f.toFloat() << std::endl << std::endl;

	std::cout << "printing A : " << a << std::endl;
	std::cout << "printing B : " << b << std::endl;
	std::cout << "printing C : " << c << std::endl;
	std::cout << "printing D : " << d << std::endl;
	std::cout << "printing E : " << e << std::endl;
	std::cout << "printing F : " << f << std::endl << std::endl;

}