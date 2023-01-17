#include "cub3d.h"

void	fd_create_map_tab(t_game *game, int fd, char *argv)
{
	char	*str;
	char	*tmp;
	
	game->height_fd = 1;
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
		free(str);
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	fill_tab(game, fd);
}

void	**fill_tab(t_game *game, int fd)
{
	int		i;

	i = 0;
	game->map = ft_calloc(game->height_fd, sizeof(char *));
	if (game->map == NULL)
		ft_quit(fd);
	game->map[i] = get_next_line(fd);
	i++;
	while (game->map)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
	}
	return (0);
}

int	open_fd(char *argv, int fd)
{
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("fd error");
		return (1);
	}
	if (!ft_strendcmp(argv, ".cub"))
		ft_quit(fd);
	return (0);
}
