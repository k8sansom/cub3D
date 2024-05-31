/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:20:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/31 14:15:54 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_pixel(t_game *game, int x, int y, int color)
{
	int	pixel_index;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pixel_index = y * (game->image.size_line / 4) + x;
		if (pixel_index >= 0 && pixel_index < (WIN_WIDTH * WIN_HEIGHT))
			game->image.img_addr[pixel_index] = color;
	}
}

void	draw_vertical_line(t_game *game, int x)
{
	double		y;
	int			color;
	int			location;

	y = game->wall.draw_start;
	while (y <= game->wall.draw_end)
	{
		game->wall.tex_y = ((int)game->wall.tex_pos) % TILE_SIZE;
		location = game->wall.tex_y * TILE_SIZE + game->wall.tex_x;
		color = get_wall_color(game, location);
		set_pixel(game, x, y, color);
		game->wall.tex_pos += game->wall.step;
		y++;
	}
}

int	get_wall_color(t_game *game, int location)
{
	if (location < 0 || location >= TILE_SIZE * TILE_SIZE)
		return (0xFFFFFF);
	return (game->texture_arr[game->wall.orientation][location]);
}
