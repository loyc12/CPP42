#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include "addons.hpp"

struct ScalarVal
{
	char	c;
	int		i;
	float	f;
	double	d;
};

struct ScalarStr
{
	std::string	c;
	std::string	i;
	std::string	f;
	std::string	d;
};

class ScalarConverter
{
	private:
		ScalarVal	_sv;
		ScalarStr	_ss;

		void	convChar( void ) const;
		void	convInt( void ) const;
		void	convFloat( void ) const;
		void	convDouble( void ) const;

	public:
		ScalarConverter( void );
		ScalarConverter( std::string const &str );
		ScalarConverter( ScalarConverter const &other );
		ScalarConverter &operator=( ScalarConverter const &other );
		~ScalarConverter( void );

		void	convertVal( std::string const & str );
		void	getScalarStrings( void ) const;
};

std::ostream &operator<< ( std::ostream &out, const ScalarConverter &other );

#endif // SCALARCONVERTER_HPP