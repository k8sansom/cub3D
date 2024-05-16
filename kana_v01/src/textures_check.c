#include "../inc/cub3d.h"

static int	check_xpms(char *north, char *south, char *east, char *west)
{
	size_t	n;
	size_t	s;
	size_t	e;
	size_t	w;

	n = ft_strlen(north);
	s = ft_strlen(south);
	e = ft_strlen(east);
	w = ft_strlen(west);
	if (north[n - 5] != '.' || south[s - 5] != '.' || east[e - 5] != '.' \
		|| west[w - 5] != '.' || north[n - 4] != 'x' || south[s - 4] != 'x' \
		|| east[e - 4] != 'x' || west[w - 4] != 'x' || north[n - 3] != 'p' \
		|| south[s - 3] != 'p' || east[e - 3] != 'p' || west[w - 3] != 'p' \
		|| north[n - 2] != 'm' || south[s - 2] != 'm' || east[e - 2] != 'm' \
		|| west[w - 2] != 'm')
		return (1);
	return (0);
}


void	check_textures(t_game *game)
{
	int	i;

	i = 0;
	if (!game->textures.north || !game->textures.south || !game->textures.west \
		|| !game->textures.east || !game->textures.ceiling_str || !game->textures.floor_str)
		full_exit("Error: texture path missing", game, 2);
	if (ft_isdir(game->textures.north) || ft_isdir(game->textures.south) \
		|| ft_isdir(game->textures.east) || ft_isdir(game->textures.west))
		full_exit("Error: texture is directory", game, 2);
	if (check_xpms(game->textures.north, game->textures.south, \
				game->textures.east, game->textures.west))
		full_exit("Error: texture file is not xpm", game, 2);
	while (i < 3)
	{
		if ((game->textures.floor[i] < 0 || game->textures.floor[i] > 255) \
			|| (game->textures.ceiling[i] < 0 || game->textures.ceiling[i] > 255))
			full_exit("Error: with color rgb", game, 2);
		i++;
	}
	game->textures.hex_ceiling = convert_rgb(game->textures.ceiling);
	game->textures.hex_floor = convert_rgb(game->textures.floor);
}