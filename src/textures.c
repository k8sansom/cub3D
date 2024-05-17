/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:41:55 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/17 12:22:07 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

size_t	convert_rgb(int *tab)
{
	size_t	result;
	int		r;
	int		g;
	int		b;

	r = tab[0];
	g = tab[1];
	b = tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
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

int	*get_rgbs(t_game *game, char *str)
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

void	read_textures(t_game *game)
{
	int	i;

	i = -1;
	while (game->cub[++i])
	{
		if (ft_strncmp(game->cub[i], "NO ", 3) == 0)
		{			
			if (game->textures.north)
				full_exit("Error: duplicate texture", game, 2);
			game->textures.north = ft_strdup(game->cub[i] + 3);
		}
		else if (ft_strncmp(game->cub[i], "SO ", 3) == 0 )
		{
			if (game->textures.south)
				full_exit("Error: duplicate texture", game, 2);
			game->textures.south = ft_strdup(game->cub[i] + 3);
		}
		else if (ft_strncmp(game->cub[i], "WE ", 3) == 0)
		{
			if (game->textures.west)
				full_exit("Error: duplicate texture", game, 2);
			game->textures.west = ft_strdup(game->cub[i] + 3);
		}
		else if (ft_strncmp(game->cub[i], "EA ", 3) == 0)
		{
			if (game->textures.east)
				full_exit("Error: duplicate texture", game, 2);
			game->textures.east = ft_strdup(game->cub[i] + 3);
		}
		else if (ft_strncmp(game->cub[i], "F ", 2) == 0)
		{
			if (game->textures.floor_str)
				full_exit("Error: duplicate texture", game, 2);
			game->textures.floor_str = ft_strdup(game->cub[i] + 2);
		}
		else if (ft_strncmp(game->cub[i], "C ", 2) == 0)
		{
			if (game->textures.ceiling_str)
				full_exit("Error: duplicate texture", game, 2);
			game->textures.ceiling_str = ft_strdup(game->cub[i] + 2);
		}
	}
}
