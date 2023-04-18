#include <iostream>

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
			str += ' ';
	}

	if (str.empty())
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << str << std::endl;

	return EXIT_SUCCESS;
}
