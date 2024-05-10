/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:32:34 by avoronko          #+#    #+#             */
/*   Updated: 2024/05/10 13:34:06 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_wall(t_game *game)
{
	if (game->ray.pos_x < 0 || game->ray.pos_x >= game->map_width
		|| game->ray.pos_y < 0 || game->ray.pos_y >= game->map_height)
		return (1);
	return (game->map[(int)game->ray.pos_y][(int)game->ray.pos_x] == '1');
}
void	draw_vertical_line(int x, double wall_dist, t_game *game)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(game->map_height / wall_dist);

	draw_start = (game->map_height - line_height) / 2;
	draw_end = draw_start + line_height;

	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= game->map_height)
		draw_end = game->map_height - 1;
}
