#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	std::cout << std::endl;

	Fixed b(a);
	std::cout << std::endl;

	Fixed c;
	c = b;
	std::cout << std::endl << std::endl;

	std::cout << "value A : " << a.getRawBits() << std::endl;
	std::cout << "value B : " << b.getRawBits() << std::endl;
	std::cout << "value C : " << c.getRawBits() << std::endl << std::endl;
}