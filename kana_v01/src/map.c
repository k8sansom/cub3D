/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:48:52 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/07 11:54:59 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	adding_rows(t_game *game, char *row)
{
	char	**temp;
	int		i;

	i = 0;
	if (!row)
		return (0);
	game->map_height++;
	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!temp)
		full_exit("Error: allocating memory for map", game, game->exit_code++);
	temp[game->map_height] = NULL;
	while (i < (game->map_height - 1))
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = row;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

void read_map(t_game *game, char *map)
{
	char	*row;

	row = NULL;
	if (ft_isdir(map))
		full_exit("Error: file is a directory", game, STDERR_FILENO);
	game->fd = open(map, O_RDONLY);
	if (game->fd < 0)
		full_exit("Error: reading map", game, STDERR_FILENO);
	while (1)
	{
		row = get_next_line(game->fd);
		if (!adding_rows(game, row))
			break ;
	}
	close(game->fd);
	//game->map_width = ft_get_width(game->map[0]);
}
