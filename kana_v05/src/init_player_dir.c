/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:45:36 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/28 10:03:35 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_north(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0;
}

static void	init_south(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
}

static void	init_west(t_game *game)
{
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0;
}

static void	init_east(t_game *game)
{
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->player.plane_x = 0.66;
	game->player.plane_y = 0;
}

void	init_player_dir(t_game *game)
{
	if (game->player.dir == 'W')
		init_west(game);
	else if (game->player.dir == 'E')
		init_east(game);
	else if (game->player.dir == 'S')
		init_south(game);
	else if (game->player.dir == 'N')
		init_north(game);
}
