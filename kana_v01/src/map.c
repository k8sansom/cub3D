/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:48:52 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/07 11:54:59 by ksansom          ###   ########.fr       */
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

