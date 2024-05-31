/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoronko <avoronko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:30 by ksansom           #+#    #+#             */
/*   Updated: 2024/05/31 12:47:39 by avoronko         ###   ########.fr       */
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

# define WIN_WIDTH	640
# define WIN_HEIGHT	480

# define WHITESPACE "	 /\r/\n/\f"

# define MOVESPEED 0.015
# define ROTSPEED 0.01

# define MOUSE_S 0.005

# define MMAP_PLAYER 0x00FF00
# define MMAP_WALL 0x808080
# define MMAP_FLOOR 0xE6E6E6
# define MMAP_OTHER 0x404040

# define TILE_SIZE 64

enum e_tex_index
{
	NO,
	SO,
	EA,
	WE
};

enum e_err_num
{
	NO_ERR,
	COM_ERR,
	CUB_ERR,
	TEX_ERR,
	MAP_ERR,
	MALLOC_ERR,
	MLX_ERR,
	MLX_IMG_ERR,
};

typedef struct s_mmap
{
	int		bits_per_pix;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
	int		view_dist;
	int		size;
	int		tile_size;
	int		off_x;
	int		off_y;
}	t_mmap;

typedef struct s_ray
{
	bool	hit_wall;
	int		current_column;
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

typedef struct s_wall
{
	int			orientation;
	double		line_height;
	double		draw_start;
	double		draw_end;
	bool		vertical_wall;
	double		tex_x;
	double		tex_y;
	double		wall_dist;
	double		step;
	double		tex_pos;
}	t_wall;

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
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
	int				width;
	int				size;
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

typedef struct s_image
{
	void	*img_ptr;
	int		*img_addr;
	int		bits_per_pix;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_game
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int			map_height;
	int			cub_height;
	int			map_width;
	int			player_counter;
	int			move_counter;

	char		**cub;
	char		**map;

	int			**texture_arr;

	t_textures	textures;
	t_player	player;
	t_ray		ray;
	t_image		image;
	t_mmap		mmap;
	t_wall		wall;
}	t_game;

//init
void		init_game(t_game *game);
void		init_mlx(t_game *game);
void		init_texture_arr(t_game *game);
void		init_tex_image(t_game *game, t_image *image, char *path);
void		init_image(t_game *game, t_image *image, int width, int height);

//parsing
void		parse_file(t_game *game, char *map);
void		read_cub(t_game *game, char *map);

//errors and exit
int			full_exit(char *s, t_game *game, int exit_code);
void		free_tab(void **tab);
void		ft_free(char **arr, int n);
int			quit_game(t_game *game);

//textures
void		read_textures(t_game *game);
void		check_textures(t_game *game);
int			*get_rgbs(t_game *game, char *str);
size_t		convert_rgb(int *tab);

//map
void		read_map(t_game *game);
void		check_map(t_game *game);
void		init_player_dir(t_game *game);
void		check_player_position(t_game *game);
void		finalize_map_dimensions(t_game *game);
void		make_map_square(t_game *game);

//controls
void		set_hooks(t_game *game);
int			key_release(int key, t_game *game);
int			key_press(int key, t_game *game);

//render
int			render_game(t_game *game);
void		render_frame(t_game *game);
void		initial_render(t_game *game);

//render utils
void		init_tex_pix(t_game *game);
void		set_frame_pix(t_game *game, t_image *image, int x, int y);

//raycasting
void		set_steps(t_game *game);
void		perform_dda(t_game *game);
void		calculate_wall(t_game *game);
void		calculate_texture(t_game *game);
void		raycasting(t_game *game);

//movement
int			handle_movement(t_game *game);
int			handle_rotation(t_game *game, double rotdir);
bool		is_wall(t_game *game, int x, int y);
int			valid_move(t_game *game, double x, double y);

//draw walls
void		set_pixel(t_game *game, int x, int y, int color);
void		wall_orientation(t_game *game);
void		draw_vertical_line(t_game *game, int x);
void		render_floor_and_ceiling(t_game *game);
int			get_wall_color(t_game *game, int location);

//minimap
void		init_minimap(t_game *game);
int			get_mmap_offset(t_mmap mmap, int mapsize, int pos);
void		render_minimap(t_game *game);
void		set_tile_pixels(t_game *game, int start_x, int start_y, int color);
void		draw_minimap_tile(t_game *game, int x, int y);

#endif