/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:46:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/24 10:55:41 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		full_exit("Error: initializing mlx", game, 6);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!game->win_ptr)
		full_exit("Error: initializing mlx", game, 6);
	// 	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2,
	// 		WIN_HEIGHT / 2);
}

static void	init_other(t_game *game)
{
	ft_memset(&game->ray, 0, sizeof(t_ray));
	ft_memset(&game->mmap, 0, sizeof(t_mmap));
	ft_memset(&game->image, 0, sizeof(t_image));
}

static void	init_textures(t_textures *textures)
{
	ft_memset(textures, 0, sizeof(t_textures));
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TILE_SIZE;
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
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	init_player(&game->player);
	init_textures(&game->textures);
	init_other(game);
}
