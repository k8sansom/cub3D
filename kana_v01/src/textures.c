/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:41:55 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 12:43:11 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static int check_digits(const char *str)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
			trigger++;
		i++;
	}
	if (trigger)
		return (1);
	return (0);
}

static int	*get_rgbs(t_game *game, char *str)
{
	char	**rgb_arr;
	int		*rgb;
	int		i;

	rgb_arr = ft_split(str, ',');
	i = 0;
	while (rgb_arr[i] && check_digits(rgb_arr[i]))
		i++;
	if (i != 3)
	{
		free_arr(rgb_arr);
		full_exit("Error: with color rgb", game, 1);
	}
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
	{
		free_arr(rgb_arr);
		full_exit("Malloc error", game, 1);
	}
	i = -1;
	while (rgb_arr[++i])
		rgb[i] = ft_atoi(rgb_arr[i]);
	free_arr(rgb_arr);
	return (rgb);
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
	game->textures.ceiling = get_rgbs(game, game->textures.ceiling_str);
	game->textures.floor = get_rgbs(game, game->textures.floor_str);
	while (i < 3)
	{
		if ((game->textures.floor[i] < 0 || game->textures.floor[i] > 255) \
			|| (game->textures.ceiling[i] < 0 || game->textures.ceiling[i] > 255))
			full_exit("Error: with color rgb", game, 2);
		i++;
	}
}

void	read_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->cub_height)
	{
		if (ft_strncmp(game->cub[i], "NO ", 3) == 0)
			game->textures.north = ft_strdup(game->cub[i] + 3);
		else if (ft_strncmp(game->cub[i], "SO ", 3) == 0)
			game->textures.south = ft_strdup(game->cub[i] + 3);
		else if (ft_strncmp(game->cub[i], "WE ", 3) == 0)
			game->textures.west = ft_strdup(game->cub[i] + 3);
		else if (ft_strncmp(game->cub[i], "EA ", 3) == 0)
			game->textures.east = ft_strdup(game->cub[i] + 3);
		else if (ft_strncmp(game->cub[i], "F ", 2) == 0)
			game->textures.floor_str = ft_strdup(game->cub[i] + 2);
		else if (ft_strncmp(game->cub[i], "C ", 2) == 0)
			game->textures.ceiling_str = ft_strdup(game->cub[i] + 2);
		i++;
	}
}
