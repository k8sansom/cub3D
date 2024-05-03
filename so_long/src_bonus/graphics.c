/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:02:40 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/23 14:39:49 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long.h"

static void	ft_render_sprite(t_game *game, t_image sprite, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			sprite.xpm_ptr, x * sprite.x, y * sprite.y);
}

void	ft_render_player(t_game *game, int y, int x, char c)
{
	if (c == 'U')
		ft_render_sprite(game, game->player_up, y, x);
	else if (c == 'D')
		ft_render_sprite(game, game->player_down, y, x);
	else if (c == 'R')
		ft_render_sprite(game, game->player_right, y, x);
	else if (c == 'L')
		ft_render_sprite(game, game->player_left, y, x);
}

void	ft_render_game(t_game *game, int c)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == '0')
				ft_render_sprite(game, game->floor, y, x);
			if (game->map[y][x] == '1')
				ft_render_sprite(game, game->wall, y, x);
			if (game->map[y][x] == 'E')
				ft_render_sprite(game, game->exit, y, x);
			if (game->map[y][x] == 'P')
				ft_render_player(game, y, x, c);
			if (game->map[y][x] == 'C')
				ft_render_sprite(game, game->wine, y, x);
			if (game->map[y][x] == 'V')
				ft_render_sprite(game, game->enemy, y, x);
		}
	}
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_exit("Error: loading sprite", game, game->exit_code++);
	return (sprite);
}

void	ft_set_sprites(t_game *game)
{
	game->floor = ft_new_sprite(game->mlx_ptr, FLOOR_XPM, game);
	game->wall = ft_new_sprite(game->mlx_ptr, WALL_XPM, game);
	game->player_up = ft_new_sprite(game->mlx_ptr, PLAYER_UP_XPM, game);
	game->player_down = ft_new_sprite(game->mlx_ptr, PLAYER_DOWN_XPM, game);
	game->player_left = ft_new_sprite(game->mlx_ptr, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(game->mlx_ptr, PLAYER_RIGHT_XPM, game);
	game->wine = ft_new_sprite(game->mlx_ptr, WINE_XPM, game);
	game->exit = ft_new_sprite(game->mlx_ptr, EXIT_XPM, game);
	game->enemy = ft_new_sprite(game->mlx_ptr, ENEMY_XPM, game);
}
