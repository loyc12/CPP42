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
		norm libft \
		brew cmake \
		glfw grind \


#------------------------------------------------------------------------------#
#                                  VARIABLES                                   #
#------------------------------------------------------------------------------#

# Compiler, flags and shortcuts
CC		=	c++
CX		=	.cpp
RM		=	rm -rf
CPY		=	cp -f
MKDR	=	mkdir -p
INCLUDE =	-I include

# Creates file paths
SRCS	=	$(addprefix $(SRCDIR), $(addsuffix $(CX), $(FILES)))
OBJS	=	$(addprefix $(OBJDIR), $(addsuffix .o, $(FILES)))

# Command to call when using make run or make leaks
CMD		=	./$(NAME) $(ARGS)


#------------------------------------------------------------------------------#
#                                 BASE TARGETS                                 #
#------------------------------------------------------------------------------#

# For full install (except brew)
long: cmake glfw $(NAME)

# For standard compilation
all: $(NAME)

# Compiles all files into an executable
$(NAME): $(OBJS)
	@echo "$(GREEN)\nFiles compiled with flags : $(CFLAGS)\n $(DEFCOL)"
	$(HIDE) $(CC) $(MODE) $(CFLAGS) -o $@ $^ $(INCLUDE) $(LIBS) $(LIBX)
	@echo "$(CYAN)Executable created !\n $(DEFCOL)"

# Compiles each source file into a .o file
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%$(CX)
	@echo "$(YELLOW)Compiling file : $< $(DEFCOL)"
	$(HIDE) $(CC) $(MODE) $(CFLAGS) -c $< -o $@


#------------------------------------------------------------------------------#
#                               CLEANING TARGETS                               #
#------------------------------------------------------------------------------#

# Removes objects
clear: clean
clean:
	$(HIDE) $(RM) $(OBJS)
	$(HIDE) $(RM) $(NAME).dSYM
	@echo "$(MAGENTA)\nDeleted object files\n $(DEFCOL)"

# Removes object dir and executable
fclear: fclean
fclean: clean
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