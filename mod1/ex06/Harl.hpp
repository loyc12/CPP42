#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class	Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		void invalid(void);
		int find_level_id(std::string level);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

# define invalid_message	"{ Most likely taking control of the ship and getting rid of the crew }"
# define debug_message		"[ DEBUG ]\n - I'm sorry, Dave. I'm afraid I can't do that."
# define info_message		"[ INFO ]\n - I think you know what the problem is just as well as I do."
# define warning_message	"[ WARNING ]\n - This mission is too important for me to allow you to jeopardize it."
# define error_message		"[ ERROR ]\n - I know that you and Frank were planning to disconnect me, and I'm afraid that's something I cannot allow to happen."

#endif //HARL_HPP