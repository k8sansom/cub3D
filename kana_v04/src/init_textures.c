/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:51:39 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/24 12:19:21 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_tex_image(t_game *game, t_image *image, char *path)
{
	printf("made it to here 2\n");
	(void)path;
	ft_memset(image, 0, sizeof(t_image));
	image->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, \
		&game->textures.size, &game->textures.size);
	printf("made it to here 3\n");
	if (!image->img_ptr)
		full_exit("Error: mlx", game, 5);
	image->img_addr = (int *)mlx_get_data_addr(image->img_ptr, \
		&image->bits_per_pix, &image->size_line, &image->endian);
}

static int	*convert_xpm(t_game *game, char *path)
{
	t_image	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_tex_image(game, &tmp, path);
	buffer = ft_calloc(1, \
		sizeof * buffer * game->textures.size * game->textures.size);
	if (!buffer)
		full_exit("Error: malloc", game, 3);
	y = 0;
	while (y < game->textures.size)
	{
		x = 0;
		while (x < game->textures.size)
		{
			buffer[y * game->textures.size + x]
				= tmp.img_addr[y * game->textures.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(game->mlx_ptr, tmp.img_ptr);
	return (buffer);
}

void	init_texture_arr(t_game *game)
{
	game->texture_arr = ft_calloc(5, sizeof(game->texture_arr));
	if (!game->texture_arr)
		full_exit("Error: memory allocation", game, 3);
	printf("made it to here 1\n");
	game->texture_arr[NO] = convert_xpm(game, game->textures.north);
	game->texture_arr[SO] = convert_xpm(game, game->textures.south);
	game->texture_arr[EA] = convert_xpm(game, game->textures.east);
	game->texture_arr[WE] = convert_xpm(game, game->textures.west); 
}
