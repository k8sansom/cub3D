/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:51:22 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/10 12:37:22 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_wall(t_game *game)
{
	if (game->ray.pos_x < 0 || game->ray.pos_x >= game->map_width
		|| game->ray.pos_y < 0 || game->ray.pos_y >= game->map_height)
		return (1);
	return (game->map[(int)game->ray.pos_y][(int)game->ray.pos_x] == '1');
}
/**
 * @brief sets up a ray based on its position across the screen.
 * Adjusts the ray's direction to create a field of view. 
 * Calculates how far the ray needs to travel to cross a grid line.
 * @param camera_x used to calculate x-coordinate in the camera's view,
 * if its negative the ray points to the left, if positive - to the right.
 * @param dir is the direction the player is facing.
 * @param plane is the vector that is perpendicular to the direction;
 * @param delta_dist is the distance that the ray needs to travel along
 * one of the axes to the next grid line;
 * the player is facing;
*/
static void	init_ray(t_game *game, int current_x)
{
	double	camera_x;

	game->ray.current_column = current_x;
	/*convert the column number current_x into a range between -1 and 1;
	basically, how far from the center of the player's view 
	the ray should be cast (the angle of the ray)*/
	camera_x = 2 * current_x / (double)game->map_width - 1;
	/*calculate the direction of the ray by adding a portion 
	of the camera plane's x and y components*/
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	/*calculate the  distance the ray must travel to move
	1 unit along the x or y axis in the map grid;
	
	If the direction component is 0 we set the distance to 
	a very large number 1e30 to prevent advancing in that direction
	
	if ray dir is not 0 calculations determine how much distance
	the ray needs to go to cross one grid cell in x or y direction.
	
	1 / game->ray_dir_x(y) gives the reciprocal of the ray's direction
	component. Fabs is to make sure the number is positive regardless 
	of the ray's direction*/
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
 * @brief The ray travels through the game field, using delta_distances calculated
 * int init ray. When the ray hits the wall we calculate the perpendicular distance
 * to it from the ray's initial position.
 * @param side_dist is the distance the ray needs to travel to reach the
 * next x or y grid line from its current position.
 * @param step is a direction indicator. They increase if the direction is 
 * right or up and decreases if the direction is left or down.
 * @param wall_dist is the perpendicular distance from the player to the wall.
*/
static void	perform_dda(t_game *game)
{
	bool	vertical_wall;
//set the ray's initial position as it will be advancing towards walls
	game->ray.pos_x = game->player.pos_x;
	game->ray.pos_y = game->player.pos_y;
/* game->ray_pos_x - floor(game->ray_pos_x) computes the fractional part of the x-coordinate, 
its how far the current position is from the leftward nearest grid line.
Mult. by game->delta_dist_x scales this fractional distance to the map grid.
floor - rounds down to the nearest integer */
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->ray.pos_x - floor(game->ray.pos_x)) * game->ray.delta_dist_x;
	}
// ceil(game->ray_pos_x) - game->ray_pos_x is how far the curr position is from the next rightward grid line
// ceil - rounds up to the nearest int
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (ceil(game->ray.pos_x) - game->ray.pos_x) * game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->ray.pos_y - floor(game->ray.pos_y)) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (ceil(game->ray.pos_y) - game->ray.pos_y) * game->ray.delta_dist_y;
	}
	game->ray.hit_wall = false;
	while (!game->ray.hit_wall)
	{
		/*First advances to the axis, where the ray will hit the
		grid line first.
		Increments the side distance by delta (distance to the NEXT line)
		each time.*/
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
		/*Calculates the distance to the wall when it's hit. 
		Its a perpedicular distance from the player position (the ray's starting
		point to the wall. )*/
		
		if (is_wall(game))
		{
			game->ray.hit_wall = true;
	// if the ray hits a vertical wall
			if (vertical_wall)
				game->ray.wall_dist = fabs((game->ray.pos_x - game->player.pos_x) / game->ray.dir_x);
	// if the ray hits the horizontal wall
			else
				game->ray.wall_dist = fabs((game->ray.pos_y - game->player.pos_y) / game->ray.dir_y);
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
		draw_vertical_line(current_x, game->ray.wall_dist, game);
		current_x++;
	}
}

void	draw_vertical_line(int x, double wall_dist, t_game *game)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	
	line_height = (int)(game->map_height / wall_dist);

	draw_start = (game->map_height - line_height) / 2;
	draw_end  = draw_start + line_height;

	if (draw_start < 0) draw_start = 0;
	if (draw_end >= game->map_height) draw_end = game->map_height - 1;
	
}


