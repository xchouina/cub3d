#include "cub3d.h"

void	put_img(t_game *game, int x, int y)
{
	void	*mlx;
	void	*window;

	mlx = game->mlx;
	window = game->window;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(mlx, window, game->wall_mm, (25 * x), (25 * y));
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(mlx, window, game->ground_mm, (25 * x), (25 * y));
}

void	map_creation(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->height_fd)
	{
		x = 0;
		while (x < game->width_fd)
		{
			put_img(game, x, y);
			x++;
		}
		y++;
	}
}
