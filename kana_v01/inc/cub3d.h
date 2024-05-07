/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:30 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/07 10:25:14 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# define FOV		(60 * (PI / 180))
# define PI			3.14159265358979323846

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;


typedef struct s_ray
{
	bool	hit_wall;
	int		c_col;
	int		cam_x;
	int		wall_dist;
	int		ray_angle;
	int		ray_step;
	int		ray_x;
	int		ray_y;
	int		eye_x;
	int		eye_y;
}	t_ray;	

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

#endif