/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/10 14:42:51 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief sets up a ray based on its position across the screen.
 * Adjusts the ray's direction to create a field of view. 
 * Calculates how far the ray needs to travel to cross a grid line.
 * @param camera_x the angle of the ray between -1 and 1 in the camera's view,
 * if its negative the ray points to the left, if positive - to the right.
 * @param dir is the direction the player is facing.
 * @param plane is the vector that is perpendicular to the direction;
 * @param delta_dist is the distance that the ray needs to travel along
 * one of the axes to the next grid line;
 * the player is facing;
 * @note Calculation of the ray's direction is adding a portion 
 * of the camera plane's x and y components to the player's position.
 * @note If the direction component is 0 we set the distance to 
 * a very large number 1e30 to prevent advancing in that direction.
 * @note If ray dir is not 0 calculations determine how much distance
 * the ray needs to go to cross one grid cell in x or y direction.
 * @note 1 / game->ray_dir_x(y) gives the reciprocal of the ray's direction component. 
 * @note Fabs is to make sure the number is positive regardless of the ray's direction.
*/
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

/**
 * @brief Sets direction of the incrementation steps based on the ray's direction.
 * @param side_dist is the distance the ray needs to travel to reach the
 * next x or y grid line from its current position.
 * @param step is a direction indicator. They increase if the direction is 
 * right or up and decreases if the direction is left or down.
 * @note ray.pos_x - floor(ray.pos_x) computes the fractional part of the x-coordinate, it's how far the current position is from the leftward nearest grid line.
 * @note Multiplied by delta_dist_x scales this fractional distance to the map grid.
 * @note ceil(ray.pos_x) - ray.pos_x is how far the curr position is from the next rightward grid line.
 * @note Floor - rounds down to the nearest integer.
 * @note Ceil - rounds up to the nearest integer.
*/
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

/**
 * @brief Digital Differential Analysis.
 * The ray travels through the game field, using delta_distances calculated
 * in init_ray function. When the ray hits the wall we calculate the perpendicular distance
 * to it from the ray's initial position.
 * @param ray_pos will be advancing towards walls from the initial (player's) position.
 * @param side_dist is the distance the ray needs to travel to reach the
 * next x or y grid line from its current position.
 * @param step is a direction indicator. They increase if the direction is 
 * right or up and decreases if the direction is left or down.
 * @param wall_dist is the perpendicular distance from the player to the wall.
 * @note First the ray advances to the axis, where it will hit the grid line first.
 * @note We increment the side distance by delta (distance to the next grid line) each time.
*/
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
	game->ray.hit_wall = true;
	if (vertical_wall)
		game->ray.wall_dist = fabs((game->ray.pos_x - game->player.pos_x)
				/ game->ray.dir_x);
	else
		game->ray.wall_dist = fabs((game->ray.pos_y - game->player.pos_y)
				/ game->ray.dir_y);
}

void	raycasting(t_game *game)
{
	int	current_x;

	current_x = 0;
	while (current_x < game->map_width)
	{
		init_ray(game, current_x);
		perform_dda(game);
		draw_vertical_line(current_x, game->ray.wall_dist, game);
		current_x++;
	}
}
