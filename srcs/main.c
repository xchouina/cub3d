#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	(void)argc;
	fd = 0;
	// open_fd(argv[1]);
	if (parsing(&game, fd, argv[1]) == 1)
		return (1);
	print_tab_fd(&game);
	// ft_arrayprint(game.tab_fd);
	starting_engine(&game);
	return (0);
}

void	print_tab_fd(t_game *tab)
{
	int	i;

	i = 0;
	while (i < tab->height_fd)
	{
		printf("[%d]%s\n", i, tab->tab_fd[i]);
		i++;
	}
}

void	print_map(t_game *tab)
{
	int	i;

	i = 0;
	while (i < tab->map_height - 1)
	{
		printf("[%d]%s\n", i, tab->map[i]);
		i++;
	}
}
