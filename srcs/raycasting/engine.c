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
	while (x < game->res_x)
	{
		while (++y < game->res_y)
			my_mlx_pixel_put(game, x, y, 0x0099FF99);
		y = 0;
		x++;
	}
	x = 0;
	y = 0;
	while (x < (game->res_x))
	{
		while (++y < (game->res_y / 2))
			my_mlx_pixel_put(game, x, y, 0x00CCFFFF);
		y = 0;
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}

void	init_assets(t_game	*game)
{
	game->width = 30;
	game->height = 30;
	// game->ylw_dot = mlx_xpm_file_to_image(game->mlx,
	// 		"../../textures/ylw_dot.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
					"textures/2d_wall.xpm", &game->width, &game->height);
}

void	starting_engine(t_game	*game)
{
	game->res_x = 1920;
	game->res_y = 1080;
	game->mlx = mlx_init();	
	game->window = mlx_new_window(game->mlx, game->res_x, game->res_y, "cub3d");
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);

	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
					&game->line_length, &game->endian);
	sky_n_ground(game);
	// cube_pixel(game, 100, 100);
										// mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	init_assets(game);


	mlx_put_image_to_window(game->mlx, game->window, game->wall, 0, 0);

	mlx_loop(game->mlx);
}

// minimap_creation(t_game *game)
// {
// 	// INSERT: 
// 	// if (vars->map_tab[y][x] == '1')
// 	// 	mlx_put_image_to_window(mlx, window, vars->wall, (25 * x), (25 * y));
// 	// else
// 	// 	mlx_put_image_to_window(mlx, window, vars->ground, (25 * x), (25 * y));
// }
