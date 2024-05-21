/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:20:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/21 12:22:25 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_vertical_line(t_game *game, int x)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	color;
	int	*pixel;

	color = get_wall_color(game);
	draw_start = game->wall.draw_start;
	draw_end = game->wall.draw_end;
	y = draw_start;
	while (y < draw_end)
	{
		pixel = (int *)(game->image.img_addr + y
				* game->image.size_line / 4 + x);
		pixel = &color;
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

void	render_floor_and_ceiling(t_game *game)
{
	int		y;
	int		x;
	size_t	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = game->textures.hex_ceiling;
		else
		{
			color = game->textures.hex_floor;
		}
		x = 0;
		while (x < WIN_WIDTH)
		{
			*(int *)(game->image.img_addr + y
					* game->image.size_line / 4 + x) = color;
			x++;
		}
		y++;
	}
}

void	wall_orientation(t_game *game, bool vertical_wall)
{
	if (vertical_wall)
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

void	calculate_line(t_game *game)
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
