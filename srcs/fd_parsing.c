#include "cub3d.h"

void	fd_parsing(t_game *game, int fd)
{
	char	*str;
	char	*tmp;

	game->height_fd = 1;
	printf("fd = %d\n", fd);
	str = get_next_line(fd);
	tmp = ft_strtrim(str, "\n");
	free(str);
	game->width_fd = ft_strlen(tmp);
	free(tmp);
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		game->height_fd++;
		printf("height = %d\n", game->height_fd);
		free(str);
	}	
}
