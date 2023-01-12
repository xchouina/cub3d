#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	(void)argc;
	fd = 0;
	if (parsing(&game, fd, argv[1]) == 1)
		return (1);
	return (0);
}