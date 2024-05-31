/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:58 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/31 16:06:38 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_minimap_tile(t_game *game, int x, int y)
{
	int		base_x;
	int		base_y;
	int		color;
	char	tile;

	base_x = x * game->mmap.tile_size;
	base_y = y * game->mmap.tile_size;
	color = MMAP_WALL;
	game->mmap.map_x = x + game->mmap.off_x;
	game->mmap.map_y = y + game->mmap.off_y;
	if (game->mmap.map_x >= 0 && game->mmap.map_x < game->map_width \
		&& game->mmap.map_y >= 0 && game->mmap.map_y < game->map_height)
	{
		tile = game->map[game->mmap.map_y][game->mmap.map_x];
		if ((int)game->player.pos_x == game->mmap.map_x \
			&& (int)game->player.pos_y == game->mmap.map_y)
			color = MMAP_PLAYER;
		else if (tile == '1')
			color = MMAP_WALL;
		else if (tile == '0')
			color = MMAP_FLOOR;
		else if (tile == 'S' || tile == 'N' || tile == 'W' || tile == 'E')
			color = MMAP_FLOOR;
	}
	set_tile_pixels(game, base_x, base_y, color);
}

void	set_tile_pixels(t_game *game, int start_x, int start_y, int color)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < game->mmap.tile_size)
	{
		j = 0;
		while (j < game->mmap.tile_size)
		{
			dst = game->mmap.addr + ((start_y + i) * game->mmap.line_length
					+ (start_x + j) * (game->mmap.bits_per_pix / 8));
			*(unsigned int *)dst = color;
			j++;
		}
		i++;
	}
}

void	render_minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mmap.height)
	{
		x = 0;
		while (x < game->mmap.width)
		{
			draw_minimap_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	init_minimap(t_game *game)
{
	int	width;
	int	height;

	game->mmap.view_dist = 10;
	game->mmap.width = game->map_width;
	game->mmap.height = game->map_height;
	if (game->map_width * (TILE_SIZE / 8) > WIN_WIDTH)
		game->mmap.tile_size = TILE_SIZE / 16;
	else if (game->map_height * (TILE_SIZE / 8) > WIN_HEIGHT)
		game->mmap.tile_size = TILE_SIZE / 16;
	else
		game->mmap.tile_size = TILE_SIZE / 8;
	width = game->mmap.width * game->mmap.tile_size;
	height = game->mmap.height * game->mmap.tile_size;
	game->mmap.img = mlx_new_image(game->mlx_ptr, width, height);
	if (!game->mmap.img)
		full_exit("Failed to create a minimap image\n", game, 0);
	game->mmap.addr = mlx_get_data_addr(game->mmap.img,
			&game->mmap.bits_per_pix,
			&game->mmap.line_length, &game->mmap.endian);
}
