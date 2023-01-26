#	Huge credit to Armorine86 on github
#		https://github.com/Armorine86
#	
#	This Makefile is inspired a lot from
#	his Makefile template. I played with
#	it and add comment for new student at
#	42 Quebec.

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= cub3d

## ----- COMPILER AND FLAGS ----- ##
CC				= clang

CFLAGS			= -Wall -Wextra -Werror

MINIFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT			= ./libft/libft.a

LIBFT_DIR		= cd ./libft && make 

## ----- ADD FILES TUTORIAL ----- ##

# to add a directory to srcs :
#
#	X_DIR = $(SRCS_DIR)x
#		(Create dir srcs/x)
#
#	X_FILES = x_y.cpp ect
#		(The file in the folder)
#
#	X_SRCS	=	$(addprefix $(X_DIR), $(X_FILES))
#		(add the prefix to all files)
#
#	OBJ_FILES = $(X_FILES:.c=.o)
#		Routine to get .c to .o
#
#	VPATH = $(X_DIR)

## ----- PATH TO DIRECTORIES ----- ##
SRCS_DIR		= srcs/

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

MAIN_DIR		= $(SRCS_DIR)main

# EXECUTION_DIR	=	execution/

# RAYCASTING_DIR	=	raycasting/

# PARSING_DIR		=	parsing/

## ----- FILES ----- ##
SRCS_FILES			=	engine.c		\
						create_tab.c	\
						minimap.c		\
						quit.c			\
						parsing.c		\

MAIN_FILES			=	main.c		\
					

# HEADER_FILES		=				\

# EXECUTION_FILES	=	\
						

# RAYCASTING_FILES	=	
						

# PARSING_FILES		=


OBJ_FILES		=	$(SRCS_FILES:.c=.o) 		\
					$(MAIN_FILES:.c=.o)			\
					$(EXECUTION_FILES:.c=.o)	\
					$(RAYCASTING_FILES:.c=.o)	\
					$(PARSING_FILES:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##

OBJS				=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
MAIN_SRCS			=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))
HEADER_SRCS			=	$(addprefix $(INCLUDE_DIR), $(HEADER_FILES))
# EXECUTION_SRCS	=	$(addprefix $(EXECUTION_DIR), $(EXECUTION_FILES))
# RAYCASTING_SRCS	=	$(addprefix $(RAYCASTING_DIR), $(RAYCASTING_FILES))
# PARSING_SRCS		=	$(addprefix $(PARSING_DIR), $(RAYCASTING_FILES))

VPATH				=	$(SRCS_DIR) $(MAIN_DIR)

## ----- .C TO .O CONVERT ----- ##

$(OBJ_DIR)%.o: %.c $(HEADER_SRCS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@
#	Here you can add any header foler by adding -I $(header_directory)


#--------------------------------------------------------------#
## ----- compile differently on other os ----- ##
#
# ifeq ($(shell uname), Linux)
#
#		(code to do if then you run in shell uname, and the result is Linux)
#		a good exemple would be to change the compilation flags and library
#		on other OS. Ex:
#
#		MLX visual library only need a flag in compilation at school since
#		the library installed for every session. At home on linux you would
#		need the srcs code of the lib and some manipulation to compile it correctly.
#		You could use ifeq to compile with the make command on both os with
#		different compiling rules.
#
# endif
#		Note : You cant put ifeq and endif in a variable/macro. It has
#				to be outside (ifeq before and endif after) any
#				declaration in Makefile

## ----- TOOLS AND COLORS ----- ##
RM				= rm -rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

#	Here you could add some rules to compile an other makefile
#
#	Exemple compilting the libft :
#
#	LIBFT			= make -C $(LIBFT_DIR)
#
#	Wich if you call $(LIBFT);
#	The makefile in LIBFT_DIR will get executed,
#	then come back to this Makefile.


## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##

#	Here we add what is necessary for compilation
#	Wich is by default the obj directory and the name
#	of the program. You could protect your compilation
#	by adding dependencies.
all: obj $(NAME)


#	1) Dependencies (creating .o files)
#	2) You could add $(LIBFT) or other rules
#		to compile anything necessary
#	3) Call the compiler with his dependencies
#		(.o files, library.a) with -o (output) name
$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)


#	Create .o folder for easy clean
obj:
	@mkdir -p $(OBJ_DIR)

## ----- make options ----- #

#	Here are some options that you could add
#	such as tester and other compilation flags
#	you might now always want.

debug: CFLAGS += -g
debug: obj $(NAME)

opti: CFLAGS += -O3
opti: obj $(NAME)

leak: obj $(NAME)
	@valgrind ./cub3d

setup: 
	@rm -rf LICENSE images README.md .git

## ----- CLEAN COMMANDS ----- ##

#	If you us an other dir with a makefile
#	you can run make clean in it like that:
#
#	@make -C $(LIBFT_DIR) clean
#		(libft exemple)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)
#	Here don't forget to delete .a previously
#	compiled in other dir/Makefile like libft
#
#	Ex : @rm -rf $(LIBFT_DIR)libft.a

re: fclean all

.PHONY: all clean fclean re


