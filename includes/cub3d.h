#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <libft/include/libft.h>
# include <unistd.h>

typedef struct s_game
{
	int		height_fd;
	int		width_fd;
	char	**map;

}t_game;

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_textures
{

}t_textures;

void	ft_quit(int fd);
void	fd_create_map_tab(t_game *game, int fd, char *argv);
void	**fill_tab(t_game *game, int fd);
int		open_fd(char *argv, int fd);
int		parsing(t_game *game, int fd, char *argv);

#endif