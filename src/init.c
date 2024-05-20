/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:46:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/20 19:11:03 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_other(t_game *game)
{
	ft_memset(&game->ray, 0, sizeof(t_ray));
	ft_memset(&game->mmap, 0, sizeof(t_mmap));
	ft_memset(&game->wall, 0, sizeof(t_wall));
}

void	init_image(t_game *game)
{
	game->image.img_ptr = mlx_new_image(game->mlx_ptr,
			game->win_width, game->win_height);
	if (!game->image.img_ptr)
		exit(full_exit("Failed to create a new image.\n", game, 1));
	game->image.img_data = (int *)mlx_get_data_addr(game->image.img_ptr,
			&game->image.bits_per_pix,
			&game->image.size_line,
			&game->image.endian);
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
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	init_player(&game->player);
	init_textures(&game->textures);
	game->win_height = 720;
	game->win_width = 960;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		exit(full_exit("Error: initializing mlx", game, 1));
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "cub3d");
	if (game->win_ptr == NULL)
		exit(full_exit("Error: initializing window", game, 1));
	init_image(game);
	init_other(game);
}
