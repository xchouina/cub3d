#include "cub3d.h"

int	parsing(t_game *game, int fd, char *argv)
{
	fd = open_fd(argv);
	if (fd == -1)
		return (1);
	fd_create_tab_fd(game, fd, argv);
	//parsing a faire pour les point cardinaux et les couleur avant tab_map
	// fd_create_tab_map(game, fd);
	fd_create_tab_map(game);
	//parsing_orientation(game);
	return (0);
}
