#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <libft/include/libft.h>
# include <math.h>
# include "../minilibx/mlx.h"


typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		res_x;
	int		res_y;


	void	*ylw_dot;
	void	*wall;

	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


	int	height_fd;
	int	width_fd;
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
void	map_dimension(t_game *game, int fd);
void	fd_parsing(t_game *game, int fd);




// ENGINE
void	starting_engine(t_game	*game);
void	init_assets(t_game	*game);

#endif