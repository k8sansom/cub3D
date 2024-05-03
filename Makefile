# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:51 by ksansom           #+#    #+#              #
#    Updated: 2023/11/27 10:00:33 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = sl_bonus

SRCS = ./src/so_long.c ./src/map.c ./src/errors.c ./src/graphics.c \
	./src/utils.c ./src/controls.c ./src/path_check.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = ./src_bonus/so_long.c ./src_bonus/map.c ./src_bonus/errors.c \
	./src_bonus/graphics.c ./src_bonus/utils.c ./src_bonus/controls.c \
	./src_bonus/path_check.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -L$(LIBFT_DIR) -lft

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(MLX_LIB):
	@make -C $(MLX_DIR)
$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean 
	@$(RM) $(NAME)
	@$(RM) $(MLX_LIB)
	@$(RM) $(LIBFT)
	@$(RM) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
