/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:27:24 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/31 13:11:51 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	flood_fill(t_game *temp, int y, int x)
{
	if (temp->map[y][x] == '1' || y > (temp->map_height - 1) || y < 0 || \
		x > (int)(ft_strlen(temp->map[y]) - 2) || x < 0)
		return ;
	if (temp->map[y][x] == '0')
		temp->move_counter++;
	temp->map[y][x] = '1';
	flood_fill(temp, y + 1, x);
	flood_fill(temp, y - 1, x);
	flood_fill(temp, y, x + 1);
	flood_fill(temp, y, x - 1);
}

void	path_check(t_game *game)
{
	t_game	temp;
	int		i;

	ft_memset(&temp, 0, sizeof(t_game));
	temp.map_height = game->map_height;
	temp.player.pos_x = game->player.pos_x;
	temp.player.pos_y = game->player.pos_y;
	temp.map = (char **)malloc((game->map_height + 1) * sizeof(char *));
	if (!temp.map)
		full_exit("Error: allocating memory", game, 5);
	i = 0;
	while (i < game->map_height)
	{
		temp.map[i] = ft_strdup(game->map[i]);
		i++;
	}
	temp.map[i] = NULL;
	flood_fill(&temp, temp.player.pos_y, temp.player.pos_x);
	if (temp.move_counter < 1)
	{
		free_tab((void **)temp.map);
		full_exit("Error: no valid path available", game, 6);
	}
	free_tab((void **)temp.map);
}

void	check_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_memset(&game->player, 0, sizeof(t_player));
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr("NSEW", game->map[i][j]))
			{
				game->player.pos_x = j + 0.5;
				game->player.pos_y = i + 0.5;
				game->player.dir = game->map[i][j];
			}
			j++;
		}
		i++;
	}
	path_check(game);
}
