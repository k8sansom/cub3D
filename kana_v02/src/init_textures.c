#include "../inc/cub3d.h"

static int	convert_xpm(t_game *game, char *path)
{

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