/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/17 11:29:09 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	handle_key_press(t_game *game, int key)
{
	if (key == KEY_ESC)
		ft_exit("Giving up?!", game, 0);
	else if (key == KEY_W)
		game->player.move_y = 1;
	else if (key == KEY_S)
		game->player.move_y = -1;
	else if (key == KEY_A)
		game->player.move_x = -1;
	else if (key == KEY_D)
		game->player.move_x = 1;
	else if (key == KEY_LEFT)
		game->player.rotate -= 1;
	else if (key == KEY_RIGHT)
		game->player.rotate += 1;
}

void	handle_key_release(t_game *game, int key)
{
	if (key == KEY_W)
	{
		if (game->player.move_y == 1)
			game->player.move_y = 0;
	}
	else if (key == KEY_S)
	{
		if (game->player.move_y == -1)
			game->player.move_y = 0;
	}
	else if (key == KEY_A)
	{
		if (game->player.move_x == -1)
			game->player.move_x = 0;
	}
	else if (key == KEY_D)
	{
		if (game->player.move_x == 1)
			game->player.move_x = 0;
	}
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		game->player.rotate = 0;
}

void	input_handler(t_game *game)
{
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, quit_cub3d, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press_handler, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release_handler, game);
}
