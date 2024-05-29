/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:34 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/29 10:55:21 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	wall_orientation(t_game *game)
{
	if (game->ray.vertical_wall)
	{
		if (game->ray.dir_x > 0)
			game->ray.orientation = WE;
		else
			game->ray.orientation = EA;
	}
	else
	{
		if (game->ray.dir_y > 0)
			game->ray.orientation = NO;
		else
			game->ray.orientation = SO;
	}
}

bool	is_wall(t_game *game, int x, int y)
{
	if (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height)
		return (game->map[y][x] == '1');
	return (false);
}
