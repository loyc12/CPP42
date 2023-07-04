#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _raw_value;
		static const int _frac_bit = 8;

	public:
		// Constructors / Destructor
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		// Operators
		Fixed &operator= (const Fixed &other);
			// Arithmetics
		Fixed operator+ (const Fixed &other) const;
		Fixed operator- (const Fixed &other) const;
		Fixed operator* (const Fixed &other) const;
		Fixed operator/ (const Fixed &other) const;
		Fixed &operator+= (const Fixed &other);
		Fixed &operator-= (const Fixed &other);
		Fixed &operator*= (const Fixed &other);
		Fixed &operator/= (const Fixed &other);
			// Comparisons
		bool operator!= (const Fixed &other) const;
		bool operator> (const Fixed &other) const;
		bool operator>= (const Fixed &other) const;
		bool operator== (const Fixed &other) const;
		bool operator<= (const Fixed &other) const;
		bool operator< (const Fixed &other) const;
			// Incrementations
		Fixed &operator++ ();
		Fixed &operator-- ();
		Fixed operator++ (int);
		Fixed operator-- (int);

		// Min/Max
		static Fixed &min(Fixed &fpn1, Fixed &fpn2);
		static Fixed &max(Fixed &fpn1, Fixed &fpn2);
		static const Fixed &min(const Fixed &fpn1, const Fixed &fpn2);
		static const Fixed &max(const Fixed &fpn1, const Fixed &fpn2);

		// Others
		int getRawBits() const;
		void setRawBits(int raw_value);
		float toFloat() const;
		int toInt() const;
		int getFracBit() const;
};

std::ostream &operator<< (std::ostream &out, const Fixed &fpn);

#endif