/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:13:49 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/25 21:42:26 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	handle_rotation(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	int		rotspeed;

	rotspeed = ROTSPEED * game->player.rotate;
	if (game->player.rotate)
	{
		old_dir_x = game->player.dir_x;
		old_plane_x = game->player.plane_x;
		game->player.dir_x = game->player.dir_x * cos(rotspeed)
			- game->player.dir_y * sin(rotspeed);
		game->player.dir_y = old_dir_x * sin(rotspeed)
			+ game->player.dir_y * cos(rotspeed);
		game->player.plane_x = old_plane_x * cos(rotspeed)
			- game->player.plane_y * sin(rotspeed);
		game->player.plane_y = old_dir_x * sin(rotspeed)
			+ game->player.plane_y * cos(rotspeed);
		game->player.rotate = 0;
	}
	game->player.has_moved = 1;
}
