/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:16:28 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/31 10:09:57 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	adding_rows(t_game *game, char *row)
{
	char	**temp;
	int		i;

	i = 0;
	if (!row)
		return (1);
	game->cub_height++;
	temp = (char **)malloc(sizeof(char *) * (game->cub_height + 1));
	if (!temp)
		full_exit("Error: malloc", game, MALLOC_ERR);
	temp[game->cub_height] = NULL;
	while (i < (game->cub_height - 1))
	{
		temp[i] = game->cub[i];
		i++;
	}
	temp[i] = row;
	if (game->cub)
		free(game->cub);
	game->cub = temp;
	return (0);
}

void	read_cub(t_game *game, char *cub)
{
	char	*row;
	size_t	len;

	row = NULL;
	len = ft_strlen(cub);
	if (ft_isdir(cub))
		full_exit("Error: is a directory", game, CUB_ERR);
	if (cub[len - 4] != '.' || cub[len - 3] != 'c' || cub[len - 2] != 'u' \
		|| cub[len - 1] != 'b')
		full_exit("Error: file is not a .cub", game, CUB_ERR);
	game->fd = open(cub, O_RDONLY);
	if (game->fd < 0)
		full_exit(strerror(errno), game, errno);
	game->cub[game->cub_height] = NULL;
	while (1)
	{
		row = get_next_line(game->fd);
		if (adding_rows(game, row))
			break ;
	}
	game->cub[game->cub_height] = NULL;
	close(game->fd);
	if (game->cub_height == 0)
		full_exit("Error: cub file is empty", game, CUB_ERR);
}

void	parse_file(t_game *game, char *cub)
{
	read_cub(game, cub);
	read_textures(game);
	check_textures(game);
	read_map(game);
	check_map(game);
	finalize_map_dimensions(game);
	make_map_square(game);
}
