/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:46:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/28 12:00:52 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_image(t_game *game, t_image *image, int width, int height)
{
	ft_memset(image, 0, sizeof(t_image));
	image->img_ptr = mlx_new_image(game->mlx_ptr, width, height);
	if (!image->img_ptr)
		full_exit("Error: Failed to create a new image", game, MLX_IMG_ERR);
	image->img_addr = (int *)mlx_get_data_addr(image->img_ptr, \
		&image->bits_per_pix, \
		&image->size_line, \
		&image->endian);
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		full_exit("Error: initializing mlx", game, MLX_ERR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!game->win_ptr)
		full_exit("Error: initializing mlx", game, MLX_ERR);
	// 	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2,
	// 		WIN_HEIGHT / 2);
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
//	init_minimap(&game);
	ft_memset(&game->ray, 0, sizeof(t_ray));
	ft_memset(&game->mmap, 0, sizeof(t_mmap));
}
