/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/07 10:38:32 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error: no map name provided\n");
		exit(STDERR_FILENO); 
	}
	ft_memset(&game, 0, sizeof(t_game));
	ft_read_map(&game, av[1]);
	ft_error_check(&game);
	ft_parse_path(&game);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		ft_exit("Error: initializing mlx", &game, game.exit_code++);
	game.win_ptr = mlx_new_window(game.mlx_ptr, \
		(game.map_width * IMG_W), (game.map_height * IMG_H), \
		"So Long");
	if (game.win_ptr == NULL)
		ft_exit ("Error: initializing window", &game, game.exit_code++);
	ft_set_sprites(&game);
	ft_render_game(&game, 'D');
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, ft_controls, &game);
	mlx_hook(game.win_ptr, 17, 0, exit_x, &game);
	mlx_loop(game.mlx_ptr);
}
