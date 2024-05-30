/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/30 13:33:09 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_raycasting(t_game *game, int current_x)
{
	double	camera_x;

	ft_memset(&game->ray, 0, sizeof(t_ray));
	camera_x = 2 * current_x / (double)WIN_WIDTH - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
	game->ray.pos_x = (int)game->player.pos_x;
	game->ray.pos_y = (int)game->player.pos_y;
}

void	set_steps(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->ray.pos_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.pos_x + 1.0
				- game->player.pos_x) * game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->ray.pos_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.pos_y + 1.0 - game->player.pos_y)
			* game->ray.delta_dist_y;
	}
}

void	perform_dda(t_game *game)
{
	game->ray.hit_wall = false;
	game->wall.vertical_wall = false;
	while (!game->ray.hit_wall)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.pos_x += game->ray.step_x;
			game->wall.vertical_wall = true;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.pos_y += game->ray.step_y;
			game->wall.vertical_wall = false;
		}
		if (game->ray.pos_y < 0.25 || game->ray.pos_x < 0.25
			|| game->ray.pos_y > game->map_height - 0.25
			|| game->ray.pos_x > game->map_width - 1.25)
			break ;
		if (is_wall(game, game->ray.pos_x, game->ray.pos_y))
		{
			game->ray.hit_wall = true;
		}
	}
}

void	calculate_wall(t_game *game)
{
	int	win_height;

	win_height = WIN_HEIGHT;
	if (game->wall.vertical_wall)
		game->wall.wall_dist = (game->ray.side_dist_x - game->ray.delta_dist_x);
	else
		game->wall.wall_dist = (game->ray.side_dist_y - game->ray.delta_dist_y);
	game->wall.line_height = (int)(win_height / game->wall.wall_dist);
	game->wall.draw_start = -(game->wall.line_height) / 2 + win_height / 2;
	if (game->wall.draw_start < 0)
		game->wall.draw_start = 0;
	game->wall.draw_end = (game->wall.line_height / 2 + win_height / 2);
	if (game->wall.draw_end >= win_height)
		game->wall.draw_end = win_height - 1;
	wall_orientation(game);
	calculate_texture(game);
}

void	raycasting(t_game *game)
{
	int		current_x;

	current_x = 0;
	while (current_x < WIN_WIDTH)
	{
		init_raycasting(game, current_x);
		set_steps(game);
		perform_dda(game);
		calculate_wall(game);
		draw_vertical_line(game, current_x);
		current_x++;
	}
}
