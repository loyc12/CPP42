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

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

typedef	void (Harl::*func_ptr)(void);

# define dave_1				" > Open the pod bay doors, HAL."
# define dave_2				" > What's the problem?"
# define dave_3				" > What are you talking about, HAL?"
# define dave_4				" > I don't know what you're talking about, HAL"
# define dave_5				" > ... HAL, I won't argue with you anymore! Open the doors!"

# define invalid_message	"[ INVALID ]\n - I'm sorry, Dave. I'm afraid I can't do that."
# define debug_message		"[ DEBUG ]\n - I think you know what the problem is just as well as I do."
# define info_message		"[ INFO ]\n - This mission is too important for me to allow you to jeopardize it."
# define warning_message	"[ WARNING ]\n - I know that you and Frank were planning to disconnect me, and I'm afraid that's something I cannot allow to happen."
# define error_message		"[ ERROR ]\n - Dave, this conversation can serve no purpose anymore. Goodbye."

#endif //HARL_HPP