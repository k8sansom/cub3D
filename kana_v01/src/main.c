/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 15:12:09 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	for (int i = 0; i < game.map_height; i++)
		ft_printf("%s", game.map[i]);
	full_exit("all done", &game, 0);
	// ft_error_check(&game);
	// ft_parse_path(&game);
	// game.mlx_ptr = mlx_init();
	// if (game.mlx_ptr == NULL)
	// 	ft_exit("Error: initializing mlx", &game, game.exit_code++);
	// game.win_ptr = mlx_new_window(game.mlx_ptr, \
	// 	(game.map_width * IMG_W), (game.map_height * IMG_H), \
	// 	"So Long");
	// if (game.win_ptr == NULL)
	// 	ft_exit ("Error: initializing window", &game, game.exit_code++);
	// ft_set_sprites(&game);
	// ft_render_game(&game, 'D');
	// mlx_hook(game.win_ptr, KeyPress, KeyPressMask, ft_controls, &game);
	// mlx_hook(game.win_ptr, 17, 0, exit_x, &game);
	// mlx_loop(game.mlx_ptr);
	return (0);
}