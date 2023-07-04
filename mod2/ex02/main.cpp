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

	const Fixed d = Fixed(69.18254643f);
	std::cout << std::endl;

	const Fixed e(a);
	std::cout << std::endl;

	const Fixed f = b;
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
	std::cout << "c D : " << d << std::endl;
	std::cout << "c E : " << e << std::endl;
	std::cout << "c F : " << f << std::endl << std::endl;


	std::cout << "0======== TESTING ARITHMETICS ========0" << std::endl << std::endl;

	std::cout << "  B : " << b << std::endl;
	std::cout << "  C : " << c << std::endl << std::endl;

	std::cout << "  B + C : " << (b + c) << std::endl;
	std::cout << "  B - C : " << (b - c) << std::endl;
	std::cout << "  B * C : " << (b * c) << std::endl;
	std::cout << "  B / C : " << (b / c) << std::endl << std::endl;

	b += c;
	std::cout << "  B += C : " << b << std::endl;
	b -= c;
	std::cout << "  B -= C : " << b << std::endl;
	b *= c;
	std::cout << "  B *= C : " << b << std::endl;
	b /= c;
	std::cout << "  B /= C : " << b << std::endl << std::endl;


	std::cout << "0======== TESTING COMPARISONS ========0" << std::endl << std::endl;

	std::cout << "c D : " << d << std::endl;
	std::cout << "c E : " << e << std::endl << std::endl;

	std::cout << "  D != E : " << (d != e) << std::endl;
	std::cout << "  D > E  : " << (d > e) << std::endl;
	std::cout << "  D >= E : " << (d >= e) << std::endl;
	std::cout << "  D == E : " << (d == e) << std::endl;
	std::cout << "  D <= E : " << (d <= e) << std::endl;
	std::cout << "  D < E  : " << (d < e) << std::endl << std::endl;


	std::cout << "0======== TESTING INCREMENTATIONS ========0" << std::endl << std::endl;

	std::cout << "  A   : " << a << std::endl << std::endl;

	std::cout << "  ++A : " << ++a << std::endl << std::endl;
	std::cout << "  A   : " << a << std::endl;

	std::cout << "  --A : " << --a << std::endl << std::endl;
	std::cout << "  A   : " << a << std::endl;

	std::cout << "  A++ : " << a++ << std::endl << std::endl;
	std::cout << "  A   : " << a << std::endl;

	std::cout << "  A-- : " << a-- << std::endl << std::endl;
	std::cout << "  A   : " << a << std::endl << std::endl;

	std::cout << "0======== TESTING MIN/MAX ========0" << std::endl << std::endl;

	std::cout << "  A : " << a << std::endl;
	std::cout << "  B : " << b << std::endl;
	std::cout << "  C : " << c << std::endl;
	std::cout << "c D : " << d << std::endl;
	std::cout << "c E : " << e << std::endl;
	std::cout << "c F : " << f << std::endl << std::endl;

	std::cout << "  MIN (A, B) : " << Fixed::min(a, b) << std::endl;
	std::cout << "  MIN (B, C) : " << Fixed::min(b, c) << std::endl;
	std::cout << "c MIN (C, D) : " << Fixed::min(c, d) << std::endl;
	std::cout << "c MIN (D, E) : " << Fixed::min(d, e) << std::endl;
	std::cout << "c MIN (E, F) : " << Fixed::min(e, f) << std::endl;
	std::cout << "c MIN (F, F) : " << Fixed::min(f, f) << std::endl << std::endl;

	std::cout << "  MAX (A, B) : " << Fixed::max(a, b) << std::endl;
	std::cout << "  MAX (B, C) : " << Fixed::max(b, c) << std::endl;
	std::cout << "c MAX (C, D) : " << Fixed::max(c, d) << std::endl;
	std::cout << "c MAX (D, E) : " << Fixed::max(d, e) << std::endl;
	std::cout << "c MAX (E, F) : " << Fixed::max(e, f) << std::endl;
	std::cout << "  MAX (A, A) : " << Fixed::max(a, a) << std::endl << std::endl;

}
