#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	(void)argc;
	fd = 0;
	// open_fd(argv[1]);
	if (parsing(&game, fd, argv[1]) == 1)
		return (1);
	print_tab(&game);
	return (0);
}

void	print_tab(t_game *map)
{
	int	i;

	i = 0;
	while (i < map->height_fd)
	{
		printf("[%d]%s\n", i, map->map[i]);
		i++;
	}
}