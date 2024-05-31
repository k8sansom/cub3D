/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/30 11:18:24 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		full_exit("All done?!", game, NO_ERR);
	if (key == XK_Left)
		game->player.rotate -= 1;
	if (key == XK_Right)
		game->player.rotate += 1;
	if (key == XK_w)
		game->player.move_y = 1;
	if (key == XK_a)
		game->player.move_x = -1;
	if (key == XK_s)
		game->player.move_y = -1;
	if (key == XK_d)
		game->player.move_x = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == XK_Escape)
		full_exit("All done?!", game, NO_ERR);
	if (key == XK_w && game->player.move_y == 1)
		game->player.move_y = 0;
	else if (key == XK_s && game->player.move_y == -1)
		game->player.move_y = 0;
	else if (key == XK_a && game->player.move_x == -1)
		game->player.move_x += 1;
	else if (key == XK_d && game->player.move_x == 1)
		game->player.move_x -= 1;
	else if ((key == XK_Left || key == XK_Right) && game->player.rotate)
		game->player.rotate = 0;
	return (0);
}

/*static int	use_mouse(int x, int y, t_game *game)
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
		return (0);
	}
	delta_x = x - old_x;
	if (delta_x)
		game->player.rotate += delta_x * MOUSE_S;
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, old_x, old_y);
	return (0);
}*/

void	set_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, quit_game, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
}
//	mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, use_mouse, game);
//	mlx_mouse_hide(game->mlx_ptr, game->win_ptr);