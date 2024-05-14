/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:15:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/13 16:42:06 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_horizontal(t_game *game)
{
	int	x;
	int	y;

	y = game->map_height - 1;
	x = -1;
	while (++x < ft_strlen(game->map[0]) - 2)
	{
		if (game->map[0][x] != '1')
			return (0);
	}
	x = -1;
	while(++x < ft_strlen(game->map[y]) - 2)
	{
		if (game->map[y][x] != '1')
			return (0);
	}
	return (1);
}

static int	check_vertical(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = game->map_width - 1;
	while (y < game->map_height)
	{
		if (game->map[y][0] != '1')
			return (0);
		y++;
	}
	return (1);
}

static void	fill_spaces(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(i < game->map_height - 1)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]) - 2)
		{
			while (ft_strchr(WHITESPACE, game->map[i][j]))
				j++;
			whileif ((game->map[i + 1] && game->map[i + 1][j] != '0') && game->map[i][j + 1] != '0'))
					game->map[i][j] == '1';
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	fill_spaces(game);
	if (!check_vertical(game) || !check_horizontal(game))
		full_exit ("Error: missing external walls!", game, 3);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (++j < ft_strlen(game->map[i]) - 2)
		{
			if (!ft_strchr("NSEW01", game->map[i][j]))
				full_exit("Error: incorrect character in map", game, 3);
			if (ft_strchr("NSEW", game->map[i][j]))
				game->player_counter++;
		}
	}
	if (game->player_counter != 1)
		full_exit ("Error: player count incorrect", game, 3);
}
