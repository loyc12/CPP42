include Settings.mk
include Colours.mk

#------------------------------------------------------------------------------#
#                                   GENERICS                                   #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all long \
		clean clear \
		fclean fclear \
		re run rerun \
		leaks releaks \
		vleaks revleaks \
		norm sub libft \
		brew cmake \
		glfw grind \
		help man \


#------------------------------------------------------------------------------#
#                                  VARIABLES                                   #
#------------------------------------------------------------------------------#

# Compiler, flags and shortcuts
CC		=	c++
CX		=	.cpp
RM		=	rm -rf
CPY		=	cp -f
MKDR	=	mkdir -p

# Formating include paths
INCS	=	$(addprefix -I , $(INCDIRS))

# Creates srcfiles paths
SRCS	=	$(addprefix $(SRCDIR), $(addsuffix $(CX), $(SRCFILES)))
OBJS	=	$(addprefix $(OBJDIR), $(addsuffix .o, $(SRCFILES)))

# Command to call when using make run or make leaks
CMD		=	./$(NAME) $(ARGS)


#------------------------------------------------------------------------------#
#                                 BASE TARGETS                                 #
#------------------------------------------------------------------------------#

# For standard compilation
all: $(OBJDIR) $(NAME)

# Compiles all files into an executable
$(NAME): $(OBJS)
	@echo "$(GREEN)\nFiles compiled with flags : $(CFLAGS)\n $(DEFCOL)"
	$(HIDE) $(CC) $(MODE) $(CFLAGS) $(INCS) $(LIBS) -o $@ $^
	@echo "$(CYAN)Executable created !\n $(DEFCOL)"

# Creates the object directory
$(OBJDIR):
	$(HIDE) $(MKDR) $(OBJDIR)

# Compiles each source file into a .o file
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%$(CX)
	@echo "$(YELLOW)Compiling file : $< $(DEFCOL)"
	$(HIDE) $(CC) $(MODE) $(CFLAGS) $(INCS) -c $< -o $@


#------------------------------------------------------------------------------#
#                               CLEANING TARGETS                               #
#------------------------------------------------------------------------------#

# Removes objects
clean clear:
	$(HIDE) $(RM) $(OBJS)
	$(HIDE) $(RM) $(NAME).dSYM
	@echo "$(MAGENTA)\nDeleted object files\n $(DEFCOL)"

# Removes object dir and executable
fclean fclear: clean
	$(HIDE) $(RM) $(OBJDIR)
	@echo "$(RED)Deleted object directory\n $(DEFCOL)"
	$(HIDE) $(RM) $(NAME)
	@echo "$(RED)Deleted executable\n $(DEFCOL)"

# Removes object dir and executable and remakes everything
re: fclean all
	@echo "$(CYAN)Rebuilt everything !\n $(DEFCOL)"


#------------------------------------------------------------------------------#
#                               SHORTCUT TARGETS                               #
#------------------------------------------------------------------------------#

# Runs the program
rerun: re run
run: all
	@echo "$(YELLOW)Launching command : $(CMD) $(DEFCOL)"
	@echo "$(GREEN)"
	$(HIDE) $(CMD); \
	if [ $$? -eq 0 ]; then \
		echo "$(GREEN)\nExited normally\n $(DEFCOL)"; \
	else \
		echo "$(RED)\nExited with error code $$?\n $(DEFCOL)"; \
	fi
	$(HIDE) $(MAKE) clean

# Runs the program with leaks
releaks: re leaks
leaks: all
	@echo "$(RED)Launching command : leaks $(LFLAGS) -- $(CMD) $(DEFCOL)"
	@echo "$(YELLOW)"
	$(HIDE) leaks $(LFLAGS) -- $(CMD); \
	if [ $$? -eq 0 ]; then \
		echo "$(GREEN)\nExited normally\n $(DEFCOL)"; \
		echo "$(GREEN)No leaks found...\n $(DEFCOL)"; \
	else \
		echo "$(RED)\nExited with error code $$?\n $(DEFCOL)"; \
		echo "$(RED)! LEAKS FOUND !\n $(DEFCOL)"; \
	fi
	$(HIDE) $(MAKE) clean

# Runs the program with valgrind
revleaks: re vleaks
vleaks: all
	@echo "$(RED)Launching command : valgrind $(VFLAGS) $(CMD) $(DEFCOL)"
	@echo "$(YELLOW)"
	$(HIDE) valgrind $(VFLAGS) $(CMD); \
	if [ $$? -eq 0 ]; then \
		echo "$(GREEN)\nExited normally\n $(DEFCOL)"; \
		echo "$(GREEN)No leaks found...\n $(DEFCOL)"; \
	else \
		echo "$(RED)\nExited with error code $$? $(DEFCOL)"; \
		echo "$(RED)! LEAKS FOUND !\n $(DEFCOL)"; \
	fi
	$(HIDE) $(MAKE) clean

# Runs the norminette
norm:
	@echo "$(DEFCOL)"
	@echo "$(YELLOW)Norminetting $(CX) files $(RED)"
	@norminette $(SRCS) | grep Error || true
	@echo "$(DEFCOL)"
	@echo "$(YELLOW)Norminetting .hpp files $(RED)"
	@norminette include | grep Error || true
	@echo "$(DEFCOL)"

# Updates the git submodules
sub:
	@echo "$(YELLOW)Updating submodules \n $(WHITE)"
	$(HIDE) git submodule update --init --recursive
	@echo "$(GREEN)Submodules updated ! \n $(DEFCOL)"

# Updates the libft module (requires push after)
libft:
	@echo "$(YELLOW)Updating libft to latest commit $(WHITE)"
	$(HIDE) cd Libft42 ; git pull origin main
	@echo "$(GREEN)Libft updated ! \n$(DEFCOL)"


#------------------------------------------------------------------------------#
#                                 BREW TARGETS                                 #
#------------------------------------------------------------------------------#

# For full install (except brew)
long: cmake glfw $(NAME)

# Installs/Updates homebrew (WARNING : can be very slow !)
brew:
	@echo "$(YELLOW)\nInstalling Brew\n $(DEFCOL)"
	$(HIDE) bash .brew_install.sh; \
	if [ $$? -eq 0 ]; then \
		echo "$(BLUE)\nBrew installed !\n $(DEFCOL)"; \
	else \
		echo "$(RED)\n! FAILED TO INSTALL BREW !\n $(DEFCOL)"; \
	fi

# Installs/Updates cmake (WARNING : can be very slow !)
cmake:
	@echo "$(YELLOW)\nInstalling Cmake\n $(DEFCOL)"
	$(HIDE) brew install cmake; \
	if [ $$? -eq 0 ]; then \
		echo "$(BLUE)\nCmake installed !\n $(DEFCOL)"; \
	else \
		echo "$(RED)\n! FAILED TO INSTALL CMAKE !\n $(DEFCOL)"; \
	fi

# Installs/Updates glfw
glfw:
	@echo "$(YELLOW)\nInstalling GFLW\n $(DEFCOL)"
	$(HIDE) brew install glfw; \
	if [ $$? -eq 0 ]; then \
		echo "$(BLUE)\nGLFW installed !\n $(DEFCOL)"; \
	else \
		echo "$(RED)\n! FAILED TO INSTALL GLFW !\n $(DEFCOL)"; \
	fi

# Installs/Updates valgrind
grind:
	@echo "$(YELLOW)\nInstalling Valgrind\n $(DEFCOL)"
	$(HIDE) brew tap LouisBrunner/valgrind
	$(HIDE) brew install --HEAD LouisBrunner/valgrind/valgrind; \
	if [ $$? -eq 0 ]; then \
		echo "$(BLUE)\nVALGRIND installed !\n $(DEFCOL)"; \
	else \
		echo "$(RED)\n! FAILED TO INSTALL VALGRIND !\n $(DEFCOL)"; \
	fi


#------------------------------------------------------------------------------#
#                                 HELP TARGETS                                 #
#------------------------------------------------------------------------------#

# Displays the help message
help man:
	@echo "$(BLUE)Usage : make [target] $(DEFCOL)"
	@echo ""
	@echo "$(CYAN)Targets$(DEFCOL)"
	@echo ""
	@echo "  $(GREEN)help/man$(DEFCOL)   : Displays this message"
	@echo ""
	@echo "  $(GREEN)all$(DEFCOL)        : Compiles the program"
	@echo "  $(GREEN)clea[n/r]$(DEFCOL)  : Removes object files"
	@echo "  $(GREEN)fclea[n/r]$(DEFCOL) : Removes object files and executable"
	@echo ""
	@echo "  $(GREEN)re$(DEFCOL)         : Removes object files and executable and recompiles"
	@echo "  $(GREEN)(re)run$(DEFCOL)    : (Re)Compiles and runs the program"
	@echo "  $(GREEN)(re)leaks$(DEFCOL)  : (Re)Compiles and runs the program with leaks"
	@echo "  $(GREEN)(re)vleaks$(DEFCOL) : (Re)Compiles and runs the program with valgrind"
	@echo ""
	@echo "  $(GREEN)sub$(DEFCOL)        : Updates the git submodules"
	@echo "  $(GREEN)libft$(DEFCOL)      : Updates the libft submodule"
	@echo "  $(GREEN)norm$(DEFCOL)       : Norminettes the project"
	@echo ""
	@echo "  $(GREEN)long$(DEFCOL)       : Installs/Updates everything except brew"
	@echo "  $(GREEN)brew$(DEFCOL)       : Installs/Updates homebrew"
	@echo "  $(GREEN)cmake$(DEFCOL)      : Installs/Updates cmake"
	@echo "  $(GREEN)glfw$(DEFCOL)       : Installs/Updates glfw"
	@echo "  $(GREEN)grind$(DEFCOL)      : Installs/Updates valgrind"
	@echo ""