/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:12 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/24 18:15:12 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"

void free_map(t_data *data)
{
	int	i;
	
	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_data data;
		int	fd;
		
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		if (init_data(&data, fd))
			return (1);
		if (check_map(&data) && valid_path(&data))
		{
			data.mlx_ptr = mlx_init();
			if (!data.mlx_ptr)
				return (1);
			data.win_ptr = mlx_new_window(data.mlx_ptr, data.rows * 64, data.col * 64, "so_long");
			if (!data.win_ptr)
				return (free(data.win_ptr), 1);
			mlx_loop_hook(data.mlx_ptr, &key_hook, &data);
			mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &key_hook, &data);
			mlx_loop(data.mlx_ptr);
			mlx_destroy_display(data.mlx_ptr);
			free(data.mlx_ptr);
		}
		free_map(&data);
	}
}
