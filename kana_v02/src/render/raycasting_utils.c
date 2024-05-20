/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:34 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/20 18:53:45 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_wall(t_game *game)
{
	if (game->ray.pos_x < 0 || game->ray.pos_x >= game->map_width
		|| game->ray.pos_y < 0 || game->ray.pos_y >= game->map_height)
		return (1);
	return (game->map[(int)game->ray.pos_y][(int)game->ray.pos_x] == '1');
}

bool	is_valid_pos(t_game *game, double x, double y)
{
	if (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height)
		return (game->map[(int)y][(int)x] != '0');
	return (true);
}
