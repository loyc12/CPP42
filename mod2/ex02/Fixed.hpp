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
			// Arithmetic
		Fixed operator+ (const Fixed &other);
		Fixed operator- (const Fixed &other);
		Fixed operator* (const Fixed &other);
		Fixed operator/ (const Fixed &other);
		Fixed &operator+= (const Fixed &other);
		Fixed &operator-= (const Fixed &other);
		Fixed &operator*= (const Fixed &other);
		Fixed &operator/= (const Fixed &other);
			// Comparison
		bool operator!= (const Fixed &other);
		bool operator> (const Fixed &other);
		bool operator>= (const Fixed &other);
		bool operator== (const Fixed &other);
		bool operator<= (const Fixed &other);
		bool operator< (const Fixed &other);
			// Incrementation
		Fixed &operator++ ();
		Fixed &operator-- ();
		Fixed operator++ (int);
		Fixed operator-- (int);

		friend std::ostream &operator<< (std::ostream &out, const Fixed &fpn);

		// Other
		int getRawBits() const;
		void setRawBits(int raw_value);
		float toFloat() const;
		int toInt() const;

};

#endif