/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:51:40 by tedelin           #+#    #+#             */
/*   Updated: 2023/01/25 16:55:43 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// typedef struct s_img
// {
// 	void	*mlx_img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }		t_img;

typedef struct s_data
{
	int		rows;
	int		col;
	int		e;
	int		p;
	int		c;
	int		error;
	char	**map;
	int		pos_px;
	int		pos_py;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_w;
	void	*img_f;
}		t_data;

int		l_len(char *s);
int		init_data(t_data *data, int fd);
void	check_line(t_data *data, int j);
int		check_map(t_data *data);
void	check_first_last(char *s, t_data *data);
int		valid_path(t_data *data);
int		isvalidmove(t_data *data, int x, int y);
void	ft_dfs(t_data *data, int x, int y);
int		key_hook(int key, t_data *data);
int		pos_x(t_data *data);
int		move(t_data *data, int x, int y);
int		pos_y(t_data *data);
int		init_sprites(t_data *data);
void	ft_put_sprites(t_data *data, char c, int x, int y);
void	gen_map(t_data *data);

#endif
