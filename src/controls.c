/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:43:54 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/27 10:48:29 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_d(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	++x;
	if (game->map[y][x] == '1')
		return (0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y][x - 1] = '0';
	ft_printf("Moves: %i, Collectables left: %i\n", game->move_counter, \
		game->collectable_counter);
	return (1);
}

static int	ft_a(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	--x;
	if (game->map[y][x] == '1')
		return (0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y][x + 1] = '0';
	ft_printf("Moves: %i, Collectables left: %i\n", game->move_counter, \
		game->collectable_counter);
	return (1);
}

static int	ft_s(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	++y;
	if (game->map[y][x] == '1')
		return (0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y - 1][x] = '0';
	ft_printf("Moves: %i, Collectables left: %i\n", game->move_counter, \
		game->collectable_counter);
	return (1);
}

static int	ft_w(t_game *game)
{
	int	x;
	int	y;
	int	move;

	x = game->x_axis;
	y = game->y_axis;
	--y;
	if (game->map[y][x] == '1')
		return (0);
	move = ft_move(game, x, y);
	if (!move)
		return (0);
	game->map[y + 1][x] = '0';
	ft_printf("Moves: %i, Collectables left: %i\n", game->move_counter, \
		game->collectable_counter);
	return (1);
}

int	ft_controls(int command, t_game *game)
{
	int	move;

	if (command == KEY_ESC)
		ft_exit ("GIVING UP?!", game, 0);
	if (command == KEY_W || command == KEY_UP)
		move = ft_w(game);
	if (command == KEY_S || command == KEY_DOWN)
		move = ft_s(game);
	if (command == KEY_A || command == KEY_LEFT)
		move = ft_a(game);
	if (command == KEY_D || command == KEY_RIGHT)
		move = ft_d(game);
	if (move)
		ft_render_game(game);
	return (0);
}
