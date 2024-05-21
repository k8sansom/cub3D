#include "../inc/cub3d.h"

static int	convert_xpm(t_game *game, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_tex_image(game, &tmp, path);
	buffer = ft_calloc(1,
			sizeof(buffer * game->textures.size * game->textures.size));
	if (!buffer)
		exit(full_exit("Error: malloc", game, 3));
	y = 0;
	while (y < game->textures.size)
	{
		x = 0;
		while (x < game->textures.size)
		{
			buffer[y * game->textures.size + x]
				= tmp.addr[y * game->textures.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_game *game)
{
	game->texture_arr = ft_calloc(5, sizeof(game->texture_arr));
	if (!game->texture_arr)
		exit(full_exit("Error: memory allocation", game, 3));
	data->textures_arr[NO] = convert_xpm(game, game->textures.north);
	data->textures_arr[SO] = convert_xpm(game, game->textures.south);
	data->textures_arr[EA] = convert_xpm(game, game->textures.east);
	data->textures_arr[WE] = convert_xpm(game, game->textures.west); 
}