/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/27 16:51:37 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		full_exit("Giving up?!", game, 0);
	if (key == KEY_W)
		game->player.move_y = 1;
	if (key == KEY_S)
		game->player.move_y = -1;
	if (key == KEY_A)
		game->player.move_x = -1;
	if (key == KEY_D)
		game->player.move_x = 1;
	if (key == KEY_LEFT)
		game->player.rotate -= 1;
	if (key == KEY_RIGHT)
		game->player.rotate += 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_ESC)
		full_exit("Giving up?!", game, 0);
	if (key == KEY_W && game->player.move_y == 1)
		game->player.move_y = 0;
	else if (key == KEY_S && game->player.move_y == -1)
		game->player.move_y = 0;
	else if (key == KEY_A && game->player.move_x == -1)
		game->player.move_x += 1;
	else if (key == KEY_D && game->player.move_x == 1)
		game->player.move_x -= 1;
	else if ((key == KEY_LEFT || key == KEY_RIGHT) && game->player.rotate)
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
	mlx_hook(game->win_ptr, 17, 0, full_exit, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
//	mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, use_mouse, game);
//	mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
}
