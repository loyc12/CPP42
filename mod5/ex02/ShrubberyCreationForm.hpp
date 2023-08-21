#ifndef SRUBBERYCREATIONFORM_HPP
# define SRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define AREA_WIDTH		84
# define AREA_HEIGHT 	42
# define SOIL_RATIO		0.4f

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
		char		area[AREA_HEIGHT][AREA_WIDTH];
		int 		area_w;
		int 		area_h;
		int			soil_h;

	protected:
		// Constructors
		ShrubberyCreationForm();

	public:
		// Constructors - Destructor
		ShrubberyCreationForm(const std::string _name);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		// Others
		const std::string	getTarget(void) const;
		void				beExecuted(Bureaucrat const &b) const;

		// Shrubbing
		void	testShrub(void);
		char	getGrassChar(void);
		void	initArea(void);
		void	drawArea(void);

};

#endif //SRUBBERYCREATIONFORM


//=========================================//
//                                         //
//               @                         //
//              @@@                        //
//             @@@@@                       //
//            @@@@@@@                      //
//           @@@@@@@@@                     //
//          @@@@@@@@@@@                    //
//         @@@@@@@@@@@@@                   //
//          @@@@@@@@@@@@                   //
//            \ |~| @@@                    //
//             \|~| /                      //
//              |~|/                       //
//              |~|                        //
//l,i;,jil;l,jl/~~~\l,l;lj,,li;il,j;li,l,jl//
//..............###........................//
//............##.#.#.......................//
//..........##.#.#..##.....................//
//.........#..#.#..#..#....................//
//...........#.#..#.#......................//
//..............#..........................//
//.........................................//
//=========================================//