/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:59:21 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/28 18:45:46 by tedelin          ###   ########.fr       */
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

void	struc_init(t_data *data)
{
	data->rows = 0;
	data->col = 0;
	data->e = 0;
	data->p = 0;
	data->c = 0;
	data->error = 0;
	data->map = NULL;
	data->cpy = NULL;
	data->pos_px = 0;
	data->pos_py = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->img_e = NULL;
	data->img_p = NULL;
	data->img_c = NULL;
	data->img_w = NULL;
	data->img_f = NULL;
}

char	*ft_error(t_data *data, char *av)
{
	char	*error;
	int		valid;
	int		fd;

	error = NULL;
	if (ft_strlen(ft_strnstr(av, ".ber", ft_strlen(av))) != 4)
		return ("Error\nInvalid file extension : expected .ber file");
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return ("Error\nNo such file or directory");
	else if (init_data(data, fd))
		return (close(fd), "Error\nInvalid map : empty line in file");
	valid = check_map(data);
	if (!valid && data->c == 0)
		return (close(fd), "Error\nNo collectibles");
	else if (!valid && (data->e == 0 || data->e > 1))
		return (close(fd), "Error\nIncorrect number of exit expected : 1");
	else if (!valid && (data->p == 0 || data->p > 1))
		return (close(fd), "Error\nIncorrect number of player expected : 1");
	else if (!valid)
		return (close(fd), "Error\nInvalid map");
	if (!valid_path(data))
		return (close(fd), "Error\nNo valid acess path");
	return (close(fd), error);
}