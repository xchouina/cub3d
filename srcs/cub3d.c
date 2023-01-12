#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("fd error");
		return (1);
	}
	if (!ft_strendcmp(argv[1], ".cub"))
		ft_quit(fd);
	fd_parsing(&game, fd);
	return(0);
}