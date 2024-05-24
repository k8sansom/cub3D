/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:53:18 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/24 11:24:01 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_duplicates(t_game *game)
{
	if (!ft_strcmp(game->textures.south, game->textures.north) || \
		!ft_strcmp(game->textures.east, game->textures.north) || \
		!ft_strcmp(game->textures.west, game->textures.north) || \
		!ft_strcmp(game->textures.east, game->textures.south) || \
		!ft_strcmp(game->textures.west, game->textures.south) || \
		!ft_strcmp(game->textures.east, game->textures.west))
		full_exit("Error: duplicate texture file", game, 2);
}

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
	printf("%s\n", north);
	if (north[n - 4] != '.' || south[s - 4] != '.' || east[e - 4] != '.' \
		|| west[w - 4] != '.' || north[n - 3] != 'x' || south[s - 3] != 'x' \
		|| east[e - 3] != 'x' || west[w - 3] != 'x' || north[n - 2] != 'p' \
		|| south[s - 2] != 'p' || east[e - 2] != 'p' || west[w - 2] != 'p' \
		|| north[n - 1] != 'm' || south[s - 1] != 'm' || east[e - 1] != 'm' \
		|| west[w - 1] != 'm')
		return (1);
	return (0);
}


void	check_textures(t_game *game)
{
	int	i;

	i = 0;
	if (!game->textures.north || !game->textures.south || !game->textures.west \
		|| !game->textures.east || !game->textures.ceiling_str || \
		!game->textures.floor_str)
		full_exit("Error: texture path missing", game, 2);
	// if (check_xpms(game->textures.north, game->textures.south, \
	// 			game->textures.east, game->textures.west))
	// 	full_exit("Error: texture file is not xpm", game, 2);
	check_duplicates(game);
	game->textures.ceiling = get_rgbs(game, game->textures.ceiling_str);
	game->textures.floor = get_rgbs(game, game->textures.floor_str);
	while (i < 3)
	{
		if ((game->textures.floor[i] < 0 || game->textures.floor[i] > 255) \
			|| (game->textures.ceiling[i] < 0 || \
			game->textures.ceiling[i] > 255))
			full_exit("Error: with color rgb", game, 2);
		i++;
	}
	game->textures.hex_ceiling = convert_rgb(game->textures.ceiling);
	game->textures.hex_floor = convert_rgb(game->textures.floor);
}
