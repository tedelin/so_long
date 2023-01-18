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

int	moves(t_data *data, int i, int j)
{
	int	nb;

	nb = 0;
	if (data->map[j][i] == 'E')
	{
		data->map[j][i] = 'X';
		data->e--;
		nb++;
	}
	if (data->map[j][i] == 'C')
	{
		data->map[j][i] = 'X';
		data->c--;
		nb++;
	}
	if (data->map[i][j] == '0')
		data->map[j][i] = 'X';
	return (nb);
}

int	valid_path(t_data *data)
{
	t_data cpy;

	cpy = *data;
	return (cpy.e == 0 && cpy.c == 0);
}
