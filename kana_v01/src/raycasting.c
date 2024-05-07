/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/07 12:44:02 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_wall(int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return (1);
	return (game->map[y][x] == '1');
}
/**
 * @brief initializing variables needed for casting
 *  a single ray form players current position.
 * @param camera_x used to calculate x-coordinate in the camera's view,
 * if its negative the ray points to the left, if positive - to the right.
 * @param dir_x and ->
 * @param dir_y is the direction the player is facing.
 * @param plane_x and ->
 * @param plane_y is the vector that is perpendicular to the direction;
 * @param delta_dist_x and ->
 * @param delta_dist_y is the distance that the ray needs to travel along
 * one of the axes to the next grid line;
 * the player is facing;
*/
static void	init_ray(t_game *game, int current_x)
{
	double	camera_x;

	game->current_column = current_x;
	/*convert the column number current_x into a range between -1 and 1;
	basically, how far from the center of the player's view 
	the ray should be cast (the angle of the ray)*/
	camera_x = 2 * current_x / (double)game->map_width - 1;
	/*calculate the direction of the ray by adding a portion 
	of the camera plane's x and y components*/
	game->ray_dir_x = game->dir_x + game->plane_x * camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * camera_x;
	/*calculate the  distance the ray must travel to move
	1 unit along the x or y axis in the map grid;
	
	If the direction component is 0 we set the distance to 
	a very large number 1e30 to prevent advancing in that direction
	
	if ray dir is not 0 calculations determine how much distance
	the ray needs to go to cross one grid cell in x or y direction.
	
	1 / game->ray_dir_x(y) gives the reciprocal of the ray's direction
	component. Fabs is to make sure the number is positive regardless 
	of the ray's direction*/
	if (game->ray_dir_x == 0)
		game->delta_dist_x = 1e30;
	else
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = 1e30;
	else
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
}

static void	perform_dda(t_game *game)
{
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;

	if (game->ray_dir_x < 0)
		step_x = -1;
	else
		step_x = 1;

	if (game->ray_dir_y < 0)
		step_y = -1;
	else
		step_y = 1;
	game->hit_wall = false;
	while (!game->hit_wall)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += game->delta_dist_x;
			game->player_x += step_x;
			game->current_column = 0;
		}
		else
		{
			side_dist_y += game->delta_dist_y;
			game->player_y += step_y;
			game->current_column = 1;
		}
		if (is_wall(game->player_x, game->player_y, game))
		{
			game->hit_wall = true;
			if (game->current_column == 0)
				game->wall_dist = (game->player_x - game->player_x + (1 - step_x) / 2) / game->ray_dir_x;
			else
				game->wall_dist = (game->player_y - game->player_y + (1 - step_y) / 2) / game->ray_dir_y;
		}
	}
}

void	raycasting(t_game *game)
{
	int	current_x;

	current_x = 0;
	while (current_x < game->map_width)
	{
		init_ray(game, current_x);
		perform_dda(game);
		draw_vertical_line(current_x, game->wall_dist, game);
		current_x++;
	}
}

void	draw_vertical_line(int x, double wall_dist, t_game *game)
{
	int	line_height;

	line_height = (int)(game->map_height / wall_dist);
	
}


