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

static bool	is_dir(char *map)
{
	int		fd;

	fd = open(map, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (true);
	}
	return (false);
}
void read_map(t_game *game, char *map)
{
	if (is_dir(map))
		full_exit("Error: file is a directory", game);
	game->fd = open(map, O_RDONLY);
	if (game->fd < 0)
		ft_exit("Error: reading map", game, game->exit_code++);
	while (1)
	{
		row = get_next_line(game->fd);
		if (!ft_adding_rows(game, row))
			break ;
	}
	close(game->fd);
	game->map_width = ft_get_width(game->map[0]);
}