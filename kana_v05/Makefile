# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:51 by ksansom           #+#    #+#              #
#    Updated: 2024/05/29 11:04:29 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

SRCS =	src/controls.c \
		src/exit.c \
		src/init_player_dir.c \
		src/init_textures.c \
		src/init.c \
		src/main.c \
		src/map_check.c \
		src/map.c \
		src/parse.c \
		src/player_check.c \
		src/textures_check.c \
		src/textures.c \
		src/movement/movement.c \
		src/movement/rotation.c \
		src/movement/valid_move.c \
		src/render/draw_walls.c \
		src/render/minimap.c \
		src/render/raycasting_utils.c \
		src/render/raycasting.c \
		src/render/render.c \
		src/render/render_utils.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX_DIR = ./minilibx-linux
INCLUDES = -I$(LIBFT_DIR)/inc -I$(MINILIBX_DIR)

LFLAGS = -L$(MINILIBX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean 
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
