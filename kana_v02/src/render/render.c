/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:49:11 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/21 17:50:00 by avoronko         ###   ########.fr       */
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

void	raycasting(t_game *game)
{
	int	current_x;

	current_x = 0;
	while (current_x < WIN_WIDTH)
	{
		init_ray(game, current_x);
		perform_dda(game);
		calculate_line(game);
		draw_vertical_line(game, current_x);
		current_x++;
	}
}
int	render_game(t_game *game)
{
	handle_movement(game);
	handle_rotation(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_floor_and_ceiling(game);
	raycasting(game);
//	render_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->image.img_ptr, 0, 0);
	game->player.has_moved = 0;
	return (0);
}

