# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:52:51 by tedelin           #+#    #+#              #
#    Updated: 2023/01/24 17:14:00 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = path.c parsing.c main.c hook.c
OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall
MLX_FLAGS = -lX11 -lXext
MLX_PATH = minilibx-linux
MLX_LIB = minilibx-linux/libmlx.a
LIBFT_LIB = libft/libft.a
LIBFT_PATH = libft

all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_PATH)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(FLAGS) -o $@ $^ $(MLX_FLAGS)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
