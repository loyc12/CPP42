#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "Shrub.hpp"

# define AREA_WIDTH		128
# define AREA_HEIGHT 	42
# define SOIL_RATIO		0.3f
# define SHRUB_COUNT	16

# define BOTTOM_LINE	'-'
# define SIDE_LINE		'!'
# define CORNER_LINE	'+'

# define GROUND_CHAR	':'
# define SKY_CHAR		' '
# define ROOT_CHAR		'X'
# define BUSH_CHAR		'.'


class Bureaucrat;
class Shrub;

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
		void	initArea(void);
		void	addShrubs(int count);
		void	drawArea(void) const;
		void	writeArea(void) const;
		void	setChar(int x, int y, char c);
		char	getChar(int x, int y) const;
		char	getGrassChar(void) const;
		char	getBarkChar(void) const;
		char	getLeafChar(void) const;
};

#endif //SHRUBBERYCREATIONFORM


//=========================================//
//  \\|//                                  //
//  ==O==        @          __   __        //
//  //|\\       @@@           \_/          //
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