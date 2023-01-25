/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:27:52 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/25 20:20:37 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"

int	init_sprites(t_data *data)
{
	int	r;

	data->img_p = mlx_xpm_file_to_image(data->mlx_ptr, "assets/p.xpm", &r, &r);
	data->img_c = mlx_xpm_file_to_image(data->mlx_ptr, "assets/c.xpm", &r, &r);
	data->img_w = mlx_xpm_file_to_image(data->mlx_ptr, "assets/w.xpm", &r, &r);
	data->img_f = mlx_xpm_file_to_image(data->mlx_ptr, "assets/f.xpm", &r, &r);
	data->img_e = mlx_xpm_file_to_image(data->mlx_ptr, "assets/e.xpm", &r, &r);
	if (!data->img_p || !data->img_c || !data->img_w || !data->img_f || !data->img_e)
		return (1);
	return (0);
}

void	ft_put_sprites(t_data *data, char c, int x, int y)
{
	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p, y, x);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_c, y, x);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_w, y, x);
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_f, y, x);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_e, y, x);
}

void	gen_map(t_data *data)
{
	int	x;
	int	y;
	int	img_x;
	int	img_y;

	x = -1;
	img_x = 0;
	while (++x < data->rows)
	{
		y = -1;
		img_y = 0;
		while (++y < data->col)
		{
			ft_put_sprites(data, data->map[x][y], img_x, img_y);
			img_y += 64;
		}
		img_x += 64;
	}
}
