/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:12 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/27 17:11:22 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include <errno.h>
#include <stdio.h>

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	i = 0;
	while (data->cpy && data->cpy[i])
		free(data->cpy[i++]);
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
	fd = open(av[1], O_RDONLY);
	if (!*env || fd == -1)
		return (perror("Error\n"), 1);
	if (ac != 2)
		return (close(fd), ft_printf("Error\nExpected 1 argument"), 1);
	if (init_data(&data, fd))
		return (close(fd), ft_printf("Error\nMemory allocation error"), 1);
	if (!check_map(&data) || !valid_path(&data))
		return (close(fd), ft_free(&data), ft_printf("Error\nInvalid Map"), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_free(&data), 1);
	data.win = mlx_new_window(data.mlx, data.col * 64, \
	data.rows * 64, "so_long");
	if (!data.win || init_sprites(&data))
		return (close(fd), ft_free(&data), 1);
	gen_map(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);
	return (close(fd), ft_free(&data), 0);
}
