/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:34 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/27 17:49:17 by avoronko         ###   ########.fr       */
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

bool	is_wall(t_game *game, double x, double y)
{
	int	i_x;
	int	i_y;

	i_x = (int)x;
	i_y = (int)y;
	if (i_x >= 0 && i_x < game->map_width && i_y >= 0 && i_y < game->map_height)
		return (game->map[i_y][i_x] == '1');
	return (true);
}

bool	is_valid_pos(t_game *game, double x, double y)
{
	int	i_x;
	int	i_y;

	i_x = (int)x;
	i_y = (int)y;
	if (i_x < 0.25 || i_x >= (game->map_width - 1.25)
		|| i_y < 0.25 || i_y > (game->map_height - 0.25))
		return (false);
	if (is_wall(game, x, y))
		return (false);
	return (true);
}
