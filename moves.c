/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:56:21 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/25 18:54:12 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"

int	move(t_data *data, int x, int y)
{
	if (x > data->rows - 1 || y > data->col - 1 || y < 0 || x < 0)
		return (0);
	if (data->map[x][y] == 'E' && data->c == 0)
	{
		mlx_loop_end(data->mlx_ptr);
		return (1);
	}
	if (data->map[x][y] == 'C' || data->map[x][y] == '0')
	{
		if (data->map[x][y] == 'C')
			data->c--;
		data->map[data->pos_px][data->pos_py] = '0';
		data->map[x][y] = 'P';
		gen_map(data);
		return (1);
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	static int	nb = 0;

	data->pos_px = pos_x(data);
	data->pos_py = pos_y(data);
	if ((key == XK_w && move(data, data->pos_px - 1, data->pos_py))
		|| (key == XK_a && move(data, data->pos_px, data->pos_py - 1))
		|| (key == XK_s && move(data, data->pos_px + 1, data->pos_py))
		|| (key == XK_d && move(data, data->pos_px, data->pos_py + 1)))
	{
		nb++;
		ft_printf("MOVES : %d\n", nb);
	}
	if (key == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	pos_x(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->rows)
	{
		y = -1;
		while (++y < data->col)
		{
			if (data->map[x][y] == 'P')
				return (x);
		}
	}
	return (-1);
}

int	pos_y(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->rows)
	{
		y = -1;
		while (++y < data->col)
		{
			if (data->map[x][y] == 'P')
				return (y);
		}
	}
	return (-1);
}
