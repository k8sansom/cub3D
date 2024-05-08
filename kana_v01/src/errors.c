#include "../inc/cub3d.h"

static void	free_textures(t_textures *textures)
{
	free(textures->north);
	free(textures->south);
	free(textures->west);
	free(textures->east);
	free(textures->floor);
	free(textures->ceiling);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
void	full_exit(char *s, t_game *game, int exit_code)
{
	// if (game->win_ptr)
	// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// if (game->mlx_ptr)
	// 	mlx_destroy_display(game->mlx_ptr);
	// if (game->fd)
		close(game->fd);
	if (game->map_height)
		free_map(game);
	if (s)
		ft_fprintf(1, "%s\n", s);
	free_textures(&game->textures);
	//free_ray(game->ray);
	exit(exit_code);
}
