/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:30 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/07 11:56:47 by ksansom          ###   ########.fr       */
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

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

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
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_height;
	int			win_width;
	int			map_height;
	int			map_width;

	char		**map;

	t_textures	*textures;
	t_player	*player;
}	t_game;

#endif