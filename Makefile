# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:52:51 by tedelin           #+#    #+#              #
#    Updated: 2023/01/30 19:48:41 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include -I./minilibx-linux -I./libft
SRC = $(addprefix src/, path.c parsing.c img.c moves.c utils.c main.c)
OBJ = $(addprefix obj/, path.o parsing.o img.o moves.o utils.o main.o)
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

$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDE) $(MLX_FLAGS) -o $@ $^

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f $(OBJ)
	rm -rf obj

fclean:	clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re