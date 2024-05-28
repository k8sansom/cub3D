/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:44:42 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/28 14:39:14 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	move_player_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVESPEED;
	return (valid_move(game, new_x, new_y));
}

static int	move_player_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVESPEED;
	return (valid_move(game, new_x, new_y));
}

static int	move_player_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVESPEED;
	new_y = game->player.pos_y - game->player.dir_x * MOVESPEED;
	return (valid_move(game, new_x, new_y));
}

static int	move_player_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * MOVESPEED;
	new_y = game->player.pos_y + game->player.dir_x * MOVESPEED;
	return (valid_move(game, new_x, new_y));
}

int	handle_movement(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move_y == 1)
		moved += move_player_forward(game);
	if (game->player.move_y == -1)
		moved += move_player_backward(game);
	if (game->player.move_x == -1)
		moved += move_player_left(game);
	if (game->player.move_x == 1)
		moved += move_player_right(game);
	if (game->player.rotate != 0)
		moved += handle_rotation(game, game->player.rotate);
	return (moved);
}

