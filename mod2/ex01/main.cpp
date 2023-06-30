#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	a.setRawBits(42 * 8);

	Fixed b(42);

	Fixed c(42.5f);

	Fixed d = Fixed(42.25f);
	Fixed e(b);
	Fixed f = c;

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