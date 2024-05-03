/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:10:58 by ksansom           #+#    #+#             */
/*   Updated: 2023/12/04 16:19:13 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit(char *s, t_game *game, int exit_code)
{
	int	i;

	i = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->fd)
		close(game->fd);
	// while (i < game->map_height)
	// {
	// 	free(game->map[i]);
	// 	i++;
	// }
	// free(game->map);
	if (s)
		ft_printf("%s\n", s);
	exit(exit_code);
}

int	ft_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectable_counter != 0)
			return (0);
		ft_printf("You've won!\n");
		ft_exit("", game, 0);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->move_counter++;
	}
	else if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->collectable_counter--;
		game->move_counter++;
	}
	return (1);
}

void	ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	exit_x(void *param)
{
	t_game	*game;
	int		i;

	game = (t_game *)param;
	ft_printf("Giving up?!\n");
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
	exit(0);
}
