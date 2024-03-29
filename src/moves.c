/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:56:21 by tedelin           #+#    #+#             */
/*   Updated: 2023/02/01 15:06:17 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include "mlx.h"
#include "libft.h"

int	move(t_data *data, int x, int y)
{
	if (x > data->rows - 1 || y > data->col - 1 || y < 0 || x < 0)
	{
		return (0);
	}
	if (data->map[x][y] == 'E' && data->c == 0)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	if (data->map[x][y] == 'C')
	{
		data->c--;
	}
	if (data->map[x][y] == 'C' || data->map[x][y] == '0')
	{
		data->map[data->pos_px][data->pos_py] = '0';
		data->map[x][y] = 'P';
		data->pos_px = x;
		data->pos_py = y;
		gen_map(data);
		return (1);
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	char		*number;

	if ((key == XK_w && move(data, data->pos_px - 1, data->pos_py))
		|| (key == XK_a && move(data, data->pos_px, data->pos_py - 1))
		|| (key == XK_s && move(data, data->pos_px + 1, data->pos_py))
		|| (key == XK_d && move(data, data->pos_px, data->pos_py + 1)))
	{
		data->moves++;
		ft_printf("MOVES : %d\n", data->moves);
		number = ft_itoa(data->moves);
		if (!number)
			return (1);
		mlx_string_put(data->mlx, data->win, 25, 35, 0xFFFFFF, number);
		free(number);
	}
	if (key == XK_Escape)
	{
		mlx_loop_end(data->mlx);
	}
	return (0);
}

int	player_pos(t_data *data, char pos)
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
			{
				if (pos == 'x')
					return (x);
				else if (pos == 'y')
					return (y);
			}
		}
	}
	return (-1);
}
