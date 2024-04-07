#------------------------------------------------------------------------------#
#                              PROJECT VARIABLES                               #
#------------------------------------------------------------------------------#

# Executable name
NAME		=	PmergeMe

# Source file names (prefix their subdir if needed)
FILES		=	main \
				PmergeMe \
				PsortMe \
				Addons \

# Directory names
SRCDIR		=
OBJDIR		=
#TSTDIR		=	tests \
#SUBDIRS	=	example \

# Libraries (.a files) to include for compilation
LIBS		=
LIBX		=

# Arguments to call the command with
ARGS		= 1 73 47 7 694 9 315 03 78 534 #63 49 24 1 6 10 18 42 69 87 0 36 298 11 56 02 97 -1 836 40 29 649 78 36 45 028 73 56 27 109 36 4 208 37 46 12 387 452 43 87 56 29 38 75 287 439 35 23 89 45 73 96 248 98 735 428 20 77 34 293 88 743 32 98 79 45 38 90 455 34 87 298 135 74 5

#ARGS		= 99 1 88 2 77 3 66 4 55 5 44 6 33 7 22 8 11 9 # 18  comparisons ( best case )
#ARGS		= 11 9 22 8 33 7 44 6 55 5 66 4 77 3 88 2 99 1 # 54  comparisons
#ARGS		= 1 11 2 22 3 33 4 44 5 55 6 66 7 77 8 88 9 99 # 54  comparisons
#ARGS		= 1 2 3 4 5 6 7 8 9 11 22 33 44 55 66 77 88 99 # 89  comparisons
#ARGS		= 9 8 7 6 5 4 3 2 1 99 88 77 66 55 44 33 22 11 # 90  comparisons
#ARGS		= 99 9 88 8 77 7 66 6 55 5 44 4 33 3 22 2 11 1 # 90  comparisons
#ARGS		= 9 8 7 6 5 4 3 2 1 11 22 33 44 55 66 77 88 99 # 92  comparisons
#ARGS		= 99 88 77 66 55 44 33 22 11 1 2 3 4 5 6 7 8 9 # 108 comparisons
#ARGS		= 99 88 77 66 55 44 33 22 11 9 8 7 6 5 4 3 2 1 # 125 comparisons ( worst case ? )

#ARGS		= 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 #          26  comparisons ( all equal )
#ARGS		= 8 4 99 22 11 88 1 5 6 55 33 77 44 66 9 3 2 7 # 84  comparisons ( random order )
#ARGS		= 4 8 22 7 44 5 99 11 2 77 33 9 5 7 8 88 6 3 1 # 72  comparisons ( random order )

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