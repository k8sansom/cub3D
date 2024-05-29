/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:20:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/29 11:59:21 by ksansom          ###   ########.fr       */
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
	int	location;

	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		location = y * game->textures.size + x;
		color = get_wall_color(game, location);
		set_pixel(game, x, y, color);
		y++;
	}
}

int	get_wall_color(t_game *game, int location)
{
	if (game->ray.orientation == NO)
		return (game->texture_arr[NO][location]);
	else if (game->ray.orientation == SO)
		return (game->texture_arr[SO][location]);
	else if (game->ray.orientation == EA)
		return (game->texture_arr[EA][location]);
	else
		return (game->texture_arr[WE][location]);
	// else
	// 	return (0xFFFFFF);
}

