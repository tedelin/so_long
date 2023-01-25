/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:46:30 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/25 20:49:00 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	isvalidmove(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x > data->rows - 1 || y > data->col - 1)
		return (0);
	if (data->cpy[x][y] == 'E')
		data->e--;
	if (data->cpy[x][y] == 'C')
		data->c--;
	return (data->cpy[x][y] =! '1');
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
	ft_memcpy(&cpy, data, sizeof(t_data));
	while (++i < cpy.rows)
	{
		j = -1;
		while (++j < cpy.col)
		{
			if (cpy.cpy[i][j] == 'P')
			{
				x = i;
				y = j;
				break ;
			}
		}
	}
	return (ft_dfs(&cpy, x, y), cpy.c == 0 && cpy.e == 0);
}
