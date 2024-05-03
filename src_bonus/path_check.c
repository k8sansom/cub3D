/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:01:49 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/23 16:10:05 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long.h"

static void	ft_flood_fill(t_game *temp, int y, int x)
{
	if (temp->map[y][x] == '1' || y > (temp->map_height - 1) || y < 0 || \
		x > (temp->map_width - 1) || x < 0 || temp->map[y][x] == 'V')
		return ;
	if (temp->map[y][x] == 'C')
		temp->collectable_counter--;
	if (temp->map[y][x] == 'E')
	{
		temp->exit_counter = 1;
		return ;
	}
	temp->map[y][x] = '1';
	ft_flood_fill(temp, y + 1, x);
	ft_flood_fill(temp, y - 1, x);
	ft_flood_fill(temp, y, x + 1);
	ft_flood_fill(temp, y, x - 1);
}

void	ft_parse_path(t_game *game)
{
	t_game	temp;
	int		i;

	ft_memset(&temp, 0, sizeof(t_game));
	temp.map_height = game->map_height;
	temp.map_width = game->map_width;
	temp.collectable_counter = game->collectable_counter;
	temp.x_axis = game->x_axis;
	temp.y_axis = game->y_axis;
	temp.map = (char **)malloc(game->map_height * sizeof(char *));
	if (!temp.map)
		ft_exit("Error: allocating memory", game, game->exit_code++);
	i = 0;
	while (i < game->map_height)
	{
		temp.map[i] = ft_strdup(game->map[i]);
		i++;
	}
	ft_flood_fill(&temp, temp.y_axis, temp.x_axis);
	if (temp.exit_counter != 1 || temp.collectable_counter != 0)
	{
		ft_free(temp.map, game->map_height);
		ft_exit("Error: no valid path available", game, game->exit_code++);
	}
	ft_free(temp.map, game->map_height);
}
