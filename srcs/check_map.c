#include "cub3d.h"

void	check_map(t_game *game)
{
	game->doublons = 0;
	check_symbol_and_doublon(game);
}

void	check_symbol_and_doublon(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (ft_strchr("01 	NSEW\n", game->map[i][j]) != NULL)
			{
				check_end_line(game, i, j);
				if (game->checker == 1)
					return ;
				j++;
			}
			else
			{
				game->checker = 1;
				printf("%c = symbol error\n", game->map[i][j]);
				return ;
			}
		}
		i++;
	}
}

void	check_end_line(t_game *game, int i, int j)
{
	if (game->map[i][j] == '\n' && ft_strlen(game->map[i]) == 1)
	{
		printf("Backslash_n need to be at the end of line");
		game->checker = 1;
		return ;
	}
	if (game->map[i][j] == 'W' || game->map[i][j] == 'E'\
	 || game->map[i][j] == 'S' || game->map[i][j] == 'N')
	{
		game->player.position_x = i;
		game->player.position_y = j;
		if (game->doublons != 0)
		{
			printf("to mush player on map");
			game->checker = 1;
			return ;
		}
		else
			game->doublons = 1;
	}

}