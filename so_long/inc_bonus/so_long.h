/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:52:21 by ksansom           #+#    #+#             */
/*   Updated: 2023/11/27 10:38:07 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>
# include <fcntl.h>

# define IMG_W	32
# define IMG_H	32

# define WALL_XPM			"assets/wall.xpm"
# define FLOOR_XPM			"assets/floor.xpm"
# define WINE_XPM			"assets/wine.xpm"
# define EXIT_XPM			"assets/toilet.xpm"
# define PLAYER_DOWN_XPM	"assets/player_down.xpm"
# define PLAYER_UP_XPM		"assets/player_up.xpm"
# define PLAYER_RIGHT_XPM	"assets/player_right.xpm"
# define PLAYER_LEFT_XPM	"assets/player_left.xpm"
# define ENEMY_XPM			"assets/enemy.xpm"

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_UP  	65362
# define KEY_LEFT  	65361
# define KEY_RIGHT 	65363
# define KEY_DOWN  	65364	

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	int		fd;
	int		map_height;
	int		map_width;
	int		player_counter;
	int		collectable_counter;
	int		move_counter;
	int		exit_counter;
	int		x_axis;
	int		y_axis;
	int		exit_code;

	char	**map;

	t_image	floor;
	t_image	wall;
	t_image	player_down;
	t_image	player_up;
	t_image	player_right;
	t_image	player_left;
	t_image	exit;
	t_image	wine;
	t_image	enemy;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_game;

//map
void	ft_read_map(t_game *game, char *s);

//graphics
void	ft_set_sprites(t_game *game);
void	ft_render_game(t_game *game, int c);
void	ft_render_player(t_game *game, int y, int x, char c);

//errors
void	ft_error_check(t_game *game);

//path check
void	ft_parse_path(t_game *game);

//utils
void	ft_exit(char *s, t_game *game, int exit_code);
int		ft_move(t_game *game, int x, int y);
void	ft_free(char **arr, int n);
int		exit_x(void *param);
void	ft_print_to_screen(t_game *game);

//controls
int		ft_controls(int command, t_game *game);

#endif