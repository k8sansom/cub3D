#include "../inc/cub3d.h"

static void	get_floor(t_game *game, char *str)

void	read_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->cub_height)
	{
		if (ft_strncmp(game->cub_file[i], "NO ", 3) == 0)
			game->textures.north = game->cub_file[i];
		else if (ft_strncmp(game->cub_file[i], "SO ", 3) == 0)
			game->textures.south = game->cub_file[i];
		else if (ft_strncmp(game->cub_file[i], "WE ", 3) == 0)
			game->textures.west = game->cub_file[i];
		else if (ft_strncmp(game->cub_file[i], "EA ", 3) == 0)
			game->textures.east = game->cub_file[i];
		// else if (ft_strncmp(game->cub_file[i], "F ", 2) == 0)
		// 	get_floor(game, game->cub_file[i]);
		// else if (ft_strncmp(game->cub_file[i], "C ", 2) == 0)
		// 	get_ceiling(game, game->cub_file[i]);
		i++;
	}
}