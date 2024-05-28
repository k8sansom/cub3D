/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:44:42 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/27 17:54:48 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	printf("F: old player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
	new_x = game->player.pos_x + game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
	printf("F: new player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	printf("B: old player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
	new_x = game->player.pos_x - game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
	printf("B: new player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
}

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	printf("L: old player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
	new_x = game->player.pos_x - game->player.plane_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.plane_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
	printf("L: new player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	printf("R: old player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
	new_x = game->player.pos_x + game->player.plane_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.plane_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y; 
		game->player.has_moved = 1;
	}
	printf("R: new player pos x is %f, y is %f\n", game->player.pos_x, game->player.pos_y);
}

void	handle_movement(t_game *game)
{
	if (!game->player.has_moved)
	{
		if (game->player.move_y == 1)
			move_forward(game);
		if (game->player.move_y == -1)
			move_backward(game);
		if (game->player.move_x == 1)
			move_right(game);
		if (game->player.move_x == -1)
			move_left(game);
	}
}
