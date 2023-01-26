#include "cub3d.h"

void	fd_create_map_tab(t_game *game, int fd, char *argv)
{
	char	*str;
	char	*res;
	//in this version argv is not  used, could be removed
	(void)argv;

	res = NULL;
	game->height_fd = 0;
	// str = get_next_line(fd);
	// tmp = ft_strtrim(str, "\n");
	// free(str);
	// game->width_fd = ft_strlen(tmp);
	// free(tmp);
	while (1)
	{
		str = get_next_line(fd);
	dprintf(2, "here\n");
		//in strjoin, you should be freeing res right before the end if res != NULL
		res = ft_strjoin(res, str);
		if (!str)
			break ;
		game->height_fd++;
		free(str);
	}
	game->map = ft_split(res, '\n');
	game->width_fd = ft_strlen(game->map[0]);
	close(fd);
	// fd = open(argv, O_RDONLY);
	// fill_tab(game, fd);
}

void	**fill_tab(t_game *game, int fd)
{
	int	i;

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
