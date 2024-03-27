#------------------------------------------------------------------------------#
#                              PROJECT VARIABLES                               #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	PmergeMe

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
ARGS		=  1 24 47 7 694 315 9 03 78 734 63 49 73 1 6 18 42 #69 87 36 0 298 56 02 97 -1 836 40 29 649 78 36 45 028 73 56 27 109 36 4 208 37 46 20 387 452 43 87 56 29 38 75 287 439 35 23 89 45 73 96 248 98 735 428 2077 34 293 88 745 32 98 79 45 38 90 745 34 87 298 135 74 5


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