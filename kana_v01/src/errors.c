/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:27:23 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 15:27:34 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_textures(t_textures *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
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
