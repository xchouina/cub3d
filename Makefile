###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_cub3d_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###
CFILES =	cub3d.c 		\
			quit.c 			\
			parsing.c		\
			create_tab.c	\
			raycasting/engine.c	\

SRCS = $(addprefix srcs/, $(CFILES))

NAME = cub3d

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g -Werror -Wextra -Wall -Iincludes -I.

LIBS =	libft/libft.a		\

GET_NEXT_LINE = get_next_line.c get_next_line_utils.c 
GNL_HEADER = ./Get_next_line/get_next_line.h
GNL_PATH = ./Get_next_line/
GNL_SRCS = $(addprefix $(GNL_PATH), $(GET_NEXT_LINE))
GNL_OBJS = ${GNL_SRCS:.c=.o}

END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m

all: $(NAME)

.c.o :
	@$(CC) $(CFLAGS) -I$(GNL_HEADER) -c $< -o $@

$(NAME): $(OBJS) $(GNL_OBJS)
	@$(MAKE) -C libft
	@ $(CC) $(CFLAGS) $(GNL_OBJS) $(OBJS) $(LIBS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "CUB3D	|	STATUS: \033[0;32mOK\033[0;00m"
	@echo "---------------------------------------------"

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS) $(GNL_OBJS)
	@echo "CUB3D		| $(CYAN)OBJECTS CLEANED$(END)"
	@echo "---------------------------------------------"
fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

flcean: fclean

re: fclean all