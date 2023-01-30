/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:46:30 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/30 19:12:46 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <stdio.h>

int	is_valid_move(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x > data->rows - 1 || y > data->col - 1)
		return (0);
	if (data->cpy[x][y] == 'E')
		data->e--;
	if (data->cpy[x][y] == 'C')
		data->c--;
	return (data->cpy[x][y] == '0' || data->cpy[x][y] == 'C'
		|| data->cpy[x][y] == 'E');
}

void	ft_dfs(t_data *data, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	i;

	dx[0] = -1;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 1;
	dy[2] = 0;
	dy[3] = -1;
	if (data->cpy[x][y] == 'E')
	{
		data->cpy[x][y] = '1';
		return ;
	}
	data->cpy[x][y] = '#';
	i = -1;
	while (++i < 4)
	{
		if (is_valid_move(data, x + dx[i], y + dy[i]))
			ft_dfs(data, x + dx[i], y + dy[i]);
	}
}

void	valid_path(t_data *data)
{
	t_data	cpy;
	int		x;
	int		y;

	x = -1;
	ft_memcpy(&cpy, data, sizeof(t_data));
	while (++x < cpy.rows)
	{
		y = -1;
		while (++y < cpy.col)
		{
			if (cpy.map[x][y] == 'P')
			{
				ft_dfs(&cpy, x, y);
				break ;
			}
		}
	}
	if (cpy.c != 0 || cpy.e != 0)
	{
		ft_printf("Error\nNo valid access path");
		exit(ft_free(data));
	}
}
