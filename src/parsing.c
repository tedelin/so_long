/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:59:41 by tedelin           #+#    #+#             */
/*   Updated: 2023/02/01 15:10:51 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

int	init_map(t_data *data, int fd)
{
	char	*lines;
	char	*new;
	int		i;

	lines = NULL;
	new = get_next_line(fd);
	i = 0;
	data->col = l_len(new);
	while (new)
	{
		data->rows++;
		lines = ft_strjoingnl(lines, new);
		new = get_next_line(fd);
	}
	close(fd);
	data->map = ft_split(lines, '\n');
	data->cpy = ft_split(lines, '\n');
	free(lines);
	while (data->map && data->map[i])
		i++;
	if (!data->cpy || !data->map)
		return (ft_printf("Error\nAllocation  failed"), ft_free(data), 1);
	if (i != data->rows)
		return (ft_printf("Error\nEmpty line in file"), ft_free(data), 1);
	return (0);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map[++j] != NULL)
	{
		if (j == 0 || j == data->rows - 1)
			check_first_last(data->map[j], data);
		i = -1;
		while (data->map[j][++i] && data->map[j][i] != '\n')
		{
			if (data->map[j][i] == 'E')
				data->e++;
			else if (data->map[j][i] == 'P')
				data->p++;
			else if (data->map[j][i] == 'C')
				data->c++;
			else if (data->map[j][0] != '1' || l_len(data->map[j]) != data->col
				|| data->map[j][l_len(data->map[j]) - 1] != '1'
				|| valid_elt(data->map[j][i]) == 0)
				data->error = 1;
		}
	}
	return (data->e == 1 && data->p == 1 && data->error == 0 && data->c >= 1);
}
