#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include "addons.hpp"

struct Scalar
{
	std::string	c;
	std::string	i;
	std::string	f;
	std::string	d;
};

class ScalarConverter
{
	private:
		Scalar	_scalar;

		void	convFromChar(  std::string const & str  );
		void	convFromInt(  std::string const & str  );
		void	convFromFloat(  std::string const & str  );
		void	convFromDouble(  std::string const & str  );
		void	badInput( void );

	public:
		ScalarConverter( void );
		ScalarConverter( std::string const &str );
		ScalarConverter( ScalarConverter const &other );
		ScalarConverter &operator=( ScalarConverter const &other );
		~ScalarConverter( void );

		void		convert( std::string const & str );
		std::string	getString() const;
};

std::ostream &operator<< ( std::ostream &out, const ScalarConverter &rhs );

#endif // SCALARCONVERTER_HPP