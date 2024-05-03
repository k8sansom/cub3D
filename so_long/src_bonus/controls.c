/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/27 11:09:34 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long.h"

static int	ft_d(t_game *game)
{
	int	x;
	int	y;
	int	move;
	int	c;

	c = 'R';
	x = game->x_axis;
	y = game->y_axis;
	++x;
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y][x - 1] = '0';
	return (c);
}

static int	ft_a(t_game *game)
{
	int	x;
	int	y;
	int	move;
	int	c;

	c = 'L';
	x = game->x_axis;
	y = game->y_axis;
	--x;
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y][x + 1] = '0';
	return (c);
}

static int	ft_s(t_game *game)
{
	int	x;
	int	y;
	int	move;
	int	c;

	c = 'D';
	x = game->x_axis;
	y = game->y_axis;
	++y;
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y - 1][x] = '0';
	return (c);
}

static int	ft_w(t_game *game)
{
	int	x;
	int	y;
	int	move;
	int	c;

	c = 'U';
	x = game->x_axis;
	y = game->y_axis;
	--y;
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'V')
		ft_exit("Game Over!", game, 0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y + 1][x] = '0';
	return (c);
}

int	ft_controls(int command, t_game *game)
{
	int	c;

	c = 0;
	if (command == KEY_ESC)
		ft_exit ("Giving up?!", game, 0);
	if (command == KEY_W || command == KEY_UP)
		c = ft_w(game);
	if (command == KEY_S || command == KEY_DOWN)
		c = ft_s(game);
	if (command == KEY_A || command == KEY_LEFT)
		c = ft_a(game);
	if (command == KEY_D || command == KEY_RIGHT)
		c = ft_d(game);
	if (c)
		ft_render_game(game, c);
	ft_print_to_screen(game);
	return (0);
}
