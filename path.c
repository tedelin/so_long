/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:46:30 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/18 17:12:56 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <stdio.h>

int	isvalidmove(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x > data->rows - 1 || y > data->col - 1)
		return (0);
	if (data->map[x][y] == 'E')
		data->e--;
	if (data->map[x][y] == 'C')
		data->c--;
	return (data->map[x][y] == '0' || data->map[x][y] == 'C' || data->map[x][y] == 'E');
}

void	ft_dfs(t_data *data, int x, int y)
{
	int	dx[4] = {-1, 0, 1, 0};
	int	dy[4] = {0, 1, 0, -1};
	int	i;

	data->map[x][y] = '#';
	i = -1;
	while (++i < 4)
	{
		if (isvalidmove(data, x + dx[i], y + dy[i]))
			ft_dfs(data, x + dx[i], y + dy[i]);
	}
}

int	valid_path(t_data *data)
{
	t_data	cpy;
	int		x;
	int		y;
	int		i;
	int		j;

	x = -1;
	y = -1;
	i = -1;
	cpy = *data;
	while (++i < cpy.rows)
	{
		j = -1;
		while (++j < cpy.col)
		{
			if (cpy.map[i][j] == 'P')
			{
				x = i;
				y = j;
				break ;
			}
		}
	}
	return (ft_dfs(&cpy, x, y), cpy.c == 0 && cpy.e == 0);
	/* ft_dfs(&cpy, x, y); */
	/* int k = 0; */
	/* while (k < cpy.rows) */
	/* 	printf("%s\n", cpy.map[k++]); */
	/* return (1); */
}
