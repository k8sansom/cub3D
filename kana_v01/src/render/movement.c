/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:44:42 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/17 10:19:33 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	move_forward(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
}

static void	move_backward(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
}

static void	move_left(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos_x - game->player.plane_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.plane_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
}

static void	move_right(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos_x + game->player.plane_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.plane_y * MOVESPEED;
	if (is_valid_pos(game, new_x, new_y))
	{
		game->player.pos_x = new_x;
		game->player.pos_y = new_y;
		game->player.has_moved = 1;
	}
}

void	handle_movement(t_game *game)
{
	if (!game->player.has_moved)
	{
		if (game->player.move_y == 1)
			move_player_forward(game);
		if (game->player.move_y == -1)
			move_player_backward(game);
		if (game->player.move_x == 1)
			move_player_right(game);
		if (game->player.move_x == -1)
			move_player_left(game);
	}
}
