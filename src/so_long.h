/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:51:40 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/25 20:44:23 by tedelin          ###   ########.fr       */
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
	char	**cpy;
	int		pos_px;
	int		pos_py;
	void	*mlx;
	void	*win;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_w;
	void	*img_f;
}		t_data;

// Parsing
int		l_len(char *s);
int		init_data(t_data *data, int fd);
void	check_first_last(char *s, t_data *data);
int		valid_elt(char c);
int		check_map(t_data *data);

// Valid Path
int		isvalidmove(t_data *data, int x, int y);
void	ft_dfs(t_data *data, int x, int y);
int		valid_path(t_data *data);

// Moves handling
int		move(t_data *data, int x, int y);
int		key_hook(int key, t_data *data);
int		pos_x(t_data *data);
int		pos_y(t_data *data);

// Image handling
int		init_sprites(t_data *data);
void	ft_put_sprites(t_data *data, char c, int x, int y);
void	gen_map(t_data *data);

#endif
