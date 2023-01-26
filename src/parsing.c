/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:59:41 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/26 15:28:04 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

int	l_len(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	init_data(t_data *data, int fd)
{
	char	*lines;
	char	*new;

	lines = get_next_line(fd);
	new = get_next_line(fd);
	if ((lines && new) || (lines && !new))
		data->rows++;
	data->col = l_len(lines);
	while (lines && new)
	{
		data->rows++;
		lines = ft_strjoingnl(lines, new);
		new = get_next_line(fd);
	}
	data->map = ft_split(lines, '\n');
	data->cpy = ft_split(lines, '\n');
	if (!data->map || !data->cpy)
		return (free(lines), 1);
	return (free(lines), 0);
}

void	check_first_last(char *s, t_data *data)
{
	while (s && *s)
	{
		if (*s != '1')
			data->error = 1;
		s++;
	}
}

int	valid_elt(char c)
{
	if (c == 'E' || c == 'P' || c == '1' || c == '0' || c == 'C')
		return (1);
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
