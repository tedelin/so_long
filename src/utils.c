/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:59:21 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/30 19:34:49 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "libft.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

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

char	*ft_error(t_data *data, int ac, char *av, char **env)
{
	int		fd;

	if (ac != 2)
		return ("Error\nExpected 1 argument");
	if (!*env)
		return ("Error\nEnv invalid");
	if (ft_strlen(ft_strnstr(av, ".ber", ft_strlen(av))) != 4)
		return ("Error\nInvalid file extension : expected .ber file");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n"), strerror(errno));
	init_data(data, fd);
	close(fd);
	if (!check_map(data))
	{
		if (data->c == 0)
			return ("Error\nNo collectibles");
		if (data->e == 0 || data->e > 1)
			return ("Error\nIncorrect number of exit expected : 1");
		if (data->p == 0 || data->p > 1)
			return ("Error\nIncorrect number of player expected : 1");
		return ("Error\nInvalid map");
	}
	valid_path(data);
	return (NULL);
}
