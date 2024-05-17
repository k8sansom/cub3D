/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:30 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/17 12:34:59 by avoronko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/inc/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
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
# define KEY_LEFT  	65361
# define KEY_RIGHT 	65363

# define MOVESPEED 0.1
# define ROTSPEED 0.01

typedef struct s_wall
{
	int		texture_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_wall;

typedef struct s_ray
{
	bool	hit_wall;
	int		current_column;
	double	wall_dist;
	double	wall_pos;
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
	char			*floor_str;
	char			*ceiling_str;
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
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_height;
	int			win_width;
	int			map_height;
	int			cub_height;
	int			map_width;
	int			player_counter;
	int			move_counter;
	int			player_pos_x;
	int			player_pos_y;

	char		**cub;
	char		**map;

	t_textures	textures;
	t_player	player;
	t_ray		ray;
	t_wall		wall;
}	t_game;

//init
void		init_game(t_game *game);

//parsing
void		parse_file(t_game *game, char *map);
void		read_cub(t_game *game, char *map);

//errors
void		full_exit(char *s, t_game *game, int exit_code);
void		free_arr(char **arr);
void		ft_free(char **arr, int n);

//textures
void		read_textures(t_game *game);
void		check_textures(t_game *game);
int			*get_rgbs(t_game *game, char *str);
size_t		convert_rgb(int *tab);

//map
void		read_map(t_game *game);
void		check_map(t_game *game);

//player
void		check_player_position(t_game *game);

//controls
static void	key_press(t_game *game, int key);
static void	key_release(t_game *game, int key);
static void	use_mouse(int x, int y, t_game *game);
void		set_hooks(t_game *game);

//raycasting
void		raycasting(t_game *game);
static void	calculate_wall_distance(t_game *game, bool vertical_wall);
static void	perform_dda(t_game *game);
static void	set_steps(t_game *game);
static void	init_ray(t_game *game, int current_x);

//movement
void		handle_movement(t_game *game);
static void	move_right(t_game *game);
static void	move_left(t_game *game);
static void	move_forward(t_game *game);
static void	move_backward(t_game *game);

//rotation
static void	handle_rotation(t_game *game);

//raycasting utils
static int	is_wall(t_game *game);
static bool	is_valid_pos(t_game *game, double x, double y);

//draw walls
void		calculate_line(int x, t_game *game);
void		draw_vertical_line();

#endif