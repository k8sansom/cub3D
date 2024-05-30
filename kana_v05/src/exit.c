/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:27:23 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/30 11:47:16 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

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
	if (textures->ceiling_str)
		free(textures->ceiling_str);
	if (textures->ceiling)
		free(textures->ceiling);
	if (textures->floor_str)
		free(textures->floor_str);
	if (textures->floor)
		free(textures->floor);
}

int	full_exit(char *s, t_game *game, int exit_code)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->fd)
		close(game->fd);
	if (game->cub)
		free_tab((void **)game->cub);
	if (game->map)
		free_tab((void **)game->map);
	free_textures(&game->textures);
	if (game->texture_arr)
		free_tab((void **)game->texture_arr);
	if (s)
		ft_fprintf(1, "%s\n", s);
	//free_ray(game->ray);
	exit(exit_code);
	return (0);
}

int	quit_game(t_game *game)
{
	full_exit("All done?!", game, NO_ERR);
	return (0);
}

