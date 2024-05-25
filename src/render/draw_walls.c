/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:20:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/25 20:11:36 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_pixel(t_game *game, int x, int y, int color)
{
	int	pixel_index;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pixel_index = y * (game->image.size_line / 4) + x;
		game->image.img_addr[pixel_index] = color;
	}
}

void	draw_vertical_line(t_game *game, int x)
{
	int	y;
	int	color;

	color = get_wall_color(game);
	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		set_pixel(game, x, y, color);
		y++;
	}
}

int	get_wall_color(t_game *game)
{
	if (game->ray.orientation == NO)
		return (0xFF0000/*game->texture_arr[NO]*/);
	else if (game->ray.orientation == SO)
		return (0x00FF00/*game->texture_arr[SO]*/);
	else if (game->ray.orientation == EA)
		return (0x0000FF/*game->texture_arr[EA]*/);
	else if (game->ray.orientation == WE)
		return (0xFFFF00/*game->texture_arr[WE]*/);
	else
		return (0xFFFFFF);
}

