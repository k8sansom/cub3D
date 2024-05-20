/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:15:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/20 18:23:53 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_horizontal(t_game *game)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(game->map[0]) - 1)
	{
		if (game->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (j < (int)ft_strlen(game->map[game->map_height - 1]) - 1)
	{
		if (game->map[game->map_height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	check_vertical(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || \
			game->map[i][ft_strlen(game->map[i]) - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	fill_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = 0;
		while (ft_strchr(WHITESPACE, game->map[i][j]))
			j++;
		if (game->map[i][j] != '1')
		{
			game->map_height = i;
			break ;
		}
	}
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->map[i]) - 2)
		{
			if (ft_strchr(WHITESPACE, game->map[i][j]))
				game->map[i][j] = '1';
		}
	}
}

static void	check_at_end(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && ft_strchr(WHITESPACE, game->map[i][j]))
			j++;
		if (game->map[i][j] && game->map[i][j] == '0')
			exit(full_exit("Error: missing external walls!", game, 3));
		else if (game->map[i][j] && game->map[i][j] != '1')
			exit(full_exit("Error: map not at end of file", game, 3));
		i++;
	}
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	if (!game->map)
		exit(full_exit("Error: map missing", game, 3));
	check_at_end(game);
	fill_spaces(game);
	if (!check_vertical(game) || !check_horizontal(game))
		full_exit("Error: missing external walls!", game, 3);
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->map[i]) - 1)
		{
			if (!ft_strchr("NSEW01", game->map[i][j]))
				exit(full_exit("Error: incorrect character in map", game, 3));
			if (ft_strchr("NSEW", game->map[i][j]))
				game->player_counter++;
		}
	}
	if (game->player_counter != 1)
		exit(full_exit ("Error: player count incorrect", game, 3));
	check_player_position(game);
}
