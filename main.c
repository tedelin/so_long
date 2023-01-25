/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:12 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/25 19:57:30 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"

void	free_final(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	if (data->img_e)
		mlx_destroy_image(data->mlx_ptr, data->img_e);
	if (data->img_p)
		mlx_destroy_image(data->mlx_ptr, data->img_p);
	if (data->img_c)
		mlx_destroy_image(data->mlx_ptr, data->img_c);
	if (data->img_w)
		mlx_destroy_image(data->mlx_ptr, data->img_w);
	if (data->img_f)
		mlx_destroy_image(data->mlx_ptr, data->img_f);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->map);
	free(data->mlx_ptr);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		fd;

	if (!*env || ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || init_data(&data, fd))
		return (1);
	close(fd);
	if (!check_map(&data))
	 	return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.col * 64, data.rows * 64, "so_long");
	if (!data.win_ptr)
		return (free(data.win_ptr), 1);
	if (init_sprites(&data))
		return (free_final(&data), 1);
	gen_map(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, mlx_loop_end, data.mlx_ptr);
	mlx_loop(data.mlx_ptr);
	free_final(&data);
}
