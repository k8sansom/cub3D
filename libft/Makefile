# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 11:51:45 by ksansom           #+#    #+#              #
#    Updated: 2023/11/20 15:25:24 by ksansom          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB	= ar rcs
RM = rm -rf

SRCS = ./src/ft_atoi.c ./src/ft_bzero.c ./src/ft_calloc.c ./src/ft_isalnum.c \
	./src/ft_isalpha.c ./src/ft_isascii.c ./src/ft_isdigit.c ./src/ft_isprint.c \
	./src/ft_itoa.c ./src/ft_memchr.c ./src/ft_memcmp.c ./src/ft_memcpy.c \
	./src/ft_memmove.c ./src/ft_memset.c ./src/ft_putchar_fd.c \
	./src/ft_putendl_fd.c ./src/ft_putnbr_fd.c ./src/ft_putstr_fd.c \
	./src/ft_split.c ./src/ft_strchr.c ./src/ft_strcmp.c ./src/ft_strdup.c \
	./src/ft_striteri.c ./src/ft_strjoin.c ./src/ft_strlcat.c ./src/ft_strlcpy.c \
	./src/ft_strlen.c ./src/ft_strmapi.c ./src/ft_strncmp.c ./src/ft_strnstr.c \
	./src/ft_strrchr.c ./src/ft_strtrim.c ./src/ft_substr.c ./src/ft_tolower.c \
	./src/ft_toupper.c ./src/get_next_line.c ./src/ft_printf.c \
	./src/ft_printf_csid.c ./src/ft_printf_pux.c 
OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	
clean:
	$(RM) $(OBJS)

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

