/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:51:40 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/18 16:08:28 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data
{
	int		rows;
	int		col;
	int		e;
	int		p;
	int		c;
	int		error;
	char	**map;
}		t_data;

int		l_len(char *s);
void	init_data(t_data *data, int fd);
void	check_line(t_data *data, int j);
int		check_map(t_data *data);
void	check_first_last(char *s, t_data *data);

#endif
