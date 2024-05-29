/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:34 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/29 14:07:35 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	wall_orientation(t_game *game)
{
	if (game->wall.vertical_wall)
	{
		if (game->ray.dir_x > 0)
			game->wall.orientation = WE;
		else
			game->wall.orientation = EA;
	}
	else
	{
		if (game->ray.dir_y > 0)
			game->wall.orientation = NO;
		else
			game->wall.orientation = SO;
	}
}

void	calculate_texture(t_game *game)
{
	if (game->wall.vertical_wall)
		game->wall.tex_x = (int)((game->player.pos_y + game->wall.wall_dist
					* game->ray.dir_y) * TILE_SIZE) % TILE_SIZE;
	else
		game->wall.tex_x = (int)((game->player.pos_x + game->wall.wall_dist
					* game->ray.dir_x) * TILE_SIZE) % TILE_SIZE;
	if ((game->wall.vertical_wall && game->ray.dir_x > 0)
		|| (!game->wall.vertical_wall && game->ray.dir_y < 0))
		game->wall.tex_x = TILE_SIZE - game->wall.tex_x - 1;
	game->wall.step = TILE_SIZE / (double)game->wall.line_height;
	game->wall.tex_pos = (game->wall.draw_start - WIN_HEIGHT / 2
			+ game->wall.line_height / 2)
		* (TILE_SIZE / (double)game->wall.line_height);
	game->wall.tex_y = ((int)game->wall.tex_pos) % TILE_SIZE;
}

bool	is_wall(t_game *game, int x, int y)
{
	if (x >= 0 && x < game->map_width && y >= 0 && y < game->map_height)
		return (game->map[y][x] == '1');
	return (false);
}
