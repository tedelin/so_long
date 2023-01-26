/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:12 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/26 18:49:43 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"

int	free_final(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		free(data->cpy[i++]);
	}
	if (data->img_e)
		mlx_destroy_image(data->mlx, data->img_e);
	if (data->img_p)
		mlx_destroy_image(data->mlx, data->img_p);
	if (data->img_c)
		mlx_destroy_image(data->mlx, data->img_c);
	if (data->img_w)
		mlx_destroy_image(data->mlx, data->img_w);
	if (data->img_f)
		mlx_destroy_image(data->mlx, data->img_f);
	if (data->win)
		mlx_clear_window(data->mlx, data->win);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	return (free(data->map), free(data->cpy), free(data->mlx), 0);
}

void	struc_init(t_data *data)
{
	data->rows = 0;
	data->col = 0;
	data->e = 0;
	data->p = 0;
	data->c = 0;
	data->error = 0;
	data->map = NULL;
	data->cpy = NULL;
	data->pos_px = 0;
	data->pos_py = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->img_e = NULL;
	data->img_p = NULL;
	data->img_c = NULL;
	data->img_w = NULL;
	data->img_f = NULL;
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		fd;

	struc_init(&data);
	if (!env || ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || init_data(&data, fd))
		return (1);
	close(fd);
	if (!check_map(&data) || !valid_path(&data))
		return (free_final(&data), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_final(&data), 1);
	data.win = mlx_new_window(data.mlx, data.col * 64, \
	data.rows * 64, "so_long");
	if (!data.win || init_sprites(&data))
		return (free_final(&data), 1);
	gen_map(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);
	free_final(&data);
}
