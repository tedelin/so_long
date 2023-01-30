/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:57:12 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/30 19:35:26 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "mlx.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*error;

	ft_memset(&data, 0, sizeof(t_data));
	error = ft_error(&data, ac, av[1], env);
	if (error)
		return (ft_free(&data), ft_printf("%s", error), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_free(&data), ft_printf("Error\nMlx init failed"), 1);
	data.win = mlx_new_window(data.mlx, data.col * 64, \
	data.rows * 64, "so_long");
	if (!data.win)
		return (ft_free(&data), ft_printf("Error\nMlx window failed"), 1);
	if (init_sprites(&data))
		return (ft_free(&data), ft_printf("Error\nFailed to \
		initialized sprites"), 1);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, mlx_loop_end, data.mlx);
	mlx_loop(data.mlx);
	return (ft_free(&data), 0);
}
