/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:16:28 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 14:46:49 by ksansom          ###   ########.fr       */
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
		full_exit(strerror(errno), game, errno);
	temp[game->cub_height] = NULL;
	while (i < (game->cub_height - 1))
	{
		temp[i] = game->cub_file[i];
		i++;
	}
	temp[i] = row;
	if (game->cub_file)
		free(game->cub_file);
	game->cub_file = temp;
	return (0);
}

void read_cub(t_game *game, char *cub)
{
	char	*row;

	row = NULL;
	if (ft_isdir(cub))
		full_exit(strerror(errno), game, errno);
	game->fd = open(cub, O_RDONLY);
	if (game->fd < 0)
		full_exit(strerror(errno), game, errno);
	while (1)
	{
		row = get_next_line(game->fd);
		if (adding_rows(game, row))
			break ;
	}
	close(game->fd);
	//game->map_width = ft_get_width(game->map[0]);
}

void	parse_file(t_game *game, char *cub)
{
	read_cub(game, cub);
 	read_textures(game);
	read_map(game);	
// 	ft_parse_path(&game);
}
