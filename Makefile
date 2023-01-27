# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:52:51 by tedelin           #+#    #+#              #
#    Updated: 2023/01/27 17:13:33 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -I./include
SRC = $(addprefix src/, path.c parsing.c img.c moves.c main.c)
OBJ = $(addprefix obj/, path.o parsing.o img.o moves.o main.o)
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
	$(CC) $(FLAGS) $(MLX_FLAGS) -o $@ $^

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c -o $@ $<

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