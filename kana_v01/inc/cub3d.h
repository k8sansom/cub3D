/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:30 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/09 15:07:52 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx-linux/mlx_int.h"
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

typedef struct s_game
{
	int		fd;
	int		map_height;
	int		map_width;
	int		player_counter;
	int		exit_counter;
	int		player_x;
	int		player_y;
	int		exit_code;

	char	**map;

	t_image	floor;
	t_image	wall;
	t_image	player;
	t_image	exit;
	t_image	wine;

	void	*mlx_ptr;
	void	*win_ptr;

	bool	hit_wall;
	int		current_column;
	double	wall_dist;
	double	ray_pos_x;
	double	ray_pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;

	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_game;

#endif