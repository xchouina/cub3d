#include "cub3d.h"

void	my_mlx_pixel_put(t_game	*game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	sky_n_ground(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map_x)
	{
		while (++y < game->map_y)
		{
			my_mlx_pixel_put(game, x, y, 0x00009933);
		}
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	while (x < (game->map_x))
	{
		while (++y < (game->map_y / 2))
		{
			my_mlx_pixel_put(game, x, y, 0x00CCFFFF);
		}
		y = 0;
		x++;
	}
}

void	starting_engine(t_game	*game)
{

	game->map_x = 1920;
	game->map_y = 1080;
	game->mlx = mlx_init();
	
	game->window = mlx_new_window(game->mlx,
			(game->map_x), (game->map_y), "cub3d");
	

	game->img = mlx_new_image(game->mlx, 1920, 1080);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length,
								&game->endian);
	
	sky_n_ground(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);

	// init_assets(game);

	// mlx_put_image_to_window(game->mlx, game->window, game->ylw_dot, (100 * 100), (100 * 00));

	mlx_loop(game->mlx);
}

// void	init_assets(t_game	*game)
// {
// 	int	width;
// 	int	height;

// 	width = 1000;
// 	height = 1000;
// 	game->ylw_dot = mlx_xpm_file_to_image(game->mlx,
// 			"../../textures/ylw_dot.xpm", &width, &height);
// }
