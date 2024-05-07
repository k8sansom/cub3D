#include "../inc/cub3d.h"

void	full_exit(char *s, t_game *game, int exit_code)
{
	int	i;

	i = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->fd)
		close(game->fd);
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (s)
		ft_printf("%s\n", s);
	exit(exit_code);
}