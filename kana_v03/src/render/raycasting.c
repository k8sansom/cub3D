/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/23 13:09:47 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_ray(t_game *game, int current_x)
{
	double	camera_x;

	game->ray.current_column = current_x;
	camera_x = 2 * current_x / (double)WIN_WIDTH - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	if (game->ray.dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	if (game->ray.dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
}

void	set_steps(t_game *game)
{
	/*
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
	}*/
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->ray.pos_x - floor(game->ray.pos_x))
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (ceil(game->ray.pos_x)
				- game->ray.pos_x) * game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->ray.pos_y - floor(game->ray.pos_y))
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (ceil(game->ray.pos_y) - game->ray.pos_y)
			* game->ray.delta_dist_y;
	}
}

void	perform_dda(t_game *game)
{
	game->ray.pos_x = game->player.pos_x;
	game->ray.pos_y = game->player.pos_y;
	set_steps(game);
	game->ray.hit_wall = false;
	game->ray.vertical_wall = false;
	while (!game->ray.hit_wall)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.pos_x += game->ray.step_x;
			game->ray.vertical_wall = true;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.pos_y += game->ray.step_y;
			game->ray.vertical_wall = false;
		}
		if (is_wall(game))
			game->ray.hit_wall = true;
	}
}

void	calculate_wall(t_game *game)
{
	if (game->ray.vertical_wall)
		game->ray.wall_dist = fabs((game->ray.pos_x - game->player.pos_x)
				/ game->ray.dir_x);
	//	game->ray.wall_dist = game->ray.side_dist_x - game->ray.delta_dist_x;
	else
		game->ray.wall_dist = fabs((game->ray.pos_y - game->player.pos_y)
				/ game->ray.dir_y);
		//game->ray.wall_dist = game->ray.side_dist_y - game->ray.delta_dist_y;
	/*game->ray.line_height = (int)(WIN_HEIGHT / game->ray.wall_dist);
	game->ray.draw_start = -(game->ray.line_height) / (2 + WIN_HEIGHT) / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / (2 + WIN_HEIGHT) / 2;
	if (game->ray.draw_end >=WIN_HEIGHT)
		game->ray.draw_end = WIN_HEIGHT - 1;
	*/
	game->ray.line_height = (int)(game->map_height / game->ray.wall_dist);
	game->ray.draw_start = (game->map_height - game->ray.line_height) / 2;
	game->ray.draw_end = game->ray.draw_start + game->ray.line_height;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	if (game->ray.draw_end >= game->map_height)
		game->ray.draw_end = game->map_height - 1;
	if (game->ray.draw_start > game->ray.draw_end)
	{
		game->ray.draw_start = (game->map_height - 1) / 2;
		game->ray.draw_end = game->ray.draw_start + 1;
	}
	wall_orientation(game);
}
