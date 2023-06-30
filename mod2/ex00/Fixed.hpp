#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _raw_value;
		static const int _frac_bit = 8;

	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &other);

		// Operators
		Fixed & operator=(const Fixed &other);

		// Destructor
		~Fixed();

		// Getters / Setters
		int getRawBits() const;
		void setRawBits(int raw_value);

};

#endif