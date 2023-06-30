#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c = b;


	std::cout << "value A : " << a.getRawBits() << std::endl;
	std::cout << "value B : " << b.getRawBits() << std::endl;
	std::cout << "value C : " << c.getRawBits() << std::endl;
}