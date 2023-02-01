/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedelin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:51:40 by tedelin           #+#    #+#             */
/*   Updated: 2023/02/01 14:53:42 by tedelin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data
{
	int		rows;
	int		col;
	int		pos_px;
	int		pos_py;
	int		e;
	int		p;
	int		c;
	int		error;
	int		moves;
	char	**map;
	char	**cpy;
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
int		init_map(t_data *data, int fd);
void	check_first_last(char *s, t_data *data);
int		valid_elt(char c);
int		check_map(t_data *data);

// Valid Path
int		is_valid_move(t_data *data, int x, int y);
void	ft_dfs(t_data *data, int x, int y);
void	valid_path(t_data *data);

// Moves handling
int		move(t_data *data, int x, int y);
int		key_hook(int key, t_data *data);
int		player_pos(t_data *data, char pos);

// Image handling
int		init_sprites(t_data *data);
void	ft_put_sprites(t_data *data, char c, int x, int y);
void	gen_map(t_data *data);

// Utils
int		ft_free(t_data *data);
void	struc_init(t_data *data);
char	*ft_error(t_data *data, int ac, char *av, char **env);

#endif
