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

static int	*get_rgbs(t_game *game, char *str)
{
	char	**rgb_arr;
	int		*rgb;
	int		i;

	rgb_arr = ft_split(str, ',');
	i = 0;
	while (rgb_arr[i])
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

	i = 0;
	while (i < game->cub_height)
	{
		if (ft_strncmp(game->cub_file[i], "NO ", 3) == 0)
			game->textures.north = ft_strdup(game->cub_file[i] + 3);
		else if (ft_strncmp(game->cub_file[i], "SO ", 3) == 0)
			game->textures.south = ft_strdup(game->cub_file[i] + 3);
		else if (ft_strncmp(game->cub_file[i], "WE ", 3) == 0)
			game->textures.west = ft_strdup(game->cub_file[i] + 3);
		else if (ft_strncmp(game->cub_file[i], "EA ", 3) == 0)
			game->textures.east = ft_strdup(game->cub_file[i] + 3);
		else if (ft_strncmp(game->cub_file[i], "F ", 2) == 0)
			game->textures.floor = get_rgbs(game, game->cub_file[i] + 2);
		else if (ft_strncmp(game->cub_file[i], "C ", 2) == 0)
			game->textures.ceiling = get_rgbs(game, game->cub_file[i] + 2);
		i++;
	}
}
