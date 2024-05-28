/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:24:54 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/28 10:43:29 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_tex_pix(t_game *game)
{
	int	i;

	if (game->tex_pix)
		free_tab((void **)game->tex_pix);
	game->tex_pix = ft_calloc(WIN_HEIGHT + 1,
			sizeof * game->tex_pix);
	if (!game->tex_pix)
		full_exit("Error: malloc", game, 3);
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
