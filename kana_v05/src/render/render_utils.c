/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:24:54 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/29 11:20:08 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	set_img_pix(t_image *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->img_addr[pixel] = color;
}

void	set_frame_pix(t_game *game, t_image *image, int x, int y)
{
	if (game->tex_pix[y][x] > 0)
		set_img_pix(image, x, y, game->tex_pix[y][x]);
	else if (y > WIN_HEIGHT / 2)
		set_img_pix(image, x, y, game->textures.hex_ceiling);
	else
		set_img_pix(image, x, y, game->textures.hex_floor);
}

void	init_tex_pix(t_game *game)
{
	int	i;

	if (game->tex_pix)
		free_tab((void **)game->tex_pix);
	game->tex_pix = ft_calloc(WIN_HEIGHT + 1,
			sizeof * game->tex_pix);
	if (!game->tex_pix)
		full_exit("Error: malloc", game, MALLOC_ERR);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		game->tex_pix[i] = ft_calloc(WIN_WIDTH + 1,
				sizeof * game->tex_pix);
		if (!game->tex_pix[i])
			full_exit("Error: malloc", game, 3);
		i++;
	}
}
