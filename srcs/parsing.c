#include "../includes/cub3d.h"

int	parsing(t_game *game, int fd, char *argv)
{
	if (open_fd(argv, fd) == 1)
		return (1);
	fd_create_map_tab(game, fd, argv);
	// parsing_orientation(game);
	return (0);
}
