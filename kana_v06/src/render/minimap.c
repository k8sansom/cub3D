/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:58 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/30 13:34:49 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_mmap_offset(t_mmap mmap, int mapsize, int pos)
{
	if (pos > mmap.view_dist && mapsize - pos > mmap.view_dist + 1)
		return (pos - mmap.view_dist);
	if (pos > mmap.view_dist && mapsize - pos <= mmap.view_dist + 1)
		return (mapsize - mmap.size);
	return (0);
}

void	draw_minimap_tile(t_game *game, int x, int y)
{
	int		base_x;
	int		base_y;
	int		color;
	char	tile;

	base_x = x * game->mmap.tile_size;
	base_y = y * game->mmap.tile_size;
	color = MMAP_OTHER;
	if ((y + game->mmap.off_y) < game->map_height
		&& (x + game->mmap.off_x) < game->map_width)
	{
		tile = game->map[y + game->mmap.off_y][x + game->mmap.off_x];
		if (tile == 'S' || tile == 'N' || tile == 'E' || tile == 'W')
			color = MMAP_PLAYER;
		else if (tile == '1')
			color = MMAP_WALL;
		else if (tile == '0')
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
	game->mmap.off_x = get_mmap_offset(game->mmap, \
		game->map_width, game->player.pos_x);
	game->mmap.off_y = get_mmap_offset(game->mmap, \
		game->map_height, game->player.pos_y);
	while (y < game->mmap.size)
	{
		x = 0;
		while (x < game->mmap.size)
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

	game->mmap.view_dist = 5;
	game->mmap.size = (2 * game->mmap.view_dist) + 1;
	game->mmap.tile_size = 10;
	game->mmap.off_x = get_mmap_offset(game->mmap, game->map_width,
			game->player.pos_x);
	game->mmap.off_y = get_mmap_offset(game->mmap, game->map_height,
			game->player.pos_y);
	width = game->mmap.size * game->mmap.tile_size;
	height = game->mmap.size * game->mmap.tile_size;
	game->mmap.img = mlx_new_image(game->mlx_ptr, width, height);
	if (!game->mmap.img)
		full_exit("Failed to create a minimap image\n", game, 0);
	game->mmap.addr = mlx_get_data_addr(game->mmap.img,
			&game->mmap.bits_per_pix,
			&game->mmap.line_length, &game->mmap.endian);
}
