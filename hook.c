/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:20:09 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/24 17:05:20 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"

int	key_hook(int key, t_data *data)
{
	static int	nb = 0;

	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		nb++;
		ft_printf("MOVES : %d\n", nb);
	}
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}