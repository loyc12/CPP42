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
		friend std::ostream &operator<< (std::ostream &out, const Fixed &fpn);

		// Other
		int getRawBits() const;
		void setRawBits(int raw_value);
		float toFloat(void) const;
		int toInt(void) const;

};

#endif