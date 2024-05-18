/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/17 17:58:26 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	render_game(t_game *game)
// {
// 	int	current_x;

// 	current_x = 0;
// 	handle_movement(game);
// 	handle_rotation(game);
// 	mlx_clear_window(game->mlx_ptr, game->win_ptr);
// 	raycasting(game);
// 	while (current_x < game->map_width)
// 	{
// 		draw_vertical_line(game, current_x);
// 		current_x++;
// 	}
// 	render_minimap(game);
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,...);
// 	game->player.has_moved = 0;
// }

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
	// init_player_dir(&game);
	// init_minimap(&game);
	// game.mlx_ptr = mlx_init();
	// if (game.mlx_ptr == NULL)
	// 	full_exit("Error: initializing mlx", &game, 1);
	// game.win_ptr = mlx_new_window(game.mlx_ptr, \
	// 	(game.map_width * IMG_W), (game.map_height * IMG_H), "cub3d");
	// if (game.win_ptr == NULL)
	// 	full_exit("Error: initializing window", &game, 1);
	// set_hooks(&game);
	// mlx_loop_hook(game.mlx_ptr, render_game, &game);
	// mlx_loop(game.mlx_ptr);
	ft_printf("game textures:\n");
	ft_printf("%s", game.textures.north);
	ft_printf("%s", game.textures.south);
	ft_printf("%s", game.textures.east);
	ft_printf("%s", game.textures.west);
	ft_printf("rgbs:\n");
	for (int i = 0; i < 3; i++)
		ft_printf("%d\n", game.textures.floor[i]);
	for (int i = 0; i < 3; i++)
		ft_printf("%d\n", game.textures.ceiling[i]);
	ft_printf("game map:\n");
	ft_printf("hex floor: %x, hex ceiling: %x\n", game.textures.hex_floor, game.textures.hex_ceiling);
	for (int i = 0; i < game.map_height; i++)
	 	ft_printf("%s", game.map[i]);
	full_exit("all done", &game, 0);
	return (0);
}
