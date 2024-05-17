/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/17 13:13:06 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_ray(t_game *game, int current_x)
{
	double	camera_x;

	game->ray.current_column = current_x;
	camera_x = 2 * current_x / (double)game->map_width - 1;
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

static void	set_steps(t_game *game)
{
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

static void	perform_dda(t_game *game)
{
	bool	vertical_wall;

	game->ray.pos_x = game->player.pos_x;
	game->ray.pos_y = game->player.pos_y;
	set_steps(game);
	game->ray.hit_wall = false;
	while (!game->ray.hit_wall)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.pos_x += game->ray.step_x;
			vertical_wall = true;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.pos_y += game->ray.step_y;
			vertical_wall = false;
		}
		if (is_wall(game))
			calculate_wall_distance(game, vertical_wall);
	}
}

static void	calculate_wall_distance(t_game *game, bool vertical_wall)
{
	int	tex_x;

	game->ray.hit_wall = true;
	if (vertical_wall)
	{
		game->ray.wall_dist = fabs((game->ray.pos_x - game->player.pos_x)
				/ game->ray.dir_x);
		game->ray.wall_pos = game->ray.pos_y + game->ray.wall_dist
			* game->ray.dir_y;
	}
	else
	{
		game->ray.wall_dist = fabs((game->ray.pos_y - game->player.pos_y)
				/ game->ray.dir_y);
		game->ray.wall_pos = game->ray.pos_x + game->ray.wall_dist
			* game->ray.dir_x;
	}
	game->ray.wall_pos -= floor(game->ray.wall_pos);
	tex_x = (int)(game->ray.wall_pos * (double)(game->textures.width));
	if ((vertical_wall && game->ray.dir_x > 0)
		|| (!vertical_wall && game->ray.dir_y < 0))
		tex_x = game->textures.width - tex_x - 1;
	game->wall.texture_x = tex_x;
}

void	raycasting(t_game *game)
{
	int	current_x;

	current_x = 0;
	game->ray.current_column = 0;
	while (current_x < game->map_width)
	{
		init_ray(game, current_x);
		perform_dda(game);
		calculate_line(current_x, game);
		current_x++;
		game->ray.current_column++;
	}
}
