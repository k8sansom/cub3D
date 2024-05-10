/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:48:52 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 15:40:13 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	check_map(t_game *game)
// {
// 	int	vertical;
// 	int	horizontal;
// 	int	height;
// 	int	width;

// 	vertical = ft_vertical(game);
// 	horizontal = ft_horizontal(game);
// 	if (!vertical || !horizontal)
// 		ft_exit ("Error: missing external walls!", game, game->exit_code++);
// 	height = 0;
// 	while (height < game->map_height - 1)
// 	{
// 		width = 0;
// 		while (width < game->map_width)
// 		{
// 			ft_checker(game, height, width);
// 			width++;
// 		}
// 		height++;
// 	}
// 	if (game->player_counter != 1 || game->collectable_counter < 1 \
// 		|| game->exit_counter != 1)
// 		ft_exit ("Error: Something is wrong with player, exit or collectable", \
// 			game, game->exit_code++);
// }

void	copy_map(t_game *game, int start)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->cub_height - start);
	while (game->cub[start])
	{
		game->map[i] = ft_strdup(game->cub[start]);
		i++;
		start++;
	}
	game->map[i] = ft_strdup("\0");
	game->map_height = i;
}

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->cub[i])
	{
		while (!ft_strncmp(game->cub[i], "NO ", 3) || !ft_strncmp(game->cub[i], \
				"SO ", 3) || !ft_strncmp(game->cub[i], "WE ", 3) || !ft_strncmp\
				(game->cub[i], "EA ", 3) || !ft_strncmp(game->cub[i], "F ", 2) \
				|| !ft_strncmp(game->cub[i], "C ", 2))
		{
			i++;
			continue ;
		}
		j = 0;
		while (game->cub[i][j] && ft_strchr(WHITESPACE, game->cub[i][j]))
			j++;
		if (game->cub[i][j] == '\0')
			i++;
		else
		{
			copy_map(game, i);
			break ;
		}
	}
}
