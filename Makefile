###_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_cub3d_*_*_*_*_*_*_*_*_*_*_*_*_###
###-------------------------# VARIABLES ##-------------------------###
CFILES =	cub3d.c				\
			quit.c				\
			fd_parsing.c		\
			raycasting/engine.c	\

SRCS = $(addprefix srcs/, $(CFILES))

NAME = cub3d

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -g -Werror -Wextra -Wall -Iincludes -I.

LIBS =	libft/libft.a		\

all: $(NAME)

.c.o :
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@ $(CC) $(CFLAGS) $(OBJS) $(LIBS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "CUB3D	|	STATUS: \033[0;32mOK\033[0;00m"
	@echo "---------------------------------------------"

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)
	@echo "CUB3D	|	STATUS: \033[0;36mCLEANED\033[0;00m"
	@echo "---------------------------------------------"
fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME)

re: fclean all
