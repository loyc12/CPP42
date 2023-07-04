#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	a.setRawBits(42 * a.getFracBit());
	std::cout << std::endl;

	Fixed b(120);
	std::cout << std::endl;

	Fixed c(35.645215346f);
	std::cout << std::endl;

	Fixed d;
	d = Fixed(69.18254643f);
	std::cout << std::endl;

	Fixed e(a);
	std::cout << std::endl;

	Fixed f;
	f = b;
	std::cout << std::endl << std::endl;

	std::cout << "  fractional bit number (precision) : " << a.getFracBit() << std::endl << std::endl;

	std::cout << "0======== TESTING VALUES ========0" << std::endl << std::endl;

	std::cout << "  int value of A : " << a.toInt() << std::endl;
	std::cout << "  int value of B : " << b.toInt() << std::endl;
	std::cout << "  int value of C : " << c.toInt() << std::endl;
	std::cout << "  int value of D : " << d.toInt() << std::endl;
	std::cout << "  int value of E : " << e.toInt() << std::endl;
	std::cout << "  int value of F : " << f.toInt() << std::endl << std::endl;

	std::cout << "  float value of A : " << a.toFloat() << std::endl;
	std::cout << "  float value of B : " << b.toFloat() << std::endl;
	std::cout << "  float value of C : " << c.toFloat() << std::endl;
	std::cout << "  float value of D : " << d.toFloat() << std::endl;
	std::cout << "  float value of E : " << e.toFloat() << std::endl;
	std::cout << "  float value of F : " << f.toFloat() << std::endl << std::endl;

	std::cout << "0======== TESTING '<<' ========0" << std::endl << std::endl;

	std::cout << "  A : " << a << std::endl;
	std::cout << "  B : " << b << std::endl;
	std::cout << "  C : " << c << std::endl;
	std::cout << "  D : " << d << std::endl;
	std::cout << "  E : " << e << std::endl;
	std::cout << "  F : " << f << std::endl << std::endl;



	std::cout << "0======== TESTING ARITHMETICS ========0" << std::endl << std::endl;

	std::cout << "  B : " << b << std::endl;
	std::cout << "  C : " << c << std::endl << std::endl;

	std::cout << "  B + C : " << (b + c) << std::endl;
	std::cout << "  B - C : " << (b - c) << std::endl;
	std::cout << "  B * C : " << (b * c) << std::endl;
	std::cout << "  B / C : " << (b / c) << std::endl<< std::endl;

	b += c;
	std::cout << "  B += C : " << b << std::endl;
	b -= c;
	std::cout << "  B -= C : " << b << std::endl;
	b *= c;
	std::cout << "  B *= C : " << b << std::endl;
	b /= c;
	std::cout << "  B /= C : " << b << std::endl << std::endl;



	std::cout << "0======== TESTING COMPARISONS ========0" << std::endl << std::endl;

	std::cout << "  D : " << d << std::endl;
	std::cout << "  E : " << e << std::endl << std::endl;

	std::cout << "  D != E : " << (d != e) << std::endl;
	std::cout << "  D > E  : " << (d > e) << std::endl;
	std::cout << "  D >= E : " << (d >= e) << std::endl;
	std::cout << "  D == E : " << (d == e) << std::endl;
	std::cout << "  D <= E : " << (d <= e) << std::endl;
	std::cout << "  D < E  : " << (d < e) << std::endl<< std::endl;

	std::cout << "0======== TESTING INCREMENTATIONS ========0" << std::endl << std::endl;

	std::cout << "  F   : " << f << std::endl;
	std::cout << "  F++ : " << f++ << std::endl << std::endl;

	std::cout << "  F   : " << f << std::endl;
	std::cout << "  ++F : " << ++f << std::endl << std::endl;

	std::cout << "  F   : " << f << std::endl;
	std::cout << "  F-- : " << f-- << std::endl << std::endl;

	std::cout << "  F   : " << f << std::endl;
	std::cout << "  --F : " << --f << std::endl << std::endl;

	std::cout << "  F   : " << f << std::endl << std::endl;

}
