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

// void	incr_map_height(char *str, t_game *map)
// {
// 	int i;

// 	i = 0;
// 	map->map_start = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (ft_strchr("FC", str[i]))
// 			return ;
// 		if (ft_strchr("10", str[i]))
// 		{
// 			if (map->map_start != 0)
// 				map->map_start = map->height_fd;
// 			map->height_fd++;
// 			return ;
// 		}
// 		i++;
// 	}
// }
