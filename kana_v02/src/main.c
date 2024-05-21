/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/21 10:41:01 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	render_game(t_game *game)
{
	int	current_x;

	current_x = 0;
	handle_movement(game);
	handle_rotation(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_floor_and_ceiling(game);
	raycasting(game);
	while (current_x < game->map_width)
	{
		draw_vertical_line(game, current_x);
		current_x++;
	}
	render_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->image.img_ptr, 0, 0);
	game->player.has_moved = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_fprintf(1, "Error: no map provided\n");
		return (1); 
	}
	init_game(&game);
	parse_file(&game, av[1]);
	init_mlx(&game);
	// init_texture_arr(&game);
	// init_player_dir(&game);
	// init_minimap(&game);
	// set_hooks(&game);
	// mlx_loop_hook(game.mlx_ptr, render_game, &game);
	// mlx_loop(game.mlx_ptr);
	exit(full_exit("all done", &game, 0));
	return (0);
}
