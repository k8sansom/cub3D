/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:30 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/10 13:00:51 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
//# include "../mlx/mlx.h"
//# include "../mlx/mlx_int.h"
# include <math.h>
# include <fcntl.h>
# include <sys/errno.h>

# define IMG_W	32
# define IMG_H	32

# define WHITESPACE "	 /\r/\n/\f"

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_UP  	65362
# define KEY_LEFT  	65361
# define KEY_RIGHT 	65363
# define KEY_DOWN  	65364	

typedef struct s_ray
{
	bool	hit_wall;
	int		current_column;
	double	wall_dist;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
}	t_ray;

typedef struct s_textures
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	size_t			hex_floor;
	size_t			hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_textures;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		has_moved;
	int		move_x;
	int		move_y;
	int		rotate;
}	t_player;

typedef struct s_game
{
	int			fd;
	// void		*mlx_ptr;
	// void		*win_ptr;
	int			win_height;
	int			win_width;
	int			map_height;
	int			cub_height;
	int			map_width;

	char		**cub_file;
	char		**map;

	t_textures	textures;
	t_player	player;
	t_ray		ray;
}	t_game;

//init
void	init_game(t_game *game);

//parsing
void	parse_file(t_game *game, char *map);
void 	read_cub(t_game *game, char *map);

//errors
void	full_exit(char *s, t_game *game, int exit_code);
void	free_arr(char **arr);

//textures
void	read_textures(t_game *game);

#endif