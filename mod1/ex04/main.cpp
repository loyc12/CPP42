#include <iostream>
#include <fstream>

// prints error and exits
void throw_error(std::string message)
{
	std::cout << message << std::endl;
	exit(1);
}

// checks if s_find matches what's stored in 'line' from index 'i' upward
bool is_match(std::string line, int i, std::string s_find)
{
	int	j = 0;

	while (line[i + j] == s_find[j])
	{
		j++;
		if (!s_find[j])
			return (true);
	}
	return (false);
}

int main(int ac, char **av)
{
	int counter = 0;

	if (ac != 4)
		throw_error("Input error : Wrong number of arguments");

	std::string	f_name = av[1]; // name of the input file
	std::string	s_find = av[2]; // word to find in the file
	std::string	s_repl = av[3]; // word to replace it by

	if (f_name.empty() || s_find.empty()) //avoids trying tp open/replace an empty file/string
		throw_error("Input error : Empty file/search string");

	std::fstream f_in; // opens input file
	f_in.open(f_name, std::ios::in);
	if (!f_in)
		throw_error("Internal error : Unable to open input file");

	std::fstream f_out; // opens output (.replace) file
	f_out.open(f_name + ".replace", std::ios::out | std::ios::trunc);
	if (!f_in)
		throw_error("Internal error : Unable to open ouput file");

	//debug info
	std::cout << "File Name : \'" << f_name << "\'" << std::endl;
	std::cout << "Replacing : \'" << s_find << "\' to \'" << s_repl << "\'" << std::endl << std::endl;

	//main replacement loop
	std::string line;
	if (getline(f_in, line))
	{
		while(true)
		{
			int i = -1;
			while (line[++i])
			{
				if (is_match(line, i, s_find))
				{ // if a match is found, writes the replacement instead of the original word
					int j = -1;
					while (s_repl[++j])
						f_out << s_repl[j];

					i += s_find.length() - 1; // skips the word we are replacing
					counter++;
				}
				else
					f_out << line[i];
			}
			if (!getline(f_in, line))
			{
				if (!line[0]) // if the last line was empty, adds an extra newline
					f_out << std::endl; // this is to ensure file parity
				break;
			}
			f_out << std::endl;
		}
	}

	//debug info
	std::cout << "Copied the file with " << counter << " modifications" << std::endl;

	// closes both files
	f_in.close();
	f_out.close();
}