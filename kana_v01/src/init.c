/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:46:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/17 16:58:34 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_ray(t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
}

static void	init_textures(t_textures *textures)
{
	ft_memset(textures, 0, sizeof(t_textures));
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = 64;
	textures->step = 0.0;
	textures->pos = 0.0;
}

static void	init_player(t_player *player)
{
	ft_memset(player, 0, sizeof(t_player));
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
}

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	init_player(&game->player);
	init_textures(&game->textures);
	init_ray(&game->ray);
	game->win_height = 720;
	game->win_width = 960;
}
