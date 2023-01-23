#include "cub3d.h"

int	parsing(t_game *game, int fd, char *argv)
{
	game->checker = 0;
	// if game.checker == 1 c une erreur
	fd = open_fd(argv);
	if (fd == -1)
		return (1);
	fd_create_tab_fd(game, fd, argv);
	//parsing a faire pour les point cardinaux et les couleur avant tab_map
	// fd_create_tab_map(game, fd);
	fd_create_tab_map(game);
	check_direction(game);
	if (game->checker == 1)
		return (1);
	check_map(game);
	//parsing_orientation(game);
	return (0);
}

void	check_direction(t_game *game)
{
	int	i;

	i = 0;
	game->direction_complete = 0;
	while (game->tab_fd[i] != NULL)
	{
		if (game->checker == 1 || game->direction_complete == 1)
			return ;
		if (ft_strncmp(game->tab_fd[i], "NO", 2) == 0)
		{
			game->dir_NO = 1;
			//get_text_path_no(game);
		}
		if (ft_strncmp("SO", game->tab_fd[i], 2) == 0)
		{
			game->dir_SO = 1;
			//get_text_path_so(game);
		}
		check_direction_2(game, i);
		check_direction_complete(game);
		if (game->direction_complete != 1)
			check_if_map_last(game, i);
		i++;
	}	
}

void	check_direction_2(t_game *game, int i)
{
	if (ft_strncmp("WE", game->tab_fd[i], 2) == 0)
	{
		game->dir_WE = 1;
		//get_text_path_we(game);
	}
	if (ft_strncmp("EA", game->tab_fd[i], 2) == 0)
	{
		game->dir_EA = 1;
		//get_text_path_ea(game);
	}
	if (ft_strncmp("F", game->tab_fd[i], 1) == 0)
	{
		game->dir_F = 1;
		//get_F_color(game);
	}
	if (ft_strncmp("C", game->tab_fd[i], 1) == 0)
	{
		game->dir_C = 1;
		//get_C_color(game);
	}
}

void	check_direction_complete(t_game *game)
{
	if (game->dir_NO == 1 && game->dir_SO == 1 && game->dir_WE == 1 \
	&& game->dir_EA == 1 && game->dir_F == 1 && game->dir_C == 1)
		game->direction_complete = 1;
}

void	check_if_map_last(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->tab_fd[i][j] != '\0')
	{
		while (ft_iswhitespace(game->tab_fd[i][j]) == true)
		{
			j++;
		}
		if (game->tab_fd[i][j] == '1')
		{
			printf("map_not_last or direction probleme");
			game->checker = 1;
			return ;
		}
		if (game->tab_fd[i][j] == '0')
		{
			printf("map_not_last or direction probleme");
			game->checker = 1;
			return ;
		}
		j++;
	}
}
