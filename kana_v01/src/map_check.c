/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:15:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/13 16:35:11 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	fill_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(game->map[i])
	{
		j = 0;
		while (j < ft_strlen(game->map[i]) - 2)
		{
			if (ft_strchr(WHITESPACE, game->map[i][j]))
			{
				if 
			}
		}
	}
}

void	check_map(t_game *game)
{
	int	i;
	int	j;

	fill_spaces(game);
	if (!ft_vertical(game) || !ft_horizontal(game))
		full_exit ("Error: missing external walls!", game, 3);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (++j < ft_strlen(game->map[i]) - 2)
		{
			if (!ft_strchr("NSEW01", game->map[i][j]))
				full_exit("Error: incorrect character in game", game, 3);
			if (ft_strchr("NSEW", game->map[i][j]))
				game->player_counter++;
		}
	}
	if (game->player_counter != 1)
		full_exit ("Error: player count incorrect", game, 3);
}
