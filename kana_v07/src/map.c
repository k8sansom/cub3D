/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:48:52 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/31 10:57:08 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	make_map_square(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) < (size_t)game->map_width)
		{
			game->map[i] = ft_realloc((void *)game->map[i], \
				ft_strlen(game->map[i]) + 1, game->map_width + 1);
			j = 0;
			while (game->map[i][j])
				j++;
			while (j < game->map_width)
			{
				game->map[i][j] = '1';
				j++;
			}
			game->map[i][j] = '\0';
		}
		i++;
	}
}

void	finalize_map_dimensions(t_game *game)
{
	int	current_length;

	game->map_height = 0;
	game->map_width = 0;
	while (game->map[game->map_height])
	{
		current_length = ft_strlen(game->map[game->map_height]);
		if (current_length > game->map_width)
			game->map_width = current_length;
		game->map_height++;
	}
}

void	copy_map(t_game *game, int start)
{
	int	i;
	int	size;

	i = 0;
	size = game->cub_height - start + 1;
	game->map = malloc(sizeof(char *) * size);
	while (game->cub[start])
	{
		if (game->cub[start + 1] == NULL)
			game->map[i] = ft_strdup(game->cub[start]);
		else
			game->map[i] = ft_strndup(game->cub[start], \
				ft_strlen(game->cub[start]) - 1);
		i++;
		start++;
	}
	game->map[i] = NULL;
	game->map_height = i;
}

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cub[i])
	{
		while (!ft_strncmp(game->cub[i], "NO ", 3) || !ft_strncmp(game->cub[i], \
				"SO ", 3) || !ft_strncmp(game->cub[i], "WE ", 3) || \
				!ft_strncmp(game->cub[i], "EA ", 3) || !ft_strncmp(\
				game->cub[i], "F ", 2) || !ft_strncmp(game->cub[i], "C ", 2))
		{
			i++;
			continue ;
		}
		j = 0;
		while (game->cub[i][j] && ft_strchr(WHITESPACE, game->cub[i][j]))
			j++;
		if (game->cub[i][j])
		{
			copy_map(game, i);
			break ;
		}
		i++;
	}
}
