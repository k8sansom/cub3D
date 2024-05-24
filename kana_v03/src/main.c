/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:19:32 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/24 12:19:44 by ksansom          ###   ########.fr       */
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
	printf("%s\n", game.textures.north);
	printf("what about here?\n");
	init_mlx(&game);
	init_texture_arr(&game);
	init_player_dir(&game);
	init_minimap(&game);
	set_hooks(&game);
	mlx_loop_hook(game.mlx_ptr, render_game, &game);
	mlx_loop(game.mlx_ptr);
	full_exit("all done", &game, 0);
	return (0);
}
