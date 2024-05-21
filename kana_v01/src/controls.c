/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/21 12:23:38 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	key_press(t_game *game, int key)
{
	if (key == KEY_ESC)
		full_exit("Giving up?!", game, 0);
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

static void	key_release(t_game *game, int key)
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

static void	use_mouse(int x, int y, t_game *game)
{
	static int	old_x;
	static int	old_y;
	static int	init;
	int			delta_x;

	if (!init)
	{
		old_x = WIN_WIDTH / 2;
		old_y = WIN_HEIGHT / 2;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, old_x, old_y);
		init = 1;
		return ;
	}
	delta_x = x - old_x;
	if (delta_x)
		game->player.rotate += delta_x * MOUSE_S;
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, old_x, old_y);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, full_exit, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, use_mouse, game);
	mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
}
