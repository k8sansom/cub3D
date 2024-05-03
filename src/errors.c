/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:00:42 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/27 10:59:43 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	ft_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '0' && game->map[height][width] != '1'\
		&& game->map[height][width] != 'C' && game->map[height][width] != 'E'\
		&& game->map[height][width] != 'P')
		ft_exit ("Error: unknown character in map", game, game->exit_code++);
	if (game->map[height][width] == 'C')
		game->collectable_counter++;
	if (game->map[height][width] == 'P')
	{
		game->player_counter++;
		game->x_axis = width;
		game->y_axis = height;
	}
	if (game->map[height][width] == 'E')
		game->exit_counter++;
}

static int	ft_horizontal(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = game->map_height - 1;
	while (x < game->map_width)
	{
		if (!(game->map[0][x] == '1' && game->map[y][x] == '1'))
			return (0);
		x++;
	}
	return (1);
}

static int	ft_vertical(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = game->map_width - 1;
	while (y < game->map_height)
	{
		if (!(game->map[y][0] == '1' && game->map[y][x] == '1'))
			return (0);
		y++;
	}
	return (1);
}

void	ft_error_check(t_game *game)
{
	int	vertical;
	int	horizontal;
	int	height;
	int	width;

	vertical = ft_vertical(game);
	horizontal = ft_horizontal(game);
	if (!vertical || !horizontal)
		ft_exit ("Error: missing external walls!", game, game->exit_code++);
	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width < game->map_width)
		{
			ft_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->player_counter != 1 || game->collectable_counter < 1 \
		|| game->exit_counter != 1)
		ft_exit ("Error: Something is wrong with player, exit or collectable", \
			game, game->exit_code++);
}
