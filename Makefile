# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:52:51 by tedelin           #+#    #+#              #
#    Updated: 2023/01/18 17:15:50 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = parsing.c main_parsing.c
OBJS = $(SRCS:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lX11 -lXext
MLX_PATH = minilibx-linux
LIBFT_LIB = libft/libft.a
LIBFT_PATH = libft

all: $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -o $@ $^

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
