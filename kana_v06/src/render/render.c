/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:49:11 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/31 14:40:37 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_floor_and_ceiling(t_game *game)
{
	int		y;
	int		x;
	size_t	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = game->textures.hex_ceiling;
		else
			color = game->textures.hex_floor;
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *game)
{
	init_image(game, &game->image, WIN_WIDTH, WIN_HEIGHT);
	render_floor_and_ceiling(game);
	raycasting(game);
	// init_minimap(game);
	// render_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->image.img_ptr, 0, 0);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	// 	game->mmap.img, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->image.img_ptr);
	// mlx_destroy_image(game->mlx_ptr, game->mmap.img);
}

int	render_game(t_game *game)
{
	game->player.has_moved = handle_movement(game);
	if (!game->player.has_moved)
		return (0);
	render_frame(game);
	game->player.has_moved = 0;
	return (0);
}
