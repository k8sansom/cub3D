/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:20:29 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/20 18:59:34 by avoronko         ###   ########.fr       */
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
		pixel = (int *)(game->image.img_data + y
				* game->image.size_line / 4 + x);
		pixel = &color;
		y++;
	}
}

int	get_wall_color(t_game *game)
{
	if (game->ray.orientation == 'N')
		return (COLOR_NORTH);
	else if (game->ray.orientation == 'S')
		return (COLOR_SOUTH);
	else if (game->ray.orientation == 'E')
		return (COLOR_EAST);
	else if (game->ray.orientation == 'W')
		return (COLOR_WEST);
	else
		return (0xFFFFFF);
}

void	render_floor_and_ceiling(t_game *game)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < game->win_height)
	{
		if (y < game->win_height / 2)
			color = COLOR_CEILING;
		else
		{
			color = COLOR_FLOOR;
		}
		x = 0;
		while (x < game->win_width)
		{
			*(int *)(game->image.img_data + y
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
			game->ray.orientation = 'W';
		else
			game->ray.orientation = 'E';
	}
	else
	{
		if (game->ray.dir_y > 0)
			game->ray.orientation = 'N';
		else
			game->ray.orientation = 'S';
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
