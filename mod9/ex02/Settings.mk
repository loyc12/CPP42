#------------------------------------------------------------------------------#
#                              PROJECT VARIABLES                               #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	Run

# Source file names (prefix their subdir if needed)
FILES		=	main \
				PmergeMe \

# Directory names
SRCDIR		=
OBJDIR		=
#TSTDIR		=	tests \
#SUBDIRS	=	example \

# Libraries (.a files) to include for compilation
LIBS		=
LIBX		=

# Arguments to call the command with
ARGS		= 1 2 47 7 6  3 9 03 78 7  63 4 73 6 87 36 0 298 56 02 97 836 4 02 9 7836 4 028 73 56 27 9 36 4 208 37 46 2 387 4 43 87 56 2938 75  287 9 35 23 89 4573 9 8 734 252 39 8745 237 6 26 37 45 23 786 45  39 48 65 3 094 56  32 8 475 9  2 98 735 428 7 34  293 8 745 3 98 7 45  38 9 745 34 8  298 3 7 5


#------------------------------------------------------------------------------#
#                                    FLAGS                                     #
#------------------------------------------------------------------------------#

# Use "export XFLAGS= {flags} " to add extra compilation flags

# Flags for gcc, valgrind and leaks
CFLAGS	=	-Wall \
			-Werror \
			-Wextra \
			-Wshadow \
			-std=c++98 \
			$(XFLAGS) \

LFLAGS	=	-atExit \

VFLAGS	=	--leak-check=full \
			--show-leak-kinds=all \
			--trace-children=yes \
			--track-fds=yes \
			--error-exitcode=42 \


# Comment the line bellow to have verbose cmds:
HIDE	=	@

# Potential xflags to use :
# -g					for debug mode compilation (lldb)
# -fsanitize=thread		to see race conditions