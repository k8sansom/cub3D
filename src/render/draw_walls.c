/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:20:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/17 13:17:28 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_vertical_line(t_game *game, int x)
{
	int	draw_start;
	int	draw_end;
	int	y;

	draw_start = game->wall.draw_start;
	draw_end = game->wall.draw_end;
	y = draw_start;
	while (y < draw_end)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, mlx_get_color_value(game->mlx_ptr, ...));
		y++;
	}
}


void	calculate_line(int x, t_game *game)
{
	if (game->ray.wall_dist <= 0)
	{
		game->wall.line_height = game->map_height;
		game->wall.draw_start = 0;
		game->wall.draw_end = game->map_height - 1;
	}
	else
	{
		game->wall.line_height = (int)(game->map_height / game->ray.wall_dist);
		game->wall.draw_start = (game->map_height - game->wall.line_height) / 2;
		game->wall.draw_end = game->wall.draw_start + game->wall.line_height;
		if (game->wall.draw_start < 0)
			game->wall.draw_start = 0;
		if (game->wall.draw_end >= game->map_height)
			game->wall.draw_end = game->map_height - 1;
	}
	if (game->wall.draw_start > game->wall.draw_end)
	{
		game->wall.draw_start = (game->map_height - 1) / 2;
		game->wall.draw_end = game->wall.draw_start + 1;
	}
}