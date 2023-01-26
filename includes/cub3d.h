#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		res_x;
	int		res_y;


// ASSETS
	void	*dot;
	void	*wall_mm;
	void	*ground_mm;
// 

	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


	int		height_fd;
	int		width_fd;
	char	**map;
	char	**tab_fd;
	int		map_start;
	int		map_height;
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
void	fd_create_tab_fd(t_game *game, int fd, char *argv);
void	fill_tab_fd(t_game *game, int fd);
int		open_fd(char *argv);
int		parsing(t_game *game, int fd, char *argv);
void	print_tab_fd(t_game *map);
void	fd_create_tab_map(t_game *game);
void	fill_tab_map(t_game *game);
void	incr_map_height(char *str, t_game *map);
void	print_map(t_game *tab);
void	fill_map_tab(t_game *game);



void	map_creation(t_game *game);
void	starting_engine(t_game	*game);

#endif