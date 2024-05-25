/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/25 22:08:00 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_ray(t_game *game, int current_x)
{
	double	camera_x;

	camera_x = 2 * current_x / (double)WIN_WIDTH - 1;
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
	game->ray.pos_x = game->player.pos_x;
	game->ray.pos_y = game->player.pos_y;
	// printf("Init Ray: Column=%d, CameraX=%.3f, DirX=%.3f, DirY=%.3f, DeltaDistX=%.3f, DeltaDistY=%.3f, PlayerPosX=%.3f, PlayerPosY=%.3f\n",
	// 	current_x, camera_x, game->ray.dir_x, game->ray.dir_y, game->ray.delta_dist_x, game->ray.delta_dist_y, game->player.pos_x, game->player.pos_y);

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
	// printf("Set Steps: StepX=%d, StepY=%d, SideDistX=%.3f, SideDistY=%.3f, PosX=%.3f, PosY=%.3f\n",
	// 	game->ray.step_x, game->ray.step_y, game->ray.side_dist_x, game->ray.side_dist_y, game->ray.pos_x, game->ray.pos_y);

}

void	perform_dda(t_game *game)
{
	game->ray.hit_wall = false;
	game->ray.vertical_wall = false;
//	printf("Starting DDA Loop\n");
	// printf("Initial Position: PosX=%.3f, PosY=%.3f\n", game->ray.pos_x, game->ray.pos_y);
	// printf("Initial Side Distances: SideDistX=%.3f, SideDistY=%.3f\n", game->ray.side_dist_x, game->ray.side_dist_y);
	while (!game->ray.hit_wall)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.pos_x += game->ray.step_x;
			game->ray.vertical_wall = true;
	//		printf("Move Horizontally: New PosX=%.3f, Updated SideDistX=%.3f\n", game->ray.pos_x, game->ray.side_dist_x);
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.pos_y += game->ray.step_y;
			game->ray.vertical_wall = false;
	//		printf("Move Vertically: New PosY=%.3f, Updated SideDistY=%.3f\n", game->ray.pos_y, game->ray.side_dist_y);
		}
		if (game->ray.pos_y < 0.25 || game->ray.pos_x < 0.25
			|| game->ray.pos_y > game->map_height - 0.25
			|| game->ray.pos_x > game->map_width - 1.25)
        	break ;
		if (is_wall(game))
		{
	//		printf("Hit Wall at PosX=%.3f, PosY=%.3f\n", game->ray.pos_x, game->ray.pos_y);
			game->ray.hit_wall = true;
		}
	}
}

void	calculate_wall(t_game *game)
{
	int	win_height;

	win_height = WIN_HEIGHT;
	if (game->ray.vertical_wall)
		game->ray.wall_dist = (game->ray.side_dist_x - game->ray.delta_dist_x);
	else
		game->ray.wall_dist = (game->ray.side_dist_y - game->ray.delta_dist_y);
	// printf("Calculate Wall Distance: WallDist=%.3f, VerticalWall=%d\n",
	// 	game->ray.wall_dist, game->ray.vertical_wall);
	game->ray.line_height = (int)(win_height / game->ray.wall_dist);
	game->ray.draw_start = -(game->ray.line_height) / 2 + win_height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = (game->ray.line_height / 2 + win_height / 2);
	if (game->ray.draw_end >= win_height)
		game->ray.draw_end = win_height - 1;
	// printf("Calculate Line: LineHeight=%d, DrawStart=%d, DrawEnd=%d\n",
	// 	game->ray.line_height, game->ray.draw_start, game->ray.draw_end);
	wall_orientation(game);
}

void	raycasting(t_game *game)
{
	int		current_x;

	current_x = 0;
	while (current_x < WIN_WIDTH)
	{
		init_ray(game, current_x);
		set_steps(game);
		perform_dda(game);
		calculate_wall(game);
		draw_vertical_line(game, current_x);
		current_x++;
	}
}
