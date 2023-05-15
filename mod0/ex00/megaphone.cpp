#include <iostream>

bool is_string_empty(std::string str)
{
	int	i = -1;

	if (str.empty())
		return (true);

	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (false);
	}
	return (true);
}

void s_add(std::string *str, char c)
{
	if (c && c != ' ' && c != '\n')
		*str += c;
	else if ((*str)[0])
		*str += c;
}

int main(int ac, char **av)
{
	int	i = 1;

	std::string	str;
	int			j;

	while (i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			str += std::toupper(av[i][j]);
		}
		i++;

		if (i < ac && av[i][0])
			s_add(&str, ' ');
	}

	if (is_string_empty(str))
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << str << std::endl;

	return EXIT_SUCCESS;
}
