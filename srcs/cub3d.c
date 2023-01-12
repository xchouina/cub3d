#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!ft_strendcmp(argv[1], ".cub"))
		ft_quit(fd);
	// fd_parsing(&game, fd);
	starting_engine(&game);
}


