/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:48:52 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 14:26:52 by ksansom          ###   ########.fr       */
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
	game->map = malloc(sizeof(char *) * game->cub_height - start);
	while (game->cub_file[start])
	{
		
	}
}

void	read_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (ft_strncmp(game->cub_file[i], "NO ", 3) == 0 ||\
			ft_strncmp(game->cub_file[i], "SO ", 3) == 0 ||\
			ft_strncmp(game->cub_file[i], "WE ", 3) == 0 ||\
			ft_strncmp(game->cub_file[i], "EA ", 3) == 0 ||\
			ft_strncmp(game->cub_file[i], "F ", 2) == 0 ||\
			ft_strncmp(game->cub_file[i], "C ", 2) == 0)
			i++;
	while (game->cub_file[i])
	{
		j = 0;
		while (game->cub_file[i][j] && ft_strchr(WHITESPACE, game->cub_file[i][j]))
			j++;
		if (game->cub_file[i][j] == '\0')
			i++;
		else
		{
			copy_map(game, i);
		}
	}
}
