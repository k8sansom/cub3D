/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:49:11 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/29 11:05:14 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_frame(t_game *game)
{
	int	x;
	int	y;

	init_image(game, &game->image, WIN_WIDTH, WIN_HEIGHT);
	init_tex_pix(game);
//	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	raycasting(game);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			set_frame_pix(game, &game->image, x, y);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->image.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->image.img_ptr);
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

void	initial_render(t_game *game)
{
	render_frame(game);
//	render_minimap(game);
}
