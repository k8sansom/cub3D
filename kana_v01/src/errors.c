#include "../inc/cub3d.h"

void	free_textures(t_textures *textures)
{
	free(textures->north);
	free(textures->south);
	free(textures->west);
	free(textures->east);
	//free(textures->floor);
	//free(textures->ceiling);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	full_exit(char *s, t_game *game, int exit_code)
{
	// if (game->win_ptr)
	// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// if (game->mlx_ptr)
	// 	mlx_destroy_display(game->mlx_ptr);
	if (game->fd)
		close(game->fd);
	if (game->cub_height)
		free_arr(game->cub_file);
	if (game->map_height)
		free_arr(game->map);
	if (s)
		ft_fprintf(1, "%s\n", s);
	free_textures(&game->textures);
	//free_ray(game->ray);
	exit(exit_code);
}
