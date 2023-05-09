#ifndef SUPLEMENTS_HPP
# define SUPLEMENTS_HPP

# include <iostream>
# include <iomanip>
# include <string>

# define FIELD_LENGHT 10

void welcome();

std::string get_input(std::string message);
std::string get_input(std::string message, bool capitalize);

void truncate_print(std::string message);
void truncate_print(std::string message, int size);
void manip_print(std::string message, int size);

int true_lenght(std::string message);

#endif //SUPLEMENTS_HPP